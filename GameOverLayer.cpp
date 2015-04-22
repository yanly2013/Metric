#include "GameOverLayer.h"
#include "StartScene.h"
#include "DefScreenAdp.h"
USING_NS_CC;

// on "init" you need to initialize your instance
bool GameOverLayer::init()
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
    CCSprite* pSprite = CCSprite::create("exitmenu.png");
	pSprite->setScale(ScaleFactor);               // ¾«ÁéµÄËõ·Å
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);
    CCLabelTTF *name = CCLabelTTF::create("Game Over", "Arial", 30);
		name->setColor(ccc3(126, 126, 126));
        name->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
		this->addChild(name,2);
    CCMenuItemImage *pcontinueItem = CCMenuItemImage::create(
                                        "confirmbtn.png",
                                        "confirmbtnclick.png",
                                        this,
                                        menu_selector(GameOverLayer::menuconfirmCallback));
    pcontinueItem->setPosition(ccp(0,0));
    pcontinueItem->setTag(1);



    // create menu, it's an autorelease object
    CCMenu* pConfirmMenu = CCMenu::create(pcontinueItem, NULL);
    pConfirmMenu->setPosition(ccp(0,0));
    this->addChild(pConfirmMenu, 1);
 

    return true;
}
void GameOverLayer::menuconfirmCallback(CCObject* pSender)
{
	CCMenuItemToggle* item = (CCMenuItemToggle*)pSender;
	switch (item->getTag())
	{
	case 1:
        CCScene *pScene = Start::scene();

        CCTransitionFade *reScene = CCTransitionFade::create(1.0f, pScene);
        CCDirector::sharedDirector()->replaceScene(reScene); 
		break;

	}
}
void GameOverLayer::onEnter()
{
       CCLayer::onEnter();  
       //CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, kCCMenuTouchPriority - 1, true);  

}
bool GameOverLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    m_bTouchedMenu = m_pMenu->ccTouchBegan(pTouch, pEvent);  
    return true; 
}
void GameOverLayer::registerWithTouchDispatcher(void)
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -128, true);
}