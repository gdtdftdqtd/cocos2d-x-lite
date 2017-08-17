#include "AppDelegate.h"

#include "platform/CCGLView.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "platform/ios/CCGLViewImpl-ios.h"
#endif // CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/CCGLViewImpl-android.h"
#endif // CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "platform/desktop/CCGLViewImpl-desktop.h"
#endif // CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
#include "platform/desktop/CCGLViewImpl-desktop.h"
#endif // CC_TARGET_PLATFORM == CC_PLATFORM_MAC

#include "base/CCDirector.h"
#include "base/CCEventDispatcher.h"

#include "js_module_register.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS) && PACKAGE_AS
#include "SDKManager.h"
#include "jsb_anysdk_protocols_auto.hpp"
#include "manualanysdkbindings.hpp"
using namespace anysdk::framework;
#endif

//add RVO
#include "jsb_RVO_auto.hpp"

#include "LogoScene.hpp"

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(1136, 640);
static cocos2d::Size smallResolutionSize = cocos2d::Size(1136, 640);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
:isRestart(false)
{
}

AppDelegate::~AppDelegate()
{
    ScriptEngineManager::destroyInstance();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS) && PACKAGE_AS
    SDKManager::getInstance()->purge();
#endif
}

void AppDelegate::initGLContextAttrs()
{
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    
    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS && PACKAGE_AS
    SDKManager::getInstance()->loadAllPlugins();
#endif
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("XuYouGame", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("XuYouGame");
#endif
        director->setOpenGLView(glview);
    }
    
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
    
    js_module_register();
    
    if (isRestart) {
        ScriptingCore* sc = ScriptingCore::getInstance();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS) && PACKAGE_AS
        sc->addRegisterCallback(register_all_anysdk_framework);
        sc->addRegisterCallback(register_all_anysdk_manual);
#endif
        //add RVO
        sc->addRegisterCallback(register_all_RVO);
        
        sc->start();
        sc->runScript("script/jsb_boot.js");
#if defined(COCOS2D_DEBUG) && (COCOS2D_DEBUG > 0)
        sc->enableDebugger();
#endif
        ScriptEngineManager::getInstance()->setScriptEngine(sc);
        ScriptingCore::getInstance()->runScript("main.js");
        
        return true;
    }
    
    // create a scene. it's an autorelease object
    auto scene = LogoScene::createScene();
    isRestart = true;
    // run
    director->runWithScene(scene);
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    auto director = Director::getInstance();
    director->stopAnimation();
    director->getEventDispatcher()->dispatchCustomEvent("game_on_hide");
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    auto director = Director::getInstance();
    director->startAnimation();
    director->getEventDispatcher()->dispatchCustomEvent("game_on_show");
}
