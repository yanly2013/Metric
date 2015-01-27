#include "WelcomeScene.h"
#include "StartScene.h"

USING_NS_CC;

CCScene* Welcome::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Welcome *layer = Welcome::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Welcome::init()
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
	pSprite->setScale(0.5f);               // ¾«ÁéµÄËõ·Å
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);

    // wait for 3 seconds

	// jump to start scene
    CCScene *pScene = Start::scene();
    //CCTransitionPageTurn *reScene = CCTransitionPageTurn::create(2.0f, pScene, false);
    CCDirector::sharedDirector()->replaceScene(pScene); 
 
    return true;
}