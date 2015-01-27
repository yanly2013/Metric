#include "StartScene.h"

USING_NS_CC;

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

    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pStartItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(Start::menuCloseCallback));
    
	pStartItem->setPosition(ccp(origin.x + visibleSize.width - pStartItem->getContentSize().width/2 ,
                                origin.y + pStartItem->getContentSize().height/2));
    CCMenuItemImage *pContinueItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(Start::menuCloseCallback));
    
	pContinueItem->setPosition(ccp(origin.x + visibleSize.width - pContinueItem->getContentSize().width/2 ,
                                origin.y + pContinueItem->getContentSize().height/2));

	    CCMenuItemImage *pHelpItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(Start::menuCloseCallback));
    
	pHelpItem->setPosition(ccp(origin.x + visibleSize.width - pHelpItem->getContentSize().width/2 ,
                                origin.y + pHelpItem->getContentSize().height/2));

	    CCMenuItemImage *pSettingItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(Start::menuCloseCallback));
    
	pSettingItem->setPosition(ccp(origin.x + visibleSize.width - pSettingItem->getContentSize().width/2 ,
                                origin.y + pSettingItem->getContentSize().height/2));


    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pStartItem, pContinueItem, pHelpItem, pSettingItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...
 
    return true;
}

void Start::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}