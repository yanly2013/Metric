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
	pSprite->setScale(0.5f);               // 精灵的缩放
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);

    CCSprite* pTitle = CCSprite::create("title.png");
	pTitle->setScale(0.5f);               // 精灵的缩放
    pTitle->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + 200));
    this->addChild(pTitle, 0);

    pnode = CCSprite::create("welcomenode.png");
	pnode->setScale(0.5f);               // 精灵的缩放
    pnode->setPosition(ccp(visibleSize.width/2 + origin.x, 300));
    this->addChild(pnode, 0);
    // wait for 3 seconds
	rotatenum = 0;
    this->schedule(schedule_selector(Welcome::updateGame), 0.3f);
	// jump to start scene
    //CCScene *pScene = Start::scene();
    //CCTransitionPageTurn *reScene = CCTransitionPageTurn::create(2.0f, pScene, false);
    //CCDirector::sharedDirector()->replaceScene(pScene); 
 
    return true;
}

void  Welcome::updateGame(float f)
{
	CCActionInterval *forwardTo = NULL;
	switch (rotatenum)
	{
	case 0:
	    forwardTo = CCRotateTo::create(0.2, 90.0f);
	    pnode->runAction(forwardTo);
		rotatenum = 1;
		break;
	case 1:
	    forwardTo = CCRotateTo::create(0.2, 180.0f);
	    pnode->runAction(forwardTo);
		rotatenum = 2;
		break;
	case 2:
	    forwardTo = CCRotateTo::create(0.2, 270.0f);
	    pnode->runAction(forwardTo);
		rotatenum = 3;
		break;
	case 3:
	    forwardTo = CCRotateTo::create(0.2, 360.0f);
	    pnode->runAction(forwardTo);
		rotatenum = 0;
		break;
	}


}