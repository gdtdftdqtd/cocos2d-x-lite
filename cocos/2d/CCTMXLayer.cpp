/****************************************************************************
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2013-2014 Chukong Technologies Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "2d/CCTMXLayer.h"
#include "2d/CCTMXTiledMap.h"
#include "2d/CCSprite.h"
#include "base/CCDirector.h"
#include "base/ccUTF8.h"
#include "renderer/CCTextureCache.h"
#include "renderer/CCGLProgram.h"

NS_CC_BEGIN


// TMXLayer - init & alloc & dealloc

TMXLayer * TMXLayer::create(TMXTilesetInfo *tilesetInfo, TMXLayerInfo *layerInfo, TMXMapInfo *mapInfo)
{
    TMXLayer *ret = new (std::nothrow) TMXLayer();
    if (ret->initWithTilesetInfo(tilesetInfo, layerInfo, mapInfo))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}
bool TMXLayer::initWithTilesetInfo(TMXTilesetInfo *tilesetInfo, TMXLayerInfo *layerInfo, TMXMapInfo *mapInfo)
{    
    // FIXME:: is 35% a good estimate ?
    Size size = layerInfo->_layerSize;
    float totalNumberOfTiles = size.width * size.height;
    float capacity = totalNumberOfTiles * 0.35f + 1; // 35 percent is occupied ?

    Texture2D *texture = nullptr;
    if( tilesetInfo )
    {
        texture = Director::getInstance()->getTextureCache()->addImage(tilesetInfo->_sourceImage);
    }

    if (nullptr == texture)
        return false;

    if (SpriteBatchNode::initWithTexture(texture, static_cast<ssize_t>(capacity)))
    {
        // layerInfo
        _layerName = layerInfo->_name;
        _layerSize = size;
        _tiles = layerInfo->_tiles;
        _opacity = layerInfo->_opacity;
        setProperties(layerInfo->getProperties());
        _contentScaleFactor = Director::getInstance()->getContentScaleFactor(); 

        // tilesetInfo
        _tileSet = tilesetInfo;
        CC_SAFE_RETAIN(_tileSet);

        // mapInfo
        _mapTileSize = mapInfo->getTileSize();
        _layerOrientation = mapInfo->getOrientation();
        _staggerAxis = mapInfo->getStaggerAxis();
        _staggerIndex = mapInfo->getStaggerIndex();
        _hexSideLength = mapInfo->getHexSideLength();

        // offset (after layer orientation is set);
        Vec2 offset = this->calculateLayerOffset(layerInfo->_offset);
        this->setPosition(CC_POINT_PIXELS_TO_POINTS(offset));

        _atlasIndexArray = ccCArrayNew(totalNumberOfTiles);

        float width = 0;
        float height = 0;
        if (_layerOrientation == TMXOrientationHex) {
            if (_staggerAxis == TMXStaggerAxis_X) {
                height = _mapTileSize.height * (_layerSize.height + 0.5);
                width = (_mapTileSize.width + _hexSideLength) * ((int)(_layerSize.width / 2)) + _mapTileSize.width * ((int)_layerSize.width % 2);
            } else {
                width = _mapTileSize.width * (_layerSize.width + 0.5);
                height = (_mapTileSize.height + _hexSideLength) * ((int)(_layerSize.height / 2)) + _mapTileSize.height * ((int)_layerSize.height % 2);
            }
        }
        else if (mapInfo->getOrientation() == TMXOrientationStaggered)
        {
            if (_staggerAxis == TMXStaggerAxis_X) {
                height = _mapTileSize.height * (_layerSize.height + 0.5);
                width = (_mapTileSize.width / 2) * (_layerSize.width + 1);
            } else {
                width = _mapTileSize.width * (_layerSize.width + 0.5);
                height = (_mapTileSize.height / 2) * (_layerSize.height + 1);
            }
        }
        else {
            width = _layerSize.width * _mapTileSize.width;
            height = _layerSize.height * _mapTileSize.height;
        }
        this->setContentSize(CC_SIZE_PIXELS_TO_POINTS(Size(width, height)));

        _useAutomaticVertexZ = false;
        _vertexZvalue = 0;
        
        return true;
    }
    return false;
}

TMXLayer::TMXLayer()
:_layerName("")
,_opacity(0)
,_vertexZvalue(0)
,_useAutomaticVertexZ(false)
,_reusedTile(nullptr)
,_atlasIndexArray(nullptr)
,_contentScaleFactor(1.0f)
,_layerSize(Size::ZERO)
,_mapTileSize(Size::ZERO)
,_tiles(nullptr)
,_tileSet(nullptr)
,_layerOrientation(TMXOrientationOrtho)
,_staggerAxis(TMXStaggerAxis_Y)
,_staggerIndex(TMXStaggerIndex_Even)
,_hexSideLength(0)
{
    this->_bigMapTiles.clear();
}

TMXLayer::~TMXLayer()
{
    CC_SAFE_RELEASE(_tileSet);
    CC_SAFE_RELEASE(_reusedTile);

    if (_atlasIndexArray)
    {
        ccCArrayFree(_atlasIndexArray);
        _atlasIndexArray = nullptr;
    }

    CC_SAFE_DELETE_ARRAY(_tiles);
    this->_bigMapTiles.clear();
}

void TMXLayer::releaseMap()
{
    if (_tiles)
    {
        delete [] _tiles;
        _tiles = nullptr;
    }

    if (_atlasIndexArray)
    {
        ccCArrayFree(_atlasIndexArray);
        _atlasIndexArray = nullptr;
    }
}

// TMXLayer - setup Tiles
void TMXLayer::setupTiles()
{    
    // Optimization: quick hack that sets the image size on the tileset
    _tileSet->_imageSize = _textureAtlas->getTexture()->getContentSizeInPixels();

    // By default all the tiles are aliased
    // pros:
    //  - easier to render
    // cons:
    //  - difficult to scale / rotate / etc.
    _textureAtlas->getTexture()->setAliasTexParameters();

    //CFByteOrder o = CFByteOrderGetCurrent();

    // Parse cocos2d properties
    this->parseInternalProperties();
    
    if (!getIsBigMap()) {
        for (int y=0; y < _layerSize.height; y++)
        {
            for (int x=0; x < _layerSize.width; x++)
            {
                int pos = static_cast<int>(x + _layerSize.width * y);
                int gid = _tiles[ pos ];
                
                // gid are stored in little endian.
                // if host is big endian, then swap
                //if( o == CFByteOrderBigEndian )
                //    gid = CFSwapInt32( gid );
                /* We support little endian.*/
                
                // FIXME:: gid == 0 --> empty tile
                if (gid != 0)
                {
                    this->appendTileForGID(gid, Vec2(x, y));
                }
            }
        }
    }
}

