#include "StartScene.h"
#include "HelloWorldScene.h"
#include "RatingScene.h"
#include "HelpScene.h"
#include "SettingScene.h"
#include "ExitLayer.h"
#include "SimpleAudioEngine.h"
#include "CCFileUtilsWin32.h"
#include "SaveData.h"
#include "EnterNameLayer.h"
USING_NS_CC;
using namespace CocosDenshion;

CCScene* Start::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Start *layer = Start::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Start::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    /////////////////
	setTouchEnabled(true);

// 预加载背景音乐和音效：相对路径 .mid和.wav等格式文件
    //SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic( CCFileUtils::sharedFileUtils()->fullPathForFilename(MUSIC_FILE) );
    //SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathForFilename(EFFECT_FILE) );

	SaveData::getInstant()->readSetting();
	bool isMusic = SaveData::getInstant()->IsMusic();
	bool isSound = SaveData::getInstant()->IsSound();
	bool isVibrate = SaveData::getInstant()->IsVibrate();
	
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    CCSprite* pSprite = CCSprite::create("bgofstart.png");
	pSprite->setScale(0.5f);               // 精灵的缩放
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);

    CCMenuItemImage *pstartItem = CCMenuItemImage::create(
                                        "startgame.png",
                                        "startgame.png",
                                        this,
                                        menu_selector(Start::menuStartCallback));
	pstartItem->setPosition(ccp(0,200));
	pstartItem->setTag(1);
    CCMenuItemImage *pexitItem = CCMenuItemImage::create(
                                        "exitgame.png",
                                        "exitgame.png",
                                        this,
                                        menu_selector(Start::menuStartCallback));
	pexitItem->setPosition(ccp(0,0));
	pexitItem->setScale(0.5f);
	pexitItem->setTag(2);
	/*
    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pRelaxModeItem = CCMenuItemImage::create(
                                        "relaxmode.png",
                                        "relaxmode.png",
                                        this,
                                        menu_selector(Start::menuStartCallback));
	pRelaxModeItem->setPosition(ccp(origin.x + visibleSize.width - pRelaxModeItem->getContentSize().width/2 ,
                                origin.y + pRelaxModeItem->getContentSize().height/2));
    pRelaxModeItem->setTag(1);
    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pChallegeModeItem = CCMenuItemImage::create(
                                        "challegemode.png",
                                        "challegemode.png",
                                        this,
                                        menu_selector(Start::menuStartCallback));
	pChallegeModeItem->setPosition(ccp(origin.x + visibleSize.width - pChallegeModeItem->getContentSize().width/2 ,
                                origin.y + pChallegeModeItem->getContentSize().height/2));
    pChallegeModeItem->setTag(2);
    */
    // create menu, it's an autorelease object
    CCMenu* pStartMenu = CCMenu::create(pstartItem, pexitItem, NULL);
	pStartMenu->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 - pexitItem->getContentSize().height/2));
	//pStartMenu->setScale(0.5f);
    this->addChild(pStartMenu, 1);

	

    CCMenuItemImage *pSettingItem = CCMenuItemImage::create(
                                        "settingbtn.png",
                                        "settingbtn.png",
                                        this,
                                        menu_selector(Start::menuSettingCallback));
    
	pSettingItem->setPosition(ccp(0,0));

    pSettingItem->setTag(1);
    CCMenuItemImage *pRatingItem = CCMenuItemImage::create(
                                        "ratingbtn.png",
                                        "ratingbtn.png",
                                        this,
                                        menu_selector(Start::menuSettingCallback));
	pRatingItem->setPosition(ccp(pSettingItem->getContentSize().width,0));
    pRatingItem->setTag(2);
    CCMenuItemImage *pHelpItem = CCMenuItemImage::create(
                                        "helpbtn.png",
                                        "helpbtn.png",
                                        this,
                                        menu_selector(Start::menuSettingCallback));
    
	pHelpItem->setPosition(ccp(pRatingItem->getContentSize().width*2,0));
    pHelpItem->setTag(3);
    // create menu, it's an autorelease object
    CCMenu* pSettingMenu = CCMenu::create(pSettingItem, pRatingItem, pHelpItem, NULL);
	pSettingMenu->setPosition(ccp(-pSettingItem->getContentSize().width/4+50, -pHelpItem->getContentSize().height/2-50));
	pSettingMenu->setScale(0.2f);
    this->addChild(pSettingMenu, 1);

    if (isMusic)
    {
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(std::string(CCFileUtils::sharedFileUtils()->fullPathForFilename("zzhtnyt.mp3")).c_str(), true);
    }
 
    return true;
}

void Start::menuStartCallback(CCObject* pSender)
{
	CCMenuItemImage* item = (CCMenuItemImage*)pSender;
	CCScene *pScene = NULL;
    CCTransitionFade *reScene = NULL;
	switch (item->getTag())
	{
	case 1:
		pScene = HelloWorld::scene();
		reScene = CCTransitionFade::create(1.0f, pScene);
	    CCDirector::sharedDirector()->replaceScene(reScene); 
		break;
	case 2:
        CCAction* popupLayer = CCSequence::create(CCScaleTo::create(0.0, 0.0),
                                          CCScaleTo::create(0.06, 1.05),
                                          CCScaleTo::create(0.08, 0.95),
                                          CCScaleTo::create(0.08, 1.0), NULL);

         ExitLayer* exitLayer = new ExitLayer();
		 //EnterNameLayer* exitLayer = new EnterNameLayer();
		 exitLayer->init();
		 exitLayer->runAction(popupLayer);
         this->addChild(exitLayer, 3);
        
		break;
	}
}

void Start::menuSettingCallback(CCObject* pSender)
{
	CCMenuItemImage* item = (CCMenuItemImage*)pSender;
	CCScene *pScene = NULL;
	switch (item->getTag())
	{
	case 1:
		pScene = Setting::scene();
		break;
	case 2:
        pScene = Rating::scene();
		break;
	case 3:
        pScene = Help::scene();
		break;
	}
    CCTransitionFade *reScene = CCTransitionFade::create(1.0f, pScene);
    CCDirector::sharedDirector()->replaceScene(reScene); 
}
