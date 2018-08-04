/****************************************************************************
 Copyright (c) 2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated engine source code (the "Software"), a limited,
 worldwide, royalty-free, non-assignable, revocable and non-exclusive license
 to use Cocos Creator solely to develop games on your target platforms. You shall
 not use Cocos Creator software for developing other software or tools that's
 used for developing games. You are not granted to publish, distribute,
 sublicense, and/or sell copies of Cocos Creator.

 The software or tools in this License Agreement are licensed, not sold.
 Xiamen Yaji Software Co., Ltd. reserves all rights not expressly granted to you.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include "JniImp.h"
#include <unordered_map>
#include <android/log.h>
#include <android/asset_manager_jni.h>
#include <jni.h>
#include <mutex>
#include "JniHelper.h"
#include "platform/CCApplication.h"
#include "scripting/js-bindings/jswrapper/SeApi.h"
#include "scripting/js-bindings/event/EventDispatcher.h"
#include "platform/android/CCFileUtils-android.h"
#include "base/CCScheduler.h"
#include "base/CCAutoreleasePool.h"
#include "audio/include/AudioEngine.h"
#include "base/CCGLUtils.h"

#define  JNI_IMP_LOG_TAG    "JniImp"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,JNI_IMP_LOG_TAG,__VA_ARGS__)

#define KEYCODE_BACK 0x04
#define KEYCODE_MENU 0x52
#define KEYCODE_DPAD_UP 0x13
#define KEYCODE_DPAD_DOWN 0x14
#define KEYCODE_DPAD_LEFT 0x15
#define KEYCODE_DPAD_RIGHT 0x16
#define KEYCODE_ENTER 0x42
#define KEYCODE_PLAY  0x7e
#define KEYCODE_DPAD_CENTER  0x17

using namespace cocos2d;

extern uint32_t __jsbInvocationCount;


namespace
{	
    bool __isOpenDebugView = false;
    bool __isGLOptModeEnabled = true;
//	std::unordered_map<int, cocos2d::EventKeyboard::KeyCode> g_keyCodeMap =
//	{
//        { KEYCODE_BACK , cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE },
//        { KEYCODE_MENU , cocos2d::EventKeyboard::KeyCode::KEY_MENU },
//        { KEYCODE_DPAD_UP  , cocos2d::EventKeyboard::KeyCode::KEY_DPAD_UP },
//        { KEYCODE_DPAD_DOWN , cocos2d::EventKeyboard::KeyCode::KEY_DPAD_DOWN },
//        { KEYCODE_DPAD_LEFT , cocos2d::EventKeyboard::KeyCode::KEY_DPAD_LEFT },
//        { KEYCODE_DPAD_RIGHT , cocos2d::EventKeyboard::KeyCode::KEY_DPAD_RIGHT },
//        { KEYCODE_ENTER  , cocos2d::EventKeyboard::KeyCode::KEY_ENTER },
//        { KEYCODE_PLAY  , cocos2d::EventKeyboard::KeyCode::KEY_PLAY },
//        { KEYCODE_DPAD_CENTER  , cocos2d::EventKeyboard::KeyCode::KEY_DPAD_CENTER },
//    };

    std::string g_apkPath;
    const std::string Cocos2dxHelperClassName = "org/cocos2dx/lib/Cocos2dxHelper";
    const std::string Cocos2dxRendererClassName = "org/cocos2dx/lib/Cocos2dxRenderer";
    EditTextCallback s_editTextCallback = nullptr;
    void* s_ctx = nullptr;
    int g_deviceSampleRate = 44100;
    int g_deviceAudioBufferSizeInFrames = 192;
    int g_width = 0;
    int g_height = 0;
    bool g_isStarted = false;
    bool g_isGameFinished = false;

    cocos2d::Application* g_app = nullptr;

    bool setCanvasCallback(se::Object* global)
    {
        se::AutoHandleScope scope;
        se::ScriptEngine* se = se::ScriptEngine::getInstance();
        char commandBuf[200] = {0};
        uint8_t devicePixelRatio = Application::getInstance()->getDevicePixelRatio();
        sprintf(commandBuf, "window.innerWidth = %d; window.innerHeight = %d;",
                g_width / devicePixelRatio,
                g_height / devicePixelRatio);
        se->evalString(commandBuf);
        glViewport(0, 0, g_width / devicePixelRatio, g_height / devicePixelRatio);
        glDepthMask(GL_TRUE);
        
        return true;
    }
}

void cocos_jni_env_init (JNIEnv* env);

Application* cocos_android_app_init(JNIEnv* env, int width, int height);

extern "C"
{
    JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
    {
        JniHelper::setJavaVM(vm);
        cocos_jni_env_init(JniHelper::getEnv());
        return JNI_VERSION_1_4;
    }

    /*****************************************************
     * Cocos2dxActivity native functions implementation.
     *****************************************************/

    JNIEXPORT jintArray JNICALL Java_org_cocos2dx_lib_Cocos2dxActivity_getGLContextAttrs(JNIEnv*  env, jobject thiz)
    {
        //TODO
        int tmp[7] = {8, 8, 8,
                      8, 0, 0, 0};
        jintArray glContextAttrsJava = env->NewIntArray(7);
        env->SetIntArrayRegion(glContextAttrsJava, 0, 7, tmp);

        return glContextAttrsJava;
    }

	/*****************************************************
	 * Cocos2dxRenderer native functions implementation.
	 *****************************************************/

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeInit(JNIEnv*  env, jobject thiz, jint w, jint h, jstring jDefaultResourcePath)
    {
        g_width = w;
        g_height = h;
        
        g_app = cocos_android_app_init(env, w, h);

        g_isGameFinished = false;
        ccInvalidateStateCache();
        std::string defaultResourcePath = JniHelper::jstring2string(jDefaultResourcePath);
        LOGD("CocosRenderer.nativeInit: %d, %d, %s", w, h, defaultResourcePath.c_str());
        

        if (!defaultResourcePath.empty())
            FileUtils::getInstance()->setDefaultResourceRootPath(defaultResourcePath);

        se::ScriptEngine* se = se::ScriptEngine::getInstance();
        se->addRegisterCallback(setCanvasCallback);

        EventDispatcher::init();

        g_app->start();
        g_isStarted = true;
    }

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeFinish(JNIEnv*  env, jobject thiz)
    {
        g_isGameFinished = true;
        LOGD("CocosRenderer.nativeFinish");
        g_app->getScheduler()->removeAllFunctionsToBePerformedInCocosThread();
        EventDispatcher::destroy();
        se::ScriptEngine::getInstance()->cleanup();
        cocos2d::experimental::AudioEngine::end();
        JniHelper::callObjectVoidMethod(thiz, Cocos2dxRendererClassName, "onGameFinished");
    }

	JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeRender(JNIEnv* env)
	{
        if (g_isGameFinished)
            return;

        if (!g_isStarted)
        {
            auto scheduler = Application::getInstance()->getScheduler();
            scheduler->removeAllFunctionsToBePerformedInCocosThread();
            scheduler->unscheduleAll();

            se::ScriptEngine::getInstance()->cleanup();
            cocos2d::PoolManager::getInstance()->getCurrentPool()->clear();

            //TODO: Wait HttpClient, WebSocket, Audio thread to exit

            ccInvalidateStateCache();
          
            se::ScriptEngine* se = se::ScriptEngine::getInstance();
            se->addRegisterCallback(setCanvasCallback);

            EventDispatcher::init();

            if(!g_app->applicationDidFinishLaunching())
            {
                g_isGameFinished = true;
                return;
            }

            g_isStarted = true;
        }

        static std::chrono::steady_clock::time_point prevTime;
        static std::chrono::steady_clock::time_point now;
        static float dt = 0.f;
        static float dtSum = 0.f;
        static uint32_t jsbInvocationTotalCount = 0;
        static uint32_t jsbInvocationTotalFrames = 0;
        bool downsampleEnabled = g_app->isDownsampleEnabled();
        
        if (downsampleEnabled)
            g_app->getRenderTexture()->prepare();

        g_app->getScheduler()->update(dt);
        EventDispatcher::dispatchTickEvent(dt);
       
        if (downsampleEnabled)
            g_app->getRenderTexture()->draw();

        PoolManager::getInstance()->getCurrentPool()->clear();

        now = std::chrono::steady_clock::now();
        dt = std::chrono::duration_cast<std::chrono::microseconds>(now - prevTime).count() / 1000000.f;

        prevTime = std::chrono::steady_clock::now();

        if (__isOpenDebugView)
        {
            dtSum += dt;
            ++jsbInvocationTotalFrames;
            jsbInvocationTotalCount += __jsbInvocationCount;

            if (dtSum > 1.0f)
            {
                dtSum = 0.0f;
                setJSBInvocationCountJNI(jsbInvocationTotalCount / jsbInvocationTotalFrames);
                jsbInvocationTotalCount = 0;
                jsbInvocationTotalFrames = 0;
            }
        }
        __jsbInvocationCount = 0;
    }

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeOnPause()
    {
        if (g_isGameFinished) {
            return;
        }
        if (g_app)
            g_app->applicationDidEnterBackground();
    }

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeOnResume()
    {
        if (g_isGameFinished) {
            return;
        }
        if (g_app)
            g_app->applicationWillEnterForeground();
    }

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeInsertText(JNIEnv* env, jobject thiz, jstring text)
    {
        //TODO
    }

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeDeleteBackward(JNIEnv* env, jobject thiz)
    {
        //TODO
    }

    JNIEXPORT jstring JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeGetContentText()
    {
        //TODO
    }

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeOnSurfaceChanged(JNIEnv*  env, jobject thiz, jint w, jint h)
    {
        //TODO
    }

    /***********************************************************
	 * Cocos2dxAccelerometer native functions implementation.
	 ***********************************************************/

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxAccelerometer_onSensorChanged(JNIEnv*  env, jobject thiz, jfloat x, jfloat y, jfloat z, jlong timeStamp)
    {
        //TODO
    }

    /***********************************************************
	 * Touches native functions implementation.
	 ***********************************************************/

    static void dispatchTouchEventWithOnePoint(JNIEnv* env, cocos2d::TouchEvent::Type type, jint id, jfloat x, jfloat y)
    {
        if (g_isGameFinished) {
            return;
        }
        cocos2d::TouchEvent touchEvent;
        touchEvent.type = type;

        uint8_t devicePixelRatio = Application::getInstance()->getDevicePixelRatio();
        cocos2d::TouchInfo touchInfo;
        touchInfo.index = id;
        touchInfo.x = x / devicePixelRatio;
        touchInfo.y = y / devicePixelRatio;
        touchEvent.touches.push_back(touchInfo);
        
        cocos2d::EventDispatcher::dispatchTouchEvent(touchEvent);
    }

    static void dispatchTouchEventWithPoints(JNIEnv* env, cocos2d::TouchEvent::Type type, jintArray ids, jfloatArray xs, jfloatArray ys)
    {
        if (g_isGameFinished) {
            return;
        }
        cocos2d::TouchEvent touchEvent;
        touchEvent.type = type;

        int size = env->GetArrayLength(ids);
        jint id[size];
        jfloat x[size];
        jfloat y[size];

        env->GetIntArrayRegion(ids, 0, size, id);
        env->GetFloatArrayRegion(xs, 0, size, x);
        env->GetFloatArrayRegion(ys, 0, size, y);

        uint8_t devicePixelRatio = Application::getInstance()->getDevicePixelRatio();
        for(int i = 0; i < size; i++)
        {
            cocos2d::TouchInfo touchInfo;
            touchInfo.index = id[i];
            touchInfo.x = x[i] / devicePixelRatio;
            touchInfo.y = y[i] / devicePixelRatio;
            touchEvent.touches.push_back(touchInfo);
        }

        cocos2d::EventDispatcher::dispatchTouchEvent(touchEvent);
    }

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeTouchesBegin(JNIEnv * env, jobject thiz, jint id, jfloat x, jfloat y)
    {
        if (g_isGameFinished) {
            return;
        }
        dispatchTouchEventWithOnePoint(env, cocos2d::TouchEvent::Type::BEGAN, id, x, y);
    }

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeTouchesEnd(JNIEnv * env, jobject thiz, jint id, jfloat x, jfloat y)
    {
        if (g_isGameFinished) {
            return;
        }
        dispatchTouchEventWithOnePoint(env, cocos2d::TouchEvent::Type::ENDED, id, x, y);
    }

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeTouchesMove(JNIEnv * env, jobject thiz, jintArray ids, jfloatArray xs, jfloatArray ys)
    {
        if (g_isGameFinished) {
            return;
        }
        dispatchTouchEventWithPoints(env, cocos2d::TouchEvent::Type::MOVED, ids, xs, ys);
    }

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeTouchesCancel(JNIEnv * env, jobject thiz, jintArray ids, jfloatArray xs, jfloatArray ys)
    {
        if (g_isGameFinished) {
            return;
        }
        dispatchTouchEventWithPoints(env, cocos2d::TouchEvent::Type::CANCELLED, ids, xs, ys);
    }

    JNIEXPORT jboolean JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeKeyEvent(JNIEnv * env, jobject thiz, jint keyCode, jboolean isPressed)
    {
        if (g_isGameFinished) {
            return JNI_TRUE;
        }
        //TODO
        return JNI_TRUE;

    }

    /***********************************************************
     * Cocos2dxHelper native functions implementation.
     ***********************************************************/

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxHelper_nativeSetApkPath(JNIEnv* env, jobject thiz, jstring apkPath)
    {
        g_apkPath = JniHelper::jstring2string(apkPath);
    }

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxHelper_nativeSetContext(JNIEnv*  env, jobject thiz, jobject context, jobject assetManager)
    {
        JniHelper::setClassLoaderFrom(context);
        FileUtilsAndroid::setassetmanager(AAssetManager_fromJava(env, assetManager));
    }

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxHelper_nativeSetAudioDeviceInfo(JNIEnv*  env, jobject thiz, jboolean isSupportLowLatency, jint deviceSampleRate, jint deviceAudioBufferSizeInFrames)
    {
        g_deviceSampleRate = deviceSampleRate;
        g_deviceAudioBufferSizeInFrames = deviceAudioBufferSizeInFrames;
        LOGD("nativeSetAudioDeviceInfo: sampleRate: %d, bufferSizeInFrames: %d", g_deviceSampleRate, g_deviceAudioBufferSizeInFrames);
    }

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxHelper_nativeSetEditTextDialogResult(JNIEnv* env, jobject obj, jbyteArray text)
    {
        jsize  size = env->GetArrayLength(text);

        if (size > 0) 
        {
            jbyte * data = (jbyte*)env->GetByteArrayElements(text, 0);
            char* buffer = (char*)malloc(size+1);
            if (buffer != nullptr) 
            {
                memcpy(buffer, data, size);
                buffer[size] = '\0';
                // pass data to edittext's delegate
                if (s_editTextCallback)
                    s_editTextCallback(buffer, s_ctx);
                free(buffer);
            }
            env->ReleaseByteArrayElements(text, data, 0);
        } 
        else 
        {
            if (s_editTextCallback)
                s_editTextCallback("", s_ctx);
        }
    }

    /***********************************************************
     * Cocos2dxAudioFocusManager native functions implementation.
     ***********************************************************/

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxAudioFocusManager_nativeOnAudioFocusChange(JNIEnv* env, jobject thiz, jint focusChange)
    {
        // cocos_audioengine_focus_change(focusChange);
    }
} // end of extern "C"