void TMXLayer::setTileOpacity(unsigned char opacity) {
    _opacity = opacity;
    for (int i = 0; i < _layerSize.width; i++) {
        for (int j = 0; j < _layerSize.height; j++) {
            Sprite* theTile = getTileAt(Vec2(i, j));
            if (theTile) {
                theTile->setOpacity(_opacity);
            }
        }
    }
}

// TMXLayer - Properties
Value TMXLayer::getProperty(const std::string& propertyName) const
{
    if (_properties.find(propertyName) != _properties.end())
        return _properties.at(propertyName);
    
    return Value();
}

void TMXLayer::parseInternalProperties()
{
    // if cc_vertex=automatic, then tiles will be rendered using vertexz

    auto vertexz = getProperty("cc_vertexz");
    if (!vertexz.isNull())
    {
        std::string vertexZStr = vertexz.asString();
        // If "automatic" is on, then parse the "cc_alpha_func" too
        if (vertexZStr == "automatic")
        {
            _useAutomaticVertexZ = true;
            auto alphaFuncVal = getProperty("cc_alpha_func");
            float alphaFuncValue = alphaFuncVal.asFloat();
            setGLProgramState(GLProgramState::getOrCreateWithGLProgramName(GLProgram::SHADER_NAME_POSITION_TEXTURE_ALPHA_TEST));

            GLint alphaValueLocation = glGetUniformLocation(getGLProgram()->getProgram(), GLProgram::UNIFORM_NAME_ALPHA_TEST_VALUE);

            // NOTE: alpha test shader is hard-coded to use the equivalent of a glAlphaFunc(GL_GREATER) comparison
            
            // use shader program to set uniform
            getGLProgram()->use();
            getGLProgram()->setUniformLocationWith1f(alphaValueLocation, alphaFuncValue);
            CHECK_GL_ERROR_DEBUG();
        }
        else
        {
            _vertexZvalue = vertexz.asInt();
        }
    }
}

void TMXLayer::setupTileSprite(Sprite* sprite, const Vec2& pos, int gid)
{
    sprite->setPosition(getPositionAt(pos));
    sprite->setPositionZ((float)getVertexZForPos(pos));
    sprite->setAnchorPoint(Vec2::ZERO);
    sprite->setOpacity(_opacity);

    //issue 1264, flip can be undone as well
    sprite->setFlippedX(false);
    sprite->setFlippedY(false);
    sprite->setRotation(0.0f);
    sprite->setAnchorPoint(Vec2(0,0));

    // Rotation in tiled is achieved using 3 flipped states, flipping across the horizontal, vertical, and diagonal axes of the tiles.
    if (gid & kTMXTileDiagonalFlag)
    {
        // put the anchor in the middle for ease of rotation.
        sprite->setAnchorPoint(Vec2(0.5f,0.5f));
        sprite->setPosition(getPositionAt(pos).x + sprite->getContentSize().height/2,
           getPositionAt(pos).y + sprite->getContentSize().width/2 );

        int flag = gid & (kTMXTileHorizontalFlag | kTMXTileVerticalFlag );

        // handle the 4 diagonally flipped states.
        if (flag == kTMXTileHorizontalFlag)
        {
            sprite->setRotation(90.0f);
        }
        else if (flag == kTMXTileVerticalFlag)
        {
            sprite->setRotation(270.0f);
        }
        else if (flag == (kTMXTileVerticalFlag | kTMXTileHorizontalFlag) )
        {
            sprite->setRotation(90.0f);
            sprite->setFlippedX(true);
        }
        else
        {
            sprite->setRotation(270.0f);
            sprite->setFlippedX(true);
        }
    }
    else
    {
        if (gid & kTMXTileHorizontalFlag)
        {
            sprite->setFlippedX(true);
        }

        if (gid & kTMXTileVerticalFlag)
        {
            sprite->setFlippedY(true);
        }
    }
}

Sprite* TMXLayer::reusedTileWithRect(const Rect& rect)
{
    if (! _reusedTile) 
    {
        _reusedTile = Sprite::createWithTexture(_textureAtlas->getTexture(), rect);
        _reusedTile->setBatchNode(this);
        _reusedTile->retain();
    }
    else
    {
        // FIXME: HACK: Needed because if "batch node" is nil,
        // then the Sprite'squad will be reset
        _reusedTile->setBatchNode(nullptr);
        
        // Re-init the sprite
        _reusedTile->setTextureRect(rect, false, rect.size);
        
        // restore the batch node
        _reusedTile->setBatchNode(this);
    }

    return _reusedTile;
}

// TMXLayer - obtaining tiles/gids
Sprite * TMXLayer::getTileAt(const Vec2& pos)
{
    CCASSERT(pos.x < _layerSize.width && pos.y < _layerSize.height && pos.x >=0 && pos.y >=0, "TMXLayer: invalid position");
    CCASSERT(_tiles && _atlasIndexArray, "TMXLayer: the tiles map has been released");

    Sprite *tile = nullptr;
    int gid = this->getTileGIDAt(pos);

    // if GID == 0, then no tile is present
    if (gid) 
    {
        int z = (int)(pos.x + pos.y * _layerSize.width);
        tile = static_cast<Sprite*>(this->getChildByTag(z));

        // tile not created yet. create it
        if (! tile) 
        {
            Rect rect = _tileSet->getRectForGID(gid);
            rect = CC_RECT_PIXELS_TO_POINTS(rect);

            tile = Sprite::createWithTexture(this->getTexture(), rect);
            tile->setBatchNode(this);
            tile->setPosition(getPositionAt(pos));
            tile->setPositionZ((float)getVertexZForPos(pos));
            tile->setAnchorPoint(Vec2::ZERO);
            tile->setOpacity(_opacity);

            ssize_t indexForZ = atlasIndexForExistantZ(z);
            this->addSpriteWithoutQuad(tile, static_cast<int>(indexForZ), z);
        }
    }
    
    return tile;
}

uint32_t TMXLayer::getTileGIDAt(const Vec2& pos, TMXTileFlags* flags/* = nullptr*/)
{
    CCASSERT(pos.x < _layerSize.width && pos.y < _layerSize.height && pos.x >=0 && pos.y >=0, "TMXLayer: invalid position");
    CCASSERT(_tiles && _atlasIndexArray, "TMXLayer: the tiles map has been released");

    ssize_t idx = static_cast<int>(((int) pos.x + (int) pos.y * _layerSize.width));
    // Bits on the far end of the 32-bit global tile ID are used for tile flags
    uint32_t tile = _tiles[idx];

    // issue1264, flipped tiles can be changed dynamically
    if (flags) 
    {
        *flags = (TMXTileFlags)(tile & kTMXFlipedAll);
    }
    
    return (tile & kTMXFlippedMask);
}

// TMXLayer - adding helper methods
Sprite * TMXLayer::insertTileForGID(uint32_t gid, const Vec2& pos)
{
    if (gid != 0 && (static_cast<int>((gid & kTMXFlippedMask)) - _tileSet->_firstGid) >= 0)
    {
        Rect rect = _tileSet->getRectForGID(gid);
        rect = CC_RECT_PIXELS_TO_POINTS(rect);
        
        intptr_t z = (intptr_t)((int) pos.x + (int) pos.y * _layerSize.width);
        
        Sprite *tile = reusedTileWithRect(rect);
        
        setupTileSprite(tile, pos, gid);
        
        // get atlas index
        ssize_t indexForZ = atlasIndexForNewZ(static_cast<int>(z));
        
        // Optimization: add the quad without adding a child
        this->insertQuadFromSprite(tile, indexForZ);
        
        // insert it into the local atlasindex array
        ccCArrayInsertValueAtIndex(_atlasIndexArray, (void*)z, indexForZ);
        
        // update possible children
        
        for(const auto &child : _children) {
            Sprite* sp = static_cast<Sprite*>(child);
            ssize_t ai = sp->getAtlasIndex();
            if ( ai >= indexForZ )
            {
                sp->setAtlasIndex(ai+1);
            }
        }
        
        _tiles[z] = gid;
        if (getIsBigMap()) {
            _bigMapTiles[z] = gid;
        }
        return tile;
    }
    
    return nullptr;
}

