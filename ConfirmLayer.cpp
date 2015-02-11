#include "ConfirmLayer.h"

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

    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

        // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("bg.png");
	pSprite->setScale(0.5f);               // 精灵的缩放
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);
      CCLabelTTF *name = CCLabelTTF::create("返回游戏", "Arial", 34);
        name->setPosition(ccp(200, 100));
		this->addChild(name,2);
    CCMenuItemImage *pconfirmItem = CCMenuItemImage::create(
                                        "confirmbtn.png",
                                        "confirmbtn.png",
                                        this,
                                        menu_selector(ConfirmLayer::menuconfirmCallback));
    
	pconfirmItem->setPosition(ccp(0,0));

    pconfirmItem->setTag(1);
    CCMenuItemImage *pCancleItem = CCMenuItemImage::create(
                                        "canclebtn.png",
                                        "canclebtn.png",
                                        this,
                                        menu_selector(ConfirmLayer::menuconfirmCallback));
	pCancleItem->setPosition(ccp(100,0));
    pCancleItem->setTag(2);

    // create menu, it's an autorelease object
    CCMenu* pConfirmMenu = CCMenu::create(pconfirmItem, pCancleItem, NULL);
    pConfirmMenu->setPosition(ccp(0,0));
    this->addChild(pConfirmMenu, 1);
 

    return true;
}
void ConfirmLayer::menuconfirmCallback(CCObject* pSender)
{
	CCMenuItemToggle* item = (CCMenuItemToggle*)pSender;
	switch (item->getTag())
	{
	case 1:
		
		break;
	case 2:
        
		break;
	}
}
void ConfirmLayer::onEnter()
{
       CCLayer::onEnter();  
       //CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, kCCMenuTouchPriority - 1, true);  

}
bool ConfirmLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    m_bTouchedMenu = m_pMenu->ccTouchBegan(pTouch, pEvent);  
    return true; 
}
