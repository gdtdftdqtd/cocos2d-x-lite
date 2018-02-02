/****************************************************************************
 Copyright (c) 2010-2012 cocos2d-x.org
 Copyright (c) 2013-2016 Chukong Technologies Inc.

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

#import "CCApplication.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import <UIKit/UIKit.h>

#import "math/CCGeometry.h"
#import "platform/ios/CCDirectorCaller-ios.h"

#include <sys/param.h>
#include <sys/mount.h>

#import <Security/Security.h>

NS_CC_BEGIN

Application* Application::sm_pSharedApplication = nullptr;

Application::Application()
{
    CC_ASSERT(! sm_pSharedApplication);
    sm_pSharedApplication = this;
}

Application::~Application()
{
    CC_ASSERT(this == sm_pSharedApplication);
    sm_pSharedApplication = 0;
}

int Application::run()
{
    if (applicationDidFinishLaunching())
    {
        [[CCDirectorCaller sharedDirectorCaller] startMainLoop];
    }
    return 0;
}

void Application::setAnimationInterval(float interval)
{
    [[CCDirectorCaller sharedDirectorCaller] setAnimationInterval: interval ];
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// static member function
//////////////////////////////////////////////////////////////////////////////////////////////////

Application* Application::getInstance()
{
    CC_ASSERT(sm_pSharedApplication);
    return sm_pSharedApplication;
}

void Application::destroyInstance()
{
    if (sm_pSharedApplication) {
        delete  sm_pSharedApplication;
    }

    sm_pSharedApplication = nullptr;
}

const char * Application::getCurrentLanguageCode()
{
    static char code[3]={0};
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSArray *languages = [defaults objectForKey:@"AppleLanguages"];
    NSString *currentLanguage = [languages objectAtIndex:0];

    // get the current language code.(such as English is "en", Chinese is "zh" and so on)
    NSDictionary* temp = [NSLocale componentsFromLocaleIdentifier:currentLanguage];
    NSString * languageCode = [temp objectForKey:NSLocaleLanguageCode];
    [languageCode getCString:code maxLength:3 encoding:NSASCIIStringEncoding];
    code[2]='\0';
    return code;
}

LanguageType Application::getCurrentLanguage()
{
    // get the current language and country config
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSArray *languages = [defaults objectForKey:@"AppleLanguages"];
    NSString *currentLanguage = [languages objectAtIndex:0];

    // get the current language code.(such as English is "en", Chinese is "zh" and so on)
    NSDictionary* temp = [NSLocale componentsFromLocaleIdentifier:currentLanguage];
    NSString * languageCode = [temp objectForKey:NSLocaleLanguageCode];

    if ([languageCode isEqualToString:@"zh"]) return LanguageType::CHINESE;
    if ([languageCode isEqualToString:@"en"]) return LanguageType::ENGLISH;
    if ([languageCode isEqualToString:@"fr"]) return LanguageType::FRENCH;
    if ([languageCode isEqualToString:@"it"]) return LanguageType::ITALIAN;
    if ([languageCode isEqualToString:@"de"]) return LanguageType::GERMAN;
    if ([languageCode isEqualToString:@"es"]) return LanguageType::SPANISH;
    if ([languageCode isEqualToString:@"nl"]) return LanguageType::DUTCH;
    if ([languageCode isEqualToString:@"ru"]) return LanguageType::RUSSIAN;
    if ([languageCode isEqualToString:@"ko"]) return LanguageType::KOREAN;
    if ([languageCode isEqualToString:@"ja"]) return LanguageType::JAPANESE;
    if ([languageCode isEqualToString:@"hu"]) return LanguageType::HUNGARIAN;
    if ([languageCode isEqualToString:@"pt"]) return LanguageType::PORTUGUESE;
    if ([languageCode isEqualToString:@"ar"]) return LanguageType::ARABIC;
    if ([languageCode isEqualToString:@"nb"]) return LanguageType::NORWEGIAN;
    if ([languageCode isEqualToString:@"pl"]) return LanguageType::POLISH;
    if ([languageCode isEqualToString:@"tr"]) return LanguageType::TURKISH;
    if ([languageCode isEqualToString:@"uk"]) return LanguageType::UKRAINIAN;
    if ([languageCode isEqualToString:@"ro"]) return LanguageType::ROMANIAN;
    if ([languageCode isEqualToString:@"bg"]) return LanguageType::BULGARIAN;
    return LanguageType::ENGLISH;

}

std::string Application::getCurrentLanguageString()
{
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSArray *languages = [defaults objectForKey:@"AppleLanguages"];
    NSString *currentLanguage = [languages objectAtIndex:0];
    return [currentLanguage UTF8String];
}

Application::Platform Application::getTargetPlatform()
{
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) // idiom for iOS <= 3.2, otherwise: [UIDevice userInterfaceIdiom] is faster.
    {
        return Platform::OS_IPAD;
    }
    else
    {
        return Platform::OS_IPHONE;
    }
}

std::string Application::getVersion() {
    NSString* version = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"];
    if (version) {
        return [version UTF8String];
    }
    return "";
}

bool Application::openURL(const std::string &url)
{
    NSString* msg = [NSString stringWithCString:url.c_str() encoding:NSUTF8StringEncoding];
    NSURL* nsUrl = [NSURL URLWithString:msg];
    return [[UIApplication sharedApplication] openURL:nsUrl];
}

void Application::applicationScreenSizeChanged(int newWidth, int newHeight) {

}

//add by chl
long long Application::getFreeDiskSpace()
{
    struct statfs buf;
    unsigned long long freespace = 0;
    if(statfs("/var", &buf) >= 0){
        freespace = (unsigned long long)(buf.f_bsize * buf.f_bfree);
//        freespace = freespace;//1024*1024
    }
    
    return freespace;//M
}

std::string Application::getAppUUID()
{
    //该类方法没有线程保护，所以可能因异步而导致创建出不同的设备唯一ID，故而增加此线程锁！
    @synchronized ([NSNotificationCenter defaultCenter])
    {
        NSString* service = @"CreateDeviceIdentifierByKeychain";
        NSString* account = @"VirtualDeviceIdentifier";
        //获取iOS系统推荐的设备唯一ID
        NSString* recommendDeviceIdentifier = [[[UIDevice currentDevice] identifierForVendor] UUIDString];
        recommendDeviceIdentifier = [recommendDeviceIdentifier stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
        NSMutableDictionary* queryDic = [NSMutableDictionary dictionary];
        [queryDic setObject:(__bridge id)kSecClassGenericPassword forKey:(__bridge id)kSecClass];
        [queryDic setObject:service forKey:(__bridge id)kSecAttrService];
        [queryDic setObject:(__bridge id)kCFBooleanFalse forKey:(__bridge id)kSecAttrSynchronizable];
        [queryDic setObject:account forKey:(__bridge id)kSecAttrAccount];
        [queryDic setObject:(__bridge id)kSecMatchLimitOne forKey:(__bridge id)kSecMatchLimit];//默认值为kSecMatchLimitOne，表示返回结果集的第一个
        [queryDic setObject:(__bridge id)kCFBooleanTrue forKey:(__bridge id)kSecReturnData];
        CFTypeRef keychainPassword = NULL;
        //首先查询钥匙串是否存在对应的值，如果存在则直接返回钥匙串中的值
        OSStatus queryResult = SecItemCopyMatching((__bridge CFDictionaryRef)queryDic, &keychainPassword);
        if (queryResult == errSecSuccess)
        {
            NSString *pwd = [[NSString alloc] initWithData:(__bridge NSData * _Nonnull)(keychainPassword) encoding:NSUTF8StringEncoding];
            if ([pwd isKindOfClass:[NSString class]] && pwd.length > 0)
            {
                return [pwd UTF8String];
            }
            else
            {
                //如果钥匙串中的相关数据不合法，则删除对应的数据重新创建
                NSMutableDictionary* deleteDic = [NSMutableDictionary dictionary];
                [deleteDic setObject:(__bridge id)kSecClassGenericPassword forKey:(__bridge id)kSecClass];
                [deleteDic setObject:service forKey:(__bridge id)kSecAttrService];
                [deleteDic setObject:(__bridge id)kCFBooleanFalse forKey:(__bridge id)kSecAttrSynchronizable];
                [deleteDic setObject:account forKey:(__bridge id)kSecAttrAccount];
                OSStatus status = SecItemDelete((__bridge CFDictionaryRef)deleteDic);
                if (status != errSecSuccess)
                {
                    return [recommendDeviceIdentifier UTF8String];
                }
            }
        }
        if (recommendDeviceIdentifier.length > 0)
        {
            //创建数据到钥匙串，达到APP即使被删除也不会变更的设备唯一ID，除非系统抹除数据，否则该数据将存储在钥匙串中
            NSMutableDictionary* createDic = [NSMutableDictionary dictionary];
            [createDic setObject:(__bridge id)kSecClassGenericPassword forKey:(__bridge id)kSecClass];
            [createDic setObject:service forKey:(__bridge id)kSecAttrService];
            [createDic setObject:account forKey:(__bridge id)kSecAttrAccount];
            [createDic setObject:(__bridge id)kCFBooleanFalse forKey:(__bridge id)kSecAttrSynchronizable];//不可以使用iCloud同步钥匙串数据，否则导致同一个iCloud账户的多个设备获取的唯一ID相同
            [createDic setObject:(__bridge id)kSecAttrAccessibleAlwaysThisDeviceOnly forKey:(__bridge id)kSecAttrAccessible];//增加一道保险，防止钥匙串数据被同步到其他设备，保证设备ID绝对唯一。
            [createDic setObject:[recommendDeviceIdentifier dataUsingEncoding:NSUTF8StringEncoding] forKey:(__bridge id)kSecValueData];
            OSStatus createResult = SecItemAdd((__bridge CFDictionaryRef)createDic, nil);
            if (createResult != errSecSuccess)
            {
                NSLog(@"通过钥匙串创建设备唯一ID不成功！");
            }
        }
        return [recommendDeviceIdentifier UTF8String];
    }
    return "0";
}

NS_CC_END

#endif // CC_PLATFORM_IOS