Sprite * TMXLayer::updateTileForGID(uint32_t gid, const Vec2& pos)
{
    Rect rect = _tileSet->getRectForGID(gid);
    rect = Rect(rect.origin.x / _contentScaleFactor, rect.origin.y / _contentScaleFactor, rect.size.width/ _contentScaleFactor, rect.size.height/ _contentScaleFactor);
    int z = (int)((int) pos.x + (int) pos.y * _layerSize.width);

    Sprite *tile = reusedTileWithRect(rect);

    setupTileSprite(tile ,pos ,gid);

    // get atlas index
    ssize_t indexForZ = atlasIndexForExistantZ(z);
    tile->setAtlasIndex(indexForZ);
    tile->setDirty(true);
    tile->updateTransform();
    _tiles[z] = gid;
    if (getIsBigMap()) {
        _bigMapTiles[z] = gid;
    }

    return tile;
}

// used only when parsing the map. useless after the map was parsed
// since lot's of assumptions are no longer true
Sprite * TMXLayer::appendTileForGID(uint32_t gid, const Vec2& pos)
{
    if (gid != 0 && (static_cast<int>((gid & kTMXFlippedMask)) - _tileSet->_firstGid) >= 0)
    {
        Rect rect = _tileSet->getRectForGID(gid);
        rect = CC_RECT_PIXELS_TO_POINTS(rect);
        
        intptr_t z = (intptr_t)(pos.x + pos.y * _layerSize.width);
        
        Sprite *tile = reusedTileWithRect(rect);
        
        setupTileSprite(tile ,pos ,gid);
        
        // optimization:
        // The difference between appendTileForGID and insertTileforGID is that append is faster, since
        // it appends the tile at the end of the texture atlas
        ssize_t indexForZ = _atlasIndexArray->num;
        
        // don't add it using the "standard" way.
        insertQuadFromSprite(tile, indexForZ);
        
        // append should be after addQuadFromSprite since it modifies the quantity values
        ccCArrayInsertValueAtIndex(_atlasIndexArray, (void*)z, indexForZ);
        
        return tile;
    }
    
    return nullptr;
}

// TMXLayer - atlasIndex and Z
static inline int compareInts(const void * a, const void * b)
{
    return ((*(int*)a) - (*(int*)b));
}

ssize_t TMXLayer::atlasIndexForExistantZ(int z)
{
    int key=z;
    int *item = (int*)bsearch((void*)&key, (void*)&_atlasIndexArray->arr[0], _atlasIndexArray->num, sizeof(void*), compareInts);

    CCASSERT(item, "TMX atlas index not found. Shall not happen");

    ssize_t index = ((size_t)item - (size_t)_atlasIndexArray->arr) / sizeof(void*);
    return index;
}

ssize_t TMXLayer::atlasIndexForNewZ(int z)
{
    // FIXME:: This can be improved with a sort of binary search
    ssize_t i=0;
    for (i=0; i< _atlasIndexArray->num ; i++) 
    {
        ssize_t val = (size_t) _atlasIndexArray->arr[i];
        if (z < val)
        {
            break;
        }
    } 
    
    return i;
}

// TMXLayer - adding / remove tiles
void TMXLayer::setTileGID(uint32_t gid, const Vec2& pos)
{
    setTileGID(gid, pos, (TMXTileFlags)0);
}

void TMXLayer::setTileGID(uint32_t gid, const Vec2& pos, TMXTileFlags flags)
{
    CCASSERT(pos.x < _layerSize.width && pos.y < _layerSize.height && pos.x >=0 && pos.y >=0, "TMXLayer: invalid position");
    CCASSERT(_tiles && _atlasIndexArray, "TMXLayer: the tiles map has been released");
    CCASSERT(gid == 0 || (int)gid >= _tileSet->_firstGid, "TMXLayer: invalid gid" );

    TMXTileFlags currentFlags;
    uint32_t currentGID = 0;
    if (!getIsBigMap()) {
        currentGID = getTileGIDAt(pos, &currentFlags);
    }
    else{
        currentGID = getBigMapTileGIDAt(pos, &currentFlags);
    }

    if (currentGID != gid || currentFlags != flags) 
    {
        uint32_t gidAndFlags = gid | flags;

        // setting gid=0 is equal to remove the tile
        if (gid == 0)
        {
            removeTileAt(pos);
        }
        // empty tile. create a new one
        else if (currentGID == 0)
        {
            insertTileForGID(gidAndFlags, pos);
        }
        // modifying an existing tile with a non-empty tile
        else 
        {
            int z = (int) pos.x + (int) pos.y * _layerSize.width;
            Sprite *sprite = static_cast<Sprite*>(getChildByTag(z));
            if (sprite)
            {
                Rect rect = _tileSet->getRectForGID(gid);
                rect = CC_RECT_PIXELS_TO_POINTS(rect);

                sprite->setTextureRect(rect, false, rect.size);
                if (flags) 
                {
                    setupTileSprite(sprite, sprite->getPosition(), gidAndFlags);
                }
                _tiles[z] = gidAndFlags;
                if (getIsBigMap()) {
                    _bigMapTiles[z] = gidAndFlags;
                }
            } 
            else 
            {
                updateTileForGID(gidAndFlags, pos);
            }
        }
    }
}

