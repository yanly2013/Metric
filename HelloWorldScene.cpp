#include "HelloWorldScene.h"
#include "activeNode.h"
#include "squareNode.h"
#include "MetricFactory.h"
#include "metriclogic.h"
USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
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
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));
	
    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("bg.png");

    // position the sprite on the center of the screen
	pSprite->setScale(0.5f);               // 精灵的缩放
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

    

	pMetric = CCSprite::create("metric.png");
    // position the sprite on the center of the screen
    pMetric->setScale(0.5f);               // 精灵的缩放
    //pMetric->setPosition(ccp(30, 600));
    // add the sprite as a child to this layer
    this->addChild(pMetric, 0);
	pMetric1 = CCSprite::create("metric.png");
    // position the sprite on the center of the screen
    pMetric1->setScale(0.5f);               // 精灵的缩放
    //pMetric1->setPosition(ccp(30, 610));
    this->addChild(pMetric1, 0);
	//pactiveNode = new SquareNode();
	MetricFactory *factory = new MetricFactory();
	pactiveNode = factory->create(SQUARE);
	pactiveNode->init();
	
	this->schedule(schedule_selector(HelloWorld::updateGame), 1.0f);
	this->schedule(schedule_selector(HelloWorld::checkConflid), 0.1f);
	T_MetricNode *metricNode;
	MetricLogic *metriclogic = new MetricLogic();
	metriclogic->init();
	metricNode = metriclogic->getmetricnode();

	for (int i = 0; i< 2; i++)
	{
		for (int j = 0; j<10; j++)
		{
			CCSprite *spritenode = CCSprite::create("metric.png");
			spritenode->setPosition(ccp(metricNode->X, metricNode->Y));
			this->addChild(spritenode);
			metricNode++;
		}
	}

    return true;
}

void HelloWorld::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	CCTouch *touch = (CCTouch *)pTouches->anyObject();
	CCPoint point = touch->getLocation();
	CCLog("%.2f,%.2f",point.x,point.y);


	

	if (point.x < 60.0 && point.y < 60.0)
	{
		pactiveNode->moveLeft();
	}
}

void HelloWorld::updateGame(float f)
{
   
	pactiveNode->moveDown();
	//CCMoveTo *pmove = CCMoveTo::create(10.0f, ccp(30,200));
	//static int i=20;
	T_MetricNode* activenode = pactiveNode->getActiveNode();
	pMetric->setPosition(ccp(activenode->X, activenode->Y));
	
	activenode++;
	pMetric1->setPosition(ccp(activenode->X, activenode->Y));
	//i+=20;
	//pMetric->runAction(pmove);
}
void HelloWorld::checkConflid(float f)
{
	CCLog("123456");
}
void HelloWorld::menuCloseCallback(CCObject* pSender)
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
