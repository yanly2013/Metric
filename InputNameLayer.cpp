#include "InputNameLayer.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool InputNameLayer::init()
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
    CCSprite* pSprite = CCSprite::create("welcome.png");
	pSprite->setScale(0.5f);               // 精灵的缩放
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);

    CCSprite* pTitle = CCSprite::create("title.png");
	pTitle->setScale(0.5f);               // 精灵的缩放
    pTitle->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + 200));
    this->addChild(pTitle, 0);


    //this->schedule(schedule_selector(Welcome::updateGame), 0.3f);
	// jump to start scene
    //CCScene *pScene = Start::scene();
    //CCTransitionPageTurn *reScene = CCTransitionPageTurn::create(2.0f, pScene, false);
    //CCDirector::sharedDirector()->replaceScene(pScene); 
 
    return true;
}

void InputNameLayer::onEnter()
{
       CCLayer::onEnter();  
       //CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, kCCMenuTouchPriority - 1, true);  

}
bool InputNameLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    m_bTouchedMenu = m_pMenu->ccTouchBegan(pTouch, pEvent);  
    return true; 
}