void TMXLayer::addChild(Node * child, int zOrder, int tag)
{
    CC_UNUSED_PARAM(child);
    CC_UNUSED_PARAM(zOrder);
    CC_UNUSED_PARAM(tag);
    CCASSERT(0, "addChild: is not supported on TMXLayer. Instead use setTileGID:at:/tileAt:");
}

void TMXLayer::removeChild(Node* node, bool cleanup)
{
    Sprite *sprite = (Sprite*)node;
    // allows removing nil objects
    if (! sprite)
    {
        return;
    }

    CCASSERT(_children.contains(sprite), "Tile does not belong to TMXLayer");

    ssize_t atlasIndex = sprite->getAtlasIndex();
    ssize_t zz = (ssize_t)_atlasIndexArray->arr[atlasIndex];
    _tiles[zz] = 0;
    if (getIsBigMap()) {
        std::map<intptr_t/*index*/, uint32_t/*gid*/>::iterator it = _bigMapTiles.find(zz);
        if (it != _bigMapTiles.end()) {
            _bigMapTiles.erase(it);
        }
    }
    ccCArrayRemoveValueAtIndex(_atlasIndexArray, atlasIndex);
    SpriteBatchNode::removeChild(sprite, cleanup);
}

void TMXLayer::removeTileAt(const Vec2& pos)
{
    CCASSERT(pos.x < _layerSize.width && pos.y < _layerSize.height && pos.x >=0 && pos.y >=0, "TMXLayer: invalid position");
    CCASSERT(_tiles && _atlasIndexArray, "TMXLayer: the tiles map has been released");

    int gid = getTileGIDAt(pos);

    if (gid) 
    {
        int z = pos.x + pos.y * _layerSize.width;
        ssize_t atlasIndex = atlasIndexForExistantZ(z);

        // remove tile from GID map
        _tiles[z] = 0;

        // remove tile from atlas position array
        ccCArrayRemoveValueAtIndex(_atlasIndexArray, atlasIndex);

        // remove it from sprites and/or texture atlas
        Sprite *sprite = (Sprite*)getChildByTag(z);
        if (sprite)
        {
            SpriteBatchNode::removeChild(sprite, true);
        }
        else 
        {
            _textureAtlas->removeQuadAtIndex(atlasIndex);

            // update possible children
            for(const auto &obj : _children) {
                Sprite* child = static_cast<Sprite*>(obj);
                ssize_t ai = child->getAtlasIndex();
                if ( ai >= atlasIndex )
                {
                    child->setAtlasIndex(ai-1);
                }
            }
        }
    }
}

//CCTMXLayer - obtaining positions, offset
Vec2 TMXLayer::calculateLayerOffset(const Vec2& pos)
{
    Vec2 ret;
    switch (_layerOrientation)
    {
        case TMXOrientationOrtho:
            ret.set( pos.x * _mapTileSize.width, -pos.y *_mapTileSize.height);
            break;
        case TMXOrientationIso:
            ret.set((_mapTileSize.width /2) * (pos.x - pos.y),
                  (_mapTileSize.height /2 ) * (-pos.x - pos.y));
            break;
        case TMXOrientationHex:
        {
            if(_staggerAxis == TMXStaggerAxis_Y)
            {
                int diffX = (_staggerIndex == TMXStaggerIndex_Even) ? _mapTileSize.width/2 : 0;
                ret.set(pos.x * _mapTileSize.width + diffX, -pos.y * (_mapTileSize.height - (_mapTileSize.width - _hexSideLength) / 2));
            }
            else if(_staggerAxis == TMXStaggerAxis_X)
            {
                int diffY = (_staggerIndex == TMXStaggerIndex_Odd) ? _mapTileSize.height/2 : 0;
                ret.set(pos.x * (_mapTileSize.width - (_mapTileSize.width - _hexSideLength) / 2), -pos.y * _mapTileSize.height + diffY);
            }
            break;
        }
        case TMXOrientationStaggered:
        {
            float diffX = 0;
            if ((int)std::abs(pos.y) % 2 == 1)
            {
                diffX = _mapTileSize.width/2;
            }
            ret.set(pos.x * _mapTileSize.width + diffX,
                         (-pos.y) * _mapTileSize.height/2);
        }
        break;
    }
    return ret;    
}

