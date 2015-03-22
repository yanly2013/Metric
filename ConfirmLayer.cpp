#include "ConfirmLayer.h"
#include "StartScene.h"
#include "SettingScene.h"
#include "DefScreenAdp.h"
USING_NS_CC;

// on "init" you need to initialize your instance
bool ConfirmLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
	setTouchEnabled(true);
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

        // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("pausemenu.png");
	pSprite->setScale(ScaleFactor);               // ¾«ÁéµÄËõ·Å
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);

    CCMenuItemImage *pcontinueItem = CCMenuItemImage::create(
                                        "continuebtn.png",
                                        "continuebtn.png",
                                        this,
                                        menu_selector(ConfirmLayer::menuconfirmCallback));
    pcontinueItem->setPosition(ccp(visibleSize.width/2,400));
	pcontinueItem->setScale(ScaleFactor);
    pcontinueItem->setTag(1);

	CCMenuItemImage *pmainmenuItem = CCMenuItemImage::create(
                                        "mainmenubtn.png",
                                        "mainmenubtn.png",
                                        this,
                                        menu_selector(ConfirmLayer::menuconfirmCallback));
	pmainmenuItem->setPosition(ccp(visibleSize.width/2,320));
	pmainmenuItem->setScale(ScaleFactor);
    pmainmenuItem->setTag(2);

    CCMenuItemImage *psettingmenuItem = CCMenuItemImage::create(
                                        "settingmenubtn.png",
                                        "settingmenubtn.png",
                                        this,
                                        menu_selector(ConfirmLayer::menuconfirmCallback));
	psettingmenuItem->setPosition(ccp(visibleSize.width/2,240));
	psettingmenuItem->setScale(ScaleFactor);
    psettingmenuItem->setTag(3);
	
    // create menu, it's an autorelease object
    CCMenu* pConfirmMenu = CCMenu::create(pcontinueItem, pmainmenuItem, psettingmenuItem, NULL);
    pConfirmMenu->setPosition(ccp(0,0));
    this->addChild(pConfirmMenu, 1);
 

    return true;
}
void ConfirmLayer::menuconfirmCallback(CCObject* pSender)
{
	CCMenuItemToggle* item = (CCMenuItemToggle*)pSender;
	CCScene *pScene = NULL;
	switch (item->getTag())
	{
	case 1:
		
		break;
	case 2:
        pScene = Start::scene();
		break;
    case 3:
        pScene = Setting::scene();
		break;
	}
    CCTransitionFade *reScene = CCTransitionFade::create(1.0f, pScene);
    CCDirector::sharedDirector()->replaceScene(reScene); 
}
void ConfirmLayer::onEnter()
{
       CCLayer::onEnter();  
       //CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, kCCMenuTouchPriority - 1, true);  

}
bool ConfirmLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    //m_bTouchedMenu = m_pMenu->ccTouchBegan(pTouch, pEvent);  
    return true; 
}
void  ConfirmLayer::registerWithTouchDispatcher(void)
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -128, true);
}