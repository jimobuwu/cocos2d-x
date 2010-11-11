// Application application cpp file.
 
// Original file name: test_uphoneApp.cpp
// Generated by TOPS Builder:Project wizard,Date:2010-7-26
 

#include  "test_uphoneApp.h"
#include  "test_uphoneMainForm.h"
#include "tests/controller.h"

// #include "CCDirector.h"
// #include "CCScene.h"
// #include "CCSprite.h"
// #include "tests/controller.h"
// #include "CCTextureCache.h"

using namespace cocos2d;

static void TimerCallback1(Int32 nTimerId, UInt32 uUserData);

Ttest_uphoneApp::Ttest_uphoneApp()
: m_pMainWnd(NULL)
, m_nTimer(0)
{

}

Ttest_uphoneApp::~Ttest_uphoneApp()
{

}

bool Ttest_uphoneApp::applicationDidFinishLaunching()
{
	// init the window
	if (! (m_pMainWnd = new TMainForm(this)) )
	{
		return false;
	}

    // init director
    CCDirector * pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(m_pMainWnd);
    pDirector->setDeviceOrientation(kCCDeviceOrientationLandscapeLeft);
	/*pDirector->setDeviceOrientation(kCCDeviceOrientationPortrait);*/
    pDirector->setDisplayFPS(true);

    // set the resource path
    CCFileUtils::setResourcePath("/NEWPLUS/TDA_DATA/Data/cocos2d_tests/");

    // load background image texture and get window size
    CCTexture2D * pTexture = CCTextureCache::sharedTextureCache()->addImage("Images/HelloWorld.png");
    CGSize size = CCDirector::sharedDirector()->getWinSize();

    // create sprite instance
    CCSprite * pSprite = new CCSprite();
	pSprite->initWithTexture(pTexture); 
    pSprite->setPosition(CGPoint(size.width / 2, size.height / 2));
    pSprite->autorelease();

    // create layer instance
    CCLayer * pLayer = new CCLayer();
    pLayer->addChild(pSprite);
    pLayer->autorelease();

    // add layer to scene
    CCScene * pScene = CCScene::node();
    pScene->addChild(pLayer);

    // add scene to director
    CCDirector::sharedDirector()->runWithScene(pScene);

    m_nTimer = TIMER_Create(3000, TIMER_MODE_NORMAL, TimerCallback1, 0, 0);
    TIMER_Start(m_nTimer, 0);

    return true;
}

void Ttest_uphoneApp::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
}

void Ttest_uphoneApp::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
}

static void TimerCallback1(Int32 nTimerId, UInt32 uUserData)
{
    CCScene * pScene = CCScene::node();
    CCLayer * pLayer = new TestController();
    pLayer->autorelease();

    pScene->addChild(pLayer);
    CCDirector::sharedDirector()->replaceScene(pScene);
}
