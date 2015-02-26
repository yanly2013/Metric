#include "ExitLayer.h"
#include "StartScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;
// on "init" you need to initialize your instance
bool ExitLayer::init()
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
    CCSprite* pSprite = CCSprite::create("exitmenu.png");
	pSprite->setScale(0.5f);               // 精灵的缩放
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);
    CCLabelTTF *name = CCLabelTTF::create("确实要退出游戏吗?", "Arial", 30);
		name->setColor(ccc3(126, 126, 126));
        name->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
		this->addChild(name,2);
    CCMenuItemImage *pcontinueItem = CCMenuItemImage::create(
                                        "confirmbtn.png",
                                        "confirmbtn.png",
                                        this,
                                        menu_selector(ExitLayer::menuconfirmCallback));
    pcontinueItem->setPosition(ccp(0,0));
    pcontinueItem->setTag(1);

	CCMenuItemImage *pmainmenuItem = CCMenuItemImage::create(
                                        "canclebtn.png",
                                        "canclebtn.png",
                                        this,
                                        menu_selector(ExitLayer::menuconfirmCallback));
	pmainmenuItem->setPosition(ccp(200,0));
    pmainmenuItem->setTag(2);

    // create menu, it's an autorelease object
    CCMenu* pConfirmMenu = CCMenu::create(pcontinueItem, pmainmenuItem,NULL);
    pConfirmMenu->setPosition(ccp(0,0));
    this->addChild(pConfirmMenu, 1);
 

    return true;
}
void ExitLayer::menuconfirmCallback(CCObject* pSender)
{
	CCMenuItemToggle* item = (CCMenuItemToggle*)pSender;
	switch (item->getTag())
	{
	case 1:
		SimpleAudioEngine::sharedEngine()->end();
		CCDirector::sharedDirector()->end();
		break;
	case 2:
        CCScene *pScene = Start::scene();

        CCTransitionPageTurn *reScene = CCTransitionPageTurn::create(2.0f, pScene, false);
        CCDirector::sharedDirector()->replaceScene(reScene); 
		break;

	}
}
void ExitLayer::onEnter()
{
       CCLayer::onEnter();  
       //CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, kCCMenuTouchPriority - 1, true);  

}
bool ExitLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    m_bTouchedMenu = m_pMenu->ccTouchBegan(pTouch, pEvent);  
    return true; 
}
void  ExitLayer::registerWithTouchDispatcher(void)
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -128, true);
}