Vec2 TMXLayer::getPositionAt(const Vec2& pos)
{
    Vec2 ret;
    switch (_layerOrientation)
    {
    case TMXOrientationOrtho:
        ret = getPositionForOrthoAt(pos);
        break;
    case TMXOrientationIso:
        ret = getPositionForIsoAt(pos);
        break;
    case TMXOrientationHex:
        ret = getPositionForHexAt(pos);
        break;
    case TMXOrientationStaggered:
        ret = getPositionForStaggeredAt(pos);
        break;
    }
    ret = CC_POINT_PIXELS_TO_POINTS( ret );
    return ret;
}

Vec2 TMXLayer::getPositionForOrthoAt(const Vec2& pos)
{
    return Vec2(pos.x * _mapTileSize.width,
                            (_layerSize.height - pos.y - 1) * _mapTileSize.height);
}

Vec2 TMXLayer::getPositionForIsoAt(const Vec2& pos)
{
    return Vec2(_mapTileSize.width /2 * (_layerSize.width + pos.x - pos.y - 1),
                             _mapTileSize.height /2 * ((_layerSize.height * 2 - pos.x - pos.y) - 2));
}

Vec2 TMXLayer::getPositionForHexAt(const Vec2& pos)
{
    Vec2 xy;
    Vec2 offset = _tileSet->_tileOffset;

    int odd_even = (_staggerIndex == TMXStaggerIndex_Odd) ? 1 : -1;
    switch (_staggerAxis)
    {
        case TMXStaggerAxis_Y:
        {
            float diffX = 0;
            if ((int)pos.y % 2 == 1)
            {
                diffX = _mapTileSize.width/2 * odd_even;
            }
            xy = Vec2(pos.x * _mapTileSize.width+diffX+offset.x,
                      (_layerSize.height - pos.y - 1) * (_mapTileSize.height-(_mapTileSize.height-_hexSideLength)/2)-offset.y);
            break;
        }
            
        case TMXStaggerAxis_X:
        {
            float diffY = 0;
            if ((int)pos.x % 2 == 1)
            {
                diffY = _mapTileSize.height/2 * -odd_even;
            }
            
            xy = Vec2(pos.x * (_mapTileSize.width-(_mapTileSize.width-_hexSideLength)/2)+offset.x,
                      (_layerSize.height - pos.y - 1) * _mapTileSize.height + diffY-offset.y);
            break;
        }
    }
    return xy;
}

Vec2 TMXLayer::getPositionForStaggeredAt(const Vec2 &pos)
{
    float diffX = 0;
    if ((int)pos.y % 2 == 1)
    {
        diffX = _mapTileSize.width/2;
    }
    return Vec2(pos.x * _mapTileSize.width + diffX,
                (_layerSize.height - pos.y - 1) * _mapTileSize.height/2);
}

int TMXLayer::getVertexZForPos(const Vec2& pos)
{
    int ret = 0;
    int maxVal = 0;
    if (_useAutomaticVertexZ)
    {
        switch (_layerOrientation) 
        {
        case TMXOrientationIso:
            maxVal = static_cast<int>(_layerSize.width + _layerSize.height);
            ret = static_cast<int>(-(maxVal - (pos.x + pos.y)));
            break;
        case TMXOrientationOrtho:
            ret = static_cast<int>(-(_layerSize.height-pos.y));
            break;
        case TMXOrientationStaggered:
            ret = static_cast<int>(-(_layerSize.height-pos.y));
            break;
        case TMXOrientationHex:
            ret = static_cast<int>(-(_layerSize.height-pos.y));
            break;
        default:
            CCASSERT(0, "TMX invalid value");
            break;
        }
    } 
    else
    {
        ret = _vertexZvalue;
    }
    
    return ret;
}

std::string TMXLayer::getDescription() const
{
    return StringUtils::format("<TMXLayer | tag = %d, size = %d,%d>", _tag, (int)_mapTileSize.width, (int)_mapTileSize.height);
}

//add by chl
bool TMXLayer::getIsBigMap()
{
    return (((int)_layerSize.width) >= 128 && ((int)_layerSize.height) >= 128) || ((int)_layerSize.width)*((int)_layerSize.height) >= 128*128 ;
}

uint32_t TMXLayer::getBigMapTileGIDAt(const Vec2& pos, TMXTileFlags* flags/* = nullptr*/)
{
    CCASSERT(pos.x < _layerSize.width && pos.y < _layerSize.height && pos.x >=0 && pos.y >=0, "TMXLayer: invalid position");
    CCASSERT(_tiles && _atlasIndexArray, "TMXLayer: the tiles map has been released");
    
    ssize_t idx = static_cast<int>(((int) pos.x + (int) pos.y * _layerSize.width));
    // Bits on the far end of the 32-bit global tile ID are used for tile flags
    uint32_t tile = 0;
    auto it = _bigMapTiles.find(idx);
    if (it != _bigMapTiles.end()){
        tile = it->second;
    }
    
    // issue1264, flipped tiles can be changed dynamically
    if (flags)
    {
        *flags = (TMXTileFlags)(tile & kTMXFlipedAll);
    }
    
    return (tile & kTMXFlippedMask);
}