void restartJSVM()
{
    g_isStarted = false;
}

/***********************************************************
 * Functions invoke from cpp to Java.
 ***********************************************************/

std::string getApkPathJNI() 
{
    return g_apkPath;
}

std::string getPackageNameJNI() 
{
    return JniHelper::callStaticStringMethod(Cocos2dxHelperClassName, "getCocos2dxPackageName");
}

int getObbAssetFileDescriptorJNI(const std::string& path, long* startOffset, long* size) 
{
    JniMethodInfo methodInfo;
    int fd = 0;
    
    if (JniHelper::getStaticMethodInfo(methodInfo, Cocos2dxHelperClassName.c_str(), "getObbAssetFileDescriptor", "(Ljava/lang/String;)[J")) 
    {
        jstring stringArg = methodInfo.env->NewStringUTF(path.c_str());
        jlongArray newArray = (jlongArray)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID, stringArg);
        jsize theArrayLen = methodInfo.env->GetArrayLength(newArray);
        
        if (3 == theArrayLen) 
        {
            jboolean copy = JNI_FALSE;
            jlong *array = methodInfo.env->GetLongArrayElements(newArray, &copy);
            fd = static_cast<int>(array[0]);
            *startOffset = array[1];
            *size = array[2];
            methodInfo.env->ReleaseLongArrayElements(newArray, array, 0);
        }
        
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        methodInfo.env->DeleteLocalRef(stringArg);
    }
    
    return fd;
}

