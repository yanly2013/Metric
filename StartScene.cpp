#include "StartScene.h"
#include "HelloWorldScene.h"
#include "RatingScene.h"
#include "HelpScene.h"
#include "SettingScene.h"
#include "ExitLayer.h"
#include "SimpleAudioEngine.h"
//#include "CCFileUtilsWin32.h"
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

// Ԥ���ر������ֺ���Ч�����·�� .mid��.wav�ȸ�ʽ�ļ�
    //SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic( CCFileUtils::sharedFileUtils()->fullPathForFilename(MUSIC_FILE) );
    //SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathForFilename(EFFECT_FILE) );

	SaveData::getInstant()->readSetting();
	bool isMusic = SaveData::getInstant()->IsMusic();
	bool isSound = SaveData::getInstant()->IsSound();
	bool isVibrate = SaveData::getInstant()->IsVibrate();
	
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    CCSprite* pSprite = CCSprite::create("bgofstart.png");
	pSprite->setScale(ScaleFactor);               // ���������
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);

    CCMenuItemImage *pleisuremodeItem = CCMenuItemImage::create(
                                        "leisuremode.png",
                                        "leisuremodeclick.png",
                                        this,
                                        menu_selector(Start::menuStartCallback));
	pleisuremodeItem->setPosition(ccp(50,350));
	pleisuremodeItem->setScale(0.7f);
	pleisuremodeItem->setTag(1);
	
    CCMenuItemImage *ptimemodeItem = CCMenuItemImage::create(
                                        "timemode.png",
                                        "timemodeclick.png",
                                        this,
                                        menu_selector(Start::menuStartCallback));
	ptimemodeItem->setPosition(ccp(-100,200));
	ptimemodeItem->setScale(0.7f);
	ptimemodeItem->setTag(3);
	
    CCMenuItemImage *pcrazymodeItem = CCMenuItemImage::create(
                                        "crazymode.png",
                                        "crazymodeclick.png",
                                        this,
                                        menu_selector(Start::menuStartCallback));
	pcrazymodeItem->setPosition(ccp(90,130));
	pcrazymodeItem->setScale(0.7f);
	pcrazymodeItem->setTag(4);
	

    CCMenuItemImage *pexitItem = CCMenuItemImage::create(
                                        "exitgame.png",
                                        "exitgameclick.png",
                                        this,
                                        menu_selector(Start::menuStartCallback));
	pexitItem->setPosition(ccp(0,0));
	pexitItem->setScale(ScaleFactor);
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
    CCMenu* pStartMenu = CCMenu::create(pleisuremodeItem, ptimemodeItem, pcrazymodeItem, pexitItem, NULL);
	pStartMenu->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 - pexitItem->getContentSize().height/2));
	//pStartMenu->setScale(ScaleFactor);
    this->addChild(pStartMenu, 1);

	

    CCMenuItemImage *pSettingItem = CCMenuItemImage::create(
                                        "settingbtn.png",
                                        "settingbtnclick.png",
                                        this,
                                        menu_selector(Start::menuSettingCallback));
    
	pSettingItem->setPosition(ccp(0,0));

    pSettingItem->setTag(1);
    CCMenuItemImage *pRatingItem = CCMenuItemImage::create(
                                        "ratingbtn.png",
                                        "ratingbtnclick.png",
                                        this,
                                        menu_selector(Start::menuSettingCallback));
	pRatingItem->setPosition(ccp(pSettingItem->getContentSize().width,0));
    pRatingItem->setTag(2);
    CCMenuItemImage *pHelpItem = CCMenuItemImage::create(
                                        "helpbtn.png",
                                        "helpbtnclick.png",
                                        this,
                                        menu_selector(Start::menuSettingCallback));
    
	pHelpItem->setPosition(ccp(pRatingItem->getContentSize().width*2,0));
    pHelpItem->setTag(3);
    // create menu, it's an autorelease object
    CCMenu* pSettingMenu = CCMenu::create(pSettingItem, pRatingItem, pHelpItem, NULL);
	pSettingMenu->setPosition(ccp(-pSettingItem->getContentSize().width/4+50, -pHelpItem->getContentSize().height/2-50));
	pSettingMenu->setScale(ScaleFactor);//(0.2f);
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
		pScene = HelloWorld::scene(1);
		reScene = CCTransitionFade::create(1.0f, pScene);
	    CCDirector::sharedDirector()->replaceScene(reScene); 
		break;
    case 3:
		pScene = HelloWorld::scene(3);
		reScene = CCTransitionFade::create(1.0f, pScene);
	    CCDirector::sharedDirector()->replaceScene(reScene); 
		break;
    case 4:
		pScene = HelloWorld::scene(4);
		reScene = CCTransitionFade::create(1.0f, pScene);
	    CCDirector::sharedDirector()->replaceScene(reScene); 
		break;
	case 2:
        CCAction* popupLayer = CCSequence::create(CCScaleTo::create(0.0f, 0.0f),
                                          CCScaleTo::create(0.06f, 1.05f),
                                          CCScaleTo::create(0.08f, 0.95f),
                                          CCScaleTo::create(0.08f, 1.0f), NULL);

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
	CCDirector::sharedDirector()->pushScene(reScene); 
}
