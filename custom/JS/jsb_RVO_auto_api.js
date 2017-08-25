/**
 * @module RVO
 */
var RVO = RVO || {};

/**
 * @class CocosRVO
 */
RVO.CocosRVO = {

/**
 * @method setAgentVelocity
 * @param {unsigned long} arg0
 * @param {vec2_object} arg1
 */
setAgentVelocity : function (
long, 
vec2 
)
{
},

/**
 * @method setAgentRadius
 * @param {unsigned long} arg0
 * @param {float} arg1
 */
setAgentRadius : function (
long, 
float 
)
{
},

/**
 * @method setAgentPrefVelocity
 * @param {unsigned long} arg0
 * @param {vec2_object} arg1
 */
setAgentPrefVelocity : function (
long, 
vec2 
)
{
},

/**
 * @method setTimeStep
 * @param {float} arg0
 */
setTimeStep : function (
float 
)
{
},

/**
 * @method getNextObstacleVertexNo
 * @param {unsigned long} arg0
 * @return {unsigned long}
 */
getNextObstacleVertexNo : function (
long 
)
{
    return 0;
},

/**
 * @method setAgentDefaults
 * @param {float} arg0
 * @param {unsigned long} arg1
 * @param {float} arg2
 * @param {float} arg3
 * @param {float} arg4
 * @param {float} arg5
 * @param {vec2_object} arg6
 */
setAgentDefaults : function (
float, 
long, 
float, 
float, 
float, 
float, 
vec2 
)
{
},

/**
 * @method updateVisualization
 */
updateVisualization : function (
)
{
},

/**
 * @method getNumObstacleVertices
 * @return {unsigned long}
 */
getNumObstacleVertices : function (
)
{
    return 0;
},

/**
 * @method getAgentTimeHorizon
 * @param {unsigned long} arg0
 * @return {float}
 */
getAgentTimeHorizon : function (
long 
)
{
    return 0;
},

/**
 * @method getTimeStep
 * @return {float}
 */
getTimeStep : function (
)
{
    return 0;
},

/**
 * @method doStep
 */
doStep : function (
)
{
},

/**
 * @method getAgentMaxNeighbors
 * @param {unsigned long} arg0
 * @return {unsigned long}
 */
getAgentMaxNeighbors : function (
long 
)
{
    return 0;
},

/**
 * @method setAgentTimeHorizon
 * @param {unsigned long} arg0
 * @param {float} arg1
 */
setAgentTimeHorizon : function (
long, 
float 
)
{
},

/**
 * @method addObstacle
 * @param {Array} arg0
 * @return {unsigned long}
 */
addObstacle : function (
array 
)
{
    return 0;
},

/**
 * @method getAgentNumAgentNeighbors
 * @param {unsigned long} arg0
 * @return {unsigned long}
 */
getAgentNumAgentNeighbors : function (
long 
)
{
    return 0;
},

/**
 * @method getAgentRadius
 * @param {unsigned long} arg0
 * @return {float}
 */
getAgentRadius : function (
long 
)
{
    return 0;
},

/**
 * @method getAgentVelocity
 * @param {unsigned long} arg0
 * @return {vec2_object}
 */
getAgentVelocity : function (
long 
)
{
    return cc.Vec2;
},

/**
 * @method setAgentsNextPos
 * @param {Array} arg0
 * @return {unsigned long}
 */
setAgentsNextPos : function (
array 
)
{
    return 0;
},

/**
 * @method removeAgent
 * @param {unsigned long} arg0
 * @return {bool}
 */
removeAgent : function (
long 
)
{
    return false;
},

/**
 * @method getAgentNumORCALines
 * @param {unsigned long} arg0
 * @return {unsigned long}
 */
getAgentNumORCALines : function (
long 
)
{
    return 0;
},

/**
 * @method reachedGoal
 * @return {Array}
 */
reachedGoal : function (
)
{
    return new Array();
},

/**
 * @method getAgentNeighborDist
 * @param {unsigned long} arg0
 * @return {float}
 */
getAgentNeighborDist : function (
long 
)
{
    return 0;
},

/**
 * @method setAgentMaxSpeed
 * @param {unsigned long} arg0
 * @param {float} arg1
 */
setAgentMaxSpeed : function (
long, 
float 
)
{
},

/**
 * @method getAgentPrefVelocity
 * @param {unsigned long} arg0
 * @return {vec2_object}
 */
getAgentPrefVelocity : function (
long 
)
{
    return cc.Vec2;
},

/**
 * @method setPreferredVelocities
 */
setPreferredVelocities : function (
)
{
},

/**
 * @method setAgentMaxNeighbors
 * @param {unsigned long} arg0
 * @param {unsigned long} arg1
 */
setAgentMaxNeighbors : function (
long, 
long 
)
{
},

/**
 * @method getNumAgents
 * @return {unsigned long}
 */
getNumAgents : function (
)
{
    return 0;
},

/**
 * @method getAgentMaxSpeed
 * @param {unsigned long} arg0
 * @return {float}
 */
getAgentMaxSpeed : function (
long 
)
{
    return 0;
},

/**
 * @method setAgentTimeHorizonObst
 * @param {unsigned long} arg0
 * @param {float} arg1
 */
setAgentTimeHorizonObst : function (
long, 
float 
)
{
},

/**
 * @method addAgent
* @param {cc.Node|cc.Node} node
* @param {vec2_object|vec2_object} vec2
* @param {float} float
* @param {unsigned long} long
* @param {float} float
* @param {float} float
* @param {float} float
* @param {float} float
* @param {vec2_object} vec2
* @return {unsigned long|unsigned long}
*/
addAgent : function(
node,
vec2,
float,
long,
float,
float,
float,
float,
vec2 
)
{
    return 0;
},

/**
 * @method getAgentObstacleNeighbor
 * @param {unsigned long} arg0
 * @param {unsigned long} arg1
 * @return {unsigned long}
 */
getAgentObstacleNeighbor : function (
long, 
long 
)
{
    return 0;
},

/**
 * @method getGlobalTime
 * @return {float}
 */
getGlobalTime : function (
)
{
    return 0;
},

/**
 * @method getObstacleVertex
 * @param {unsigned long} arg0
 * @return {vec2_object}
 */
getObstacleVertex : function (
long 
)
{
    return cc.Vec2;
},

/**
 * @method getAgentAgentNeighbor
 * @param {unsigned long} arg0
 * @param {unsigned long} arg1
 * @return {unsigned long}
 */
getAgentAgentNeighbor : function (
long, 
long 
)
{
    return 0;
},

/**
 * @method setAgentPosition
 * @param {unsigned long} arg0
 * @param {vec2_object} arg1
 */
setAgentPosition : function (
long, 
vec2 
)
{
},

/**
 * @method getAgentTimeHorizonObst
 * @param {unsigned long} arg0
 * @return {float}
 */
getAgentTimeHorizonObst : function (
long 
)
{
    return 0;
},

/**
 * @method getAgentNumObstacleNeighbors
 * @param {unsigned long} arg0
 * @return {unsigned long}
 */
getAgentNumObstacleNeighbors : function (
long 
)
{
    return 0;
},

/**
 * @method queryVisibility
 * @param {vec2_object} arg0
 * @param {vec2_object} arg1
 * @param {float} arg2
 * @return {bool}
 */
queryVisibility : function (
vec2, 
vec2, 
float 
)
{
    return false;
},

/**
 * @method getAgentPosition
 * @param {unsigned long} arg0
 * @return {vec2_object}
 */
getAgentPosition : function (
long 
)
{
    return cc.Vec2;
},

/**
 * @method processObstacles
 */
processObstacles : function (
)
{
},

/**
 * @method getPrevObstacleVertexNo
 * @param {unsigned long} arg0
 * @return {unsigned long}
 */
getPrevObstacleVertexNo : function (
long 
)
{
    return 0;
},

/**
 * @method release
 */
release : function (
)
{
},

/**
 * @method setAgentNeighborDist
 * @param {unsigned long} arg0
 * @param {float} arg1
 */
setAgentNeighborDist : function (
long, 
float 
)
{
},

/**
 * @method getAgentORCALine
 * @param {unsigned long} arg0
 * @param {unsigned long} arg1
 * @return {Array}
 */
getAgentORCALine : function (
long, 
long 
)
{
    return new Array();
},

/**
 * @method create
* @param {float} float
* @param {float} float
* @param {unsigned long} long
* @param {float} float
* @param {float} float
* @param {float} float
* @param {float} float
* @param {vec2_object} vec2
* @return {CocosRVO|CocosRVO}
*/
create : function(
float,
float,
long,
float,
float,
float,
float,
vec2 
)
{
    return CocosRVO;
},

};