int getDeviceSampleRateJNI()
{
    return g_deviceSampleRate;
}

int getDeviceAudioBufferSizeInFramesJNI()
{
    return g_deviceAudioBufferSizeInFrames;
}

void convertEncodingJNI(const std::string& src, int byteSize, const std::string& fromCharset, std::string& dst, const std::string& newCharset)
{
    JniMethodInfo methodInfo;

    if (JniHelper::getStaticMethodInfo(methodInfo, Cocos2dxHelperClassName.c_str(), "conversionEncoding", "([BLjava/lang/String;Ljava/lang/String;)[B")) 
    {
        jbyteArray strArray = methodInfo.env->NewByteArray(byteSize);
        methodInfo.env->SetByteArrayRegion(strArray, 0, byteSize, reinterpret_cast<const jbyte*>(src.c_str()));

        jstring stringArg1 = methodInfo.env->NewStringUTF(fromCharset.c_str());
        jstring stringArg2 = methodInfo.env->NewStringUTF(newCharset.c_str());

        jbyteArray newArray = (jbyteArray)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID, strArray, stringArg1, stringArg2);
        jsize theArrayLen = methodInfo.env->GetArrayLength(newArray);
        methodInfo.env->GetByteArrayRegion(newArray, 0, theArrayLen, (jbyte*)dst.c_str());

        methodInfo.env->DeleteLocalRef(strArray);
        methodInfo.env->DeleteLocalRef(stringArg1);
        methodInfo.env->DeleteLocalRef(stringArg2);
        methodInfo.env->DeleteLocalRef(newArray);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

std::string getCurrentLanguageJNI()
{
    return JniHelper::callStaticStringMethod(Cocos2dxHelperClassName, "getCurrentLanguage");
}

std::string getSystemVersionJNI()
{
    return JniHelper::callStaticStringMethod(Cocos2dxHelperClassName, "getSystemVersion");
}

bool openURLJNI(const std::string& url)
{
    return JniHelper::callStaticBooleanMethod(Cocos2dxHelperClassName, "openURL", url);
}

void setPreferredFramesPerSecondJNI(int fps)
{
    JniHelper::callStaticVoidMethod(Cocos2dxRendererClassName, "setPreferredFramesPerSecond", fps);
}

void setGameInfoDebugViewTextJNI(int index, const std::string& text)
{
    if (!__isOpenDebugView)
        return;
    JniHelper::callStaticVoidMethod(Cocos2dxHelperClassName, "setGameInfoDebugViewText", index, text);
}

void setJSBInvocationCountJNI(int count)
{
    if (!__isOpenDebugView)
        return;
    JniHelper::callStaticVoidMethod(Cocos2dxHelperClassName, "setJSBInvocationCount", count);
}

void openDebugViewJNI()
{
    if (!__isOpenDebugView)
    {
        LOGD("openDebugViewJNI ...");
        __isOpenDebugView = true;
        JniHelper::callStaticVoidMethod(Cocos2dxHelperClassName, "openDebugView");
        if (!__isGLOptModeEnabled)
        {
            JniHelper::callStaticVoidMethod(Cocos2dxHelperClassName, "disableBatchGLCommandsToNative");
        }
    }
}

void disableBatchGLCommandsToNativeJNI()
{
    __isGLOptModeEnabled = false;
    if (__isOpenDebugView)
    {
        JniHelper::callStaticVoidMethod(Cocos2dxHelperClassName, "disableBatchGLCommandsToNative");
    }
}

void exitApplicationJNI()
{
    JniHelper::callStaticVoidMethod(Cocos2dxHelperClassName, "endApplication");
}