void TMXLayer::showTilesBeyond(const Vec2& tileCoordinate, int w, int h)
{
    if (!getIsBigMap()) {
        return;
    }
    if (h == 0) {
        h = w;
    }
    int _minX = tileCoordinate.x - w;
    int _maxX = tileCoordinate.x + w;
    int _minY = tileCoordinate.y - h;
    int _maxY = tileCoordinate.y + h;
    
    _minX = _minX < 0 ? 0 : _minX;
    _maxX = _maxX > _layerSize.width - 1 ? _layerSize.width - 1 : _maxX;
    _minY = _minY < 0 ? 0 : _minY;
    _maxY = _maxY > _layerSize.height - 1 ? _layerSize.height - 1 : _maxY;
    
    int _y;
    int _x;
    int _gid;
    for (_y = _minY; _y <= _maxY; _y++) {
        for (_x = _minX; _x <= _maxX; _x++) {
            _gid = this->getTileGIDAt(Vec2(_x, _y));
            if (0 != _gid) {
                setTileGID(_gid, Vec2(_x, _y));
            }
        }
    }
    this->removeTilesAway(tileCoordinate, w, h);
}

void TMXLayer::removeTilesAway(const Vec2& tileCoordinate, int w, int h)
{
    std::map<long, Vec2> _needRemoveMap;
    for(auto it = _bigMapTiles.begin(); it != _bigMapTiles.end(); ++it)
    {
        intptr_t tileIndex = it->first;
        intptr_t _x = tileIndex % int(_layerSize.width);
        intptr_t _y = (tileIndex - _x) / int(_layerSize.width);
        if (std::abs(_x - tileCoordinate.x) > w || std::abs(_y - tileCoordinate.y) > h) {
            _needRemoveMap[tileIndex] = Vec2(_x, _y);
        }
    }
    for(auto it = _needRemoveMap.begin(); it != _needRemoveMap.end();++it)
    {
        this->removeBigMapTileAt(it->second);
    }
    _needRemoveMap.clear();
}

void TMXLayer::removeBigMapTileAt(const Vec2& pos)
{
    CCASSERT(pos.x < _layerSize.width && pos.y < _layerSize.height && pos.x >=0 && pos.y >=0, "TMXLayer: invalid position");
    CCASSERT(_tiles && _atlasIndexArray, "TMXLayer: the tiles map has been released");
    
    int gid = getTileGIDAt(pos);
    
    if (gid)
    {
        int z = pos.x + pos.y * _layerSize.width;
        
        // remove tile from GID map
        if (getIsBigMap()) {
            std::map<intptr_t/*index*/, uint32_t/*gid*/>::iterator it = _bigMapTiles.find(z);
            if (it != _bigMapTiles.end()) {
                _bigMapTiles.erase(it);
            }
            else{
                return;
            }
        }
        
        ssize_t atlasIndex = atlasIndexForExistantZ(z);
        // remove tile from atlas position array
        ccCArrayRemoveValueAtIndex(_atlasIndexArray, atlasIndex);
        
        // remove it from sprites and/or texture atlas
        Sprite *sprite = (Sprite*)getChildByTag(z);
        if (sprite)
        {
            SpriteBatchNode::removeChild(sprite, true);
        }
        else
        {
            _textureAtlas->removeQuadAtIndex(atlasIndex);
            
            // update possible children
            for(const auto &obj : _children) {
                Sprite* child = static_cast<Sprite*>(obj);
                ssize_t ai = child->getAtlasIndex();
                if ( ai >= atlasIndex )
                {
                    child->setAtlasIndex(ai-1);
                }
            }
        }
    }
}

Vec2 TMXLayer::getTileCoords(const Vec2& position)
{
    switch (_layerOrientation)
    {
    case TMXOrientationIso:
        return getTileCoordsForIso(position);
        break;
    case TMXOrientationOrtho:
        return getTileCoordsForOrtho(position);
        break;
    case TMXOrientationStaggered:
        return getTileCoordsForStaggered(position);
        break;
    case TMXOrientationHex:
        CCASSERT(0, "Not supported ");
//        return getTileCoordsForHex(position);
        break;
    default:
        CCASSERT(0, "Not supported ");
        break;
    }
    return Vec2();
}

