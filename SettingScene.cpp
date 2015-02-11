#include "SettingScene.h"
#include "StartScene.h"
#include "SaveData.h"
USING_NS_CC;

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
	pSprite->setScale(0.5f);               // 精灵的缩放
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);
    CCMenuItemImage *pmusiconItem = CCMenuItemImage::create(  
                                  "musicon.png", //png.jpg等图片格式都是可以的  
                                  "musicon.png");  
    CCMenuItemImage *pmusicoffItem = CCMenuItemImage::create(  
                                  "musicoff.png", //png.jpg等图片格式都是可以的  
                                  "musicoff.png"); 
    CCMenuItemToggle *pmusictoggle = CCMenuItemToggle::createWithTarget(this, menu_selector(Setting::menuSettingCallback),pmusiconItem, pmusicoffItem, NULL);
    pmusictoggle->setTag(1);
	pmusictoggle->setPosition(ccp(0,400));
    CCMenuItemImage *psoundonItem = CCMenuItemImage::create(  
                                  "soundon.png", //png.jpg等图片格式都是可以的  
                                  "soundon.png");  
    CCMenuItemImage *psoundoffItem = CCMenuItemImage::create(  
                                  "soundoff.png", //png.jpg等图片格式都是可以的  
                                  "soundoff.png"); 
    CCMenuItemToggle *psoundtoggle = CCMenuItemToggle::createWithTarget(this, menu_selector(Setting::menuSettingCallback),psoundonItem, psoundoffItem, NULL);
    psoundtoggle->setTag(2);
	psoundtoggle->setPosition(ccp(0,200));
    CCMenuItemImage *pvibrateonItem = CCMenuItemImage::create(  
                                  "vibrateon.png", //png.jpg等图片格式都是可以的  
                                  "vibrateon.png");  
    CCMenuItemImage *pvibrateoffItem = CCMenuItemImage::create(  
                                  "vibrateoff.png", //png.jpg等图片格式都是可以的  
                                  "vibrateoff.png"); 
    CCMenuItemToggle *pvibratetoggle = CCMenuItemToggle::createWithTarget(this, menu_selector(Setting::menuSettingCallback),pvibrateonItem, pvibrateoffItem, NULL);
    pvibratetoggle->setTag(3);
	pvibratetoggle->setPosition(ccp(0,0));
	CCMenu* pSettingMenu = CCMenu::create(pmusictoggle, psoundtoggle, pvibratetoggle, NULL);
	pSettingMenu->setPosition(ccp(100,100));
	pSettingMenu->setScale(0.5f);
	this->addChild(pSettingMenu, 1);

	
    CCMenuItemImage *pokItem = CCMenuItemImage::create(  
                                  "returnbutton.png", //png.jpg等图片格式都是可以的  
                                  "returnbutton.png",  
                                    this,  
                                    menu_selector(Setting::menuOKCallback));  	
    pokItem->setPosition(ccp(0,0));

	CCMenu* pOKMenu = CCMenu::create(pokItem, NULL);
	pOKMenu->setPosition(ccp(100,-100));
	pOKMenu->setScale(0.5f);
	this->addChild(pOKMenu, 1);

    /////////////////////////////
    // 3. add your codes below...
 
    return true;
}
void Setting::menuSettingCallback(CCObject* pSender)
{
	CCMenuItemToggle* item = (CCMenuItemToggle*)pSender;
	switch (item->getTag())
	{
	case 1:
		isMusic ^= isMusic;
		break;
	case 2:
        isSound ^= isSound;
		break;
	case 3:
        isVibrate ^= isVibrate;
		break;
	}
}

void  Setting::menuOKCallback(CCObject* pSender)
{
    SaveData::getInstant()->saveSetting(isMusic, isSound, isVibrate);

    CCScene *pScene = Start::scene();

    CCTransitionPageTurn *reScene = CCTransitionPageTurn::create(2.0f, pScene, false);
    CCDirector::sharedDirector()->replaceScene(reScene); 
}
