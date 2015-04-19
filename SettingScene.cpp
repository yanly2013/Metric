#include "SettingScene.h"
#include "StartScene.h"
#include "SaveData.h"
#include "SimpleAudioEngine.h"
#include "DefScreenAdp.h"
USING_NS_CC;
using namespace CocosDenshion;
CCScene* Setting::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Setting *layer = Setting::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Setting::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    /////////////////
	setTouchEnabled(true);

    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    CCSprite* pSprite = CCSprite::create("setting.png");
	pSprite->setScale(ScaleFactor);               // 精灵的缩放
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);

	SaveData::getInstant()->readSetting();
	isMusic = SaveData::getInstant()->IsMusic();
	isSound = SaveData::getInstant()->IsSound();
	isVibrate = SaveData::getInstant()->IsVibrate();
	
    CCMenuItemImage *pmusiconItem = CCMenuItemImage::create(  
                                  "musicon.png", //png.jpg等图片格式都是可以的  
                                  "musicon.png");  
    CCMenuItemImage *pmusicoffItem = CCMenuItemImage::create(  
                                  "musicoff.png", //png.jpg等图片格式都是可以的  
                                  "musicoff.png"); 
    CCMenuItemToggle *pmusictoggle = NULL;
	if (isMusic)
	{
        pmusictoggle = CCMenuItemToggle::createWithTarget(this, menu_selector(Setting::menuSettingCallback),pmusiconItem, pmusicoffItem, NULL);
    }
	else
	{
        pmusictoggle = CCMenuItemToggle::createWithTarget(this, menu_selector(Setting::menuSettingCallback),pmusicoffItem, pmusiconItem, NULL);
	}
	pmusictoggle->setTag(1);
	pmusictoggle->setPosition(ccp(0,400));
    CCMenuItemImage *psoundonItem = CCMenuItemImage::create(  
                                  "soundon.png", //png.jpg等图片格式都是可以的  
                                  "soundon.png");  
    CCMenuItemImage *psoundoffItem = CCMenuItemImage::create(  
                                  "soundoff.png", //png.jpg等图片格式都是可以的  
                                  "soundoff.png"); 
    CCMenuItemToggle *psoundtoggle = NULL;
	if (isSound)
	{
        psoundtoggle = CCMenuItemToggle::createWithTarget(this, menu_selector(Setting::menuSettingCallback),psoundonItem, psoundoffItem, NULL);
	}
    else
    {
        psoundtoggle = CCMenuItemToggle::createWithTarget(this, menu_selector(Setting::menuSettingCallback),psoundoffItem, psoundonItem, NULL);
    }

	psoundtoggle->setTag(2);
	psoundtoggle->setPosition(ccp(0,200));
    CCMenuItemImage *pvibrateonItem = CCMenuItemImage::create(  
                                  "vibrateon.png", //png.jpg等图片格式都是可以的  
                                  "vibrateon.png");  
    CCMenuItemImage *pvibrateoffItem = CCMenuItemImage::create(  
                                  "vibrateoff.png", //png.jpg等图片格式都是可以的  
                                  "vibrateoff.png"); 
    CCMenuItemToggle *pvibratetoggle = NULL;
    if (isVibrate)
    {
    	pvibratetoggle = CCMenuItemToggle::createWithTarget(this, menu_selector(Setting::menuSettingCallback),pvibrateonItem, pvibrateoffItem, NULL);
    }
	else
	{
	    pvibratetoggle = CCMenuItemToggle::createWithTarget(this, menu_selector(Setting::menuSettingCallback),pvibrateoffItem, pvibrateonItem,  NULL);
	}

    pvibratetoggle->setTag(3);
	pvibratetoggle->setPosition(ccp(0,0));
	CCMenu* pSettingMenu = CCMenu::create(pmusictoggle, psoundtoggle, pvibratetoggle, NULL);
	pSettingMenu->setPosition(ccp(100,100));
	pSettingMenu->setScale(ScaleFactor);
	this->addChild(pSettingMenu, 1);

	
    CCMenuItemImage *pokItem = CCMenuItemImage::create(  
                                  "returnbutton.png", //png.jpg等图片格式都是可以的  
                                  "returnbutton.png",  
                                    this,  
                                    menu_selector(Setting::menuOKCallback));  	
    pokItem->setPosition(ccp(0,0));

	CCMenu* pOKMenu = CCMenu::create(pokItem, NULL);
	pOKMenu->setPosition(ccp(100,-100));
	pOKMenu->setScale(ScaleFactor);
	this->addChild(pOKMenu, 1);
 
    return true;
}
void Setting::menuSettingCallback(CCObject* pSender)
{
	CCMenuItemToggle* item = (CCMenuItemToggle*)pSender;
	switch (item->getTag())
	{
	case 1:
		isMusic = !isMusic;
		if (isMusic)
		{
		    if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
		    {
		        SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
		    }
			else
			{
		        SimpleAudioEngine::sharedEngine()->playBackgroundMusic(std::string(CCFileUtils::sharedFileUtils()->fullPathForFilename("zzhtnyt.mp3")).c_str(), true);
			}
		}
		else
		{
            if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
            {
			    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
            }
		}
		break;
	case 2:
        isSound = !isSound;
		SimpleAudioEngine::sharedEngine()->playEffect(std::string(CCFileUtils::sharedFileUtils()->fullPathForFilename("Speech.wav")).c_str(), true);
		break;
	case 3:
        isVibrate = !isVibrate;
		break;
	}
}

void  Setting::menuOKCallback(CCObject* pSender)
{
    SaveData::getInstant()->saveSetting(isMusic, isSound, isVibrate);

    CCScene *pScene = Start::scene();

    CCTransitionFade *reScene = CCTransitionFade::create(1.0f, pScene);
	CCDirector::sharedDirector()->popScene(); 
}