Vec2 TMXLayer::getTileCoordsForIso(const Vec2 &position)
{
    Vec2 pos = position;
    const int tileWidth = this->_mapTileSize.width;
    const int tileHeight = this->_mapTileSize.height;
    
    pos.x -= this->_layerSize.height * tileWidth / 2;
    const double tileY = (this->getContentSize().height - pos.y) / tileHeight;
    const double tileX = pos.x / tileWidth;
//    CCLOG("tilecoords %lf, %lf",std::floor(tileY + tileX), std::floor(tileY - tileX));
    return Vec2(std::floor(tileY + tileX), std::floor(tileY - tileX));
}

Vec2 TMXLayer::getTileCoordsForOrtho(const Vec2 &position)
{
    Vec2 pos = position;
    return Vec2(std::floor(pos.x / this->_mapTileSize.width),std::floor((this->getContentSize().height - pos.y) / this->_mapTileSize.height));
}



Vec2 TMXLayer::getTileCoordsForHex(const Vec2 &position)
{
    return Vec2();
}

Vec2 TMXLayer::getTileCoordsForStaggered(const Vec2 &position)
{
    Vec2 pos = position;
    if (this->_staggerAxis == TMXStaggerAxis_X) {
        pos.x -= this->_staggerIndex == TMXStaggerIndex_Even ? this->_mapTileSize.width/2 : 0;
    }
    else{
        pos.y -= this->_staggerIndex == TMXStaggerIndex_Even ? this->_mapTileSize.height/2 : 0;
    }
    // Start with the coordinates of a grid-aligned tile
    Vec2 referencePoint = Vec2((intptr_t)std::floor(pos.x / this->_mapTileSize.width),(intptr_t)std::floor((this->getContentSize().height - pos.y) / this->_mapTileSize.height));

    // Relative x and y position on the base square of the grid-aligned tile
    const Vec2 rel(pos.x - referencePoint.x * this->_mapTileSize.width, (this->getContentSize().height - pos.y) - referencePoint.y * this->_mapTileSize.height);

    // Adjust the reference point to the correct tile coordinates
    auto& staggerAxisIndex = this->_staggerAxis == TMXStaggerAxis_X ? referencePoint.x : referencePoint.y;
    staggerAxisIndex *= 2;
    if (this->_staggerIndex == TMXStaggerIndex_Even){
        ++staggerAxisIndex;
    }

    const double y_pos = rel.x * ((double) this->_mapTileSize.height / this->_mapTileSize.width);

    // Check whether the cursor is in any of the corners (neighboring tiles)
    if (this->_mapTileSize.height/2 - y_pos > rel.y){
        return topLeft(referencePoint.x, referencePoint.y);
    }
    if (-this->_mapTileSize.height/2 + y_pos > rel.y){
        return topRight(referencePoint.x, referencePoint.y);
    }
    if (this->_mapTileSize.height/2 + y_pos < rel.y){
        return bottomLeft(referencePoint.x, referencePoint.y);
    }
    if (this->_mapTileSize.height/2 * 3 - y_pos < rel.y){
        return bottomRight(referencePoint.x, referencePoint.y);
    }

    return referencePoint;
}

Vec2 TMXLayer::topLeft(int x, int y) const
{
    if (this->_staggerAxis == TMXStaggerAxis_Y) {
        if ((y & 1) ^ this->_staggerIndex){
            return Vec2(x, y - 1);
        }
        else{
            return Vec2(x - 1, y - 1);
        }
    } else {
        if ((x & 1) ^ this->_staggerIndex){
            return Vec2(x - 1, y);
        }
        else{
            return Vec2(x - 1, y - 1);
        }
    }
}

Vec2 TMXLayer::topRight(int x, int y) const
{
    if (this->_staggerAxis == TMXStaggerAxis_Y) {
        if ((y & 1) ^ this->_staggerIndex){
            return Vec2(x + 1, y - 1);
        }
        else{
            return Vec2(x, y - 1);
        }
    } else {
        if ((x & 1) ^ this->_staggerIndex){
            return Vec2(x + 1, y);
        }
        else{
            return Vec2(x + 1, y - 1);
        }
    }
}

Vec2 TMXLayer::bottomLeft(int x, int y) const
{
    if (this->_staggerAxis == TMXStaggerAxis_Y) {
        if ((y & 1) ^ this->_staggerIndex){
            return Vec2(x, y + 1);
        }
        else{
            return Vec2(x - 1, y + 1);
        }
    } else {
        if ((x & 1) ^ this->_staggerIndex){
            return Vec2(x - 1, y + 1);
        }
        else{
            return Vec2(x - 1, y);
        }
    }
}

Vec2 TMXLayer::bottomRight(int x, int y) const
{
    if (this->_staggerAxis == TMXStaggerAxis_Y) {
        if ((y & 1) ^ this->_staggerIndex){
            return Vec2(x + 1, y + 1);
        }
        else{
            return Vec2(x, y + 1);
        }
    } else {
        if ((x & 1) ^ this->_staggerIndex){
            return Vec2(x + 1, y + 1);
        }
        else{
            return Vec2(x + 1, y);
        }
    }
}


NS_CC_END
