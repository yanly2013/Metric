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

 
    pLabel->setString("change string");//修改文字的方法

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("bg.png");

    // position the sprite on the center of the screen
	pSprite->setScale(0.5f);               // 精灵的缩放
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
		deadSpriteNum = 0;
	createNextNode();
    ActivenextNode();
    this->removeChild(pnextMetric0);
	this->removeChild(pnextMetric1);
    this->removeChild(pnextMetric2);
    this->removeChild(pnextMetric3);
	createNextNode();
	//createNextNode();	
	this->schedule(schedule_selector(HelloWorld::updateGame), 0.5f);
	//this->schedule(schedule_selector(HelloWorld::checkConflid), 0.5f);

	metriclogic = new MetricLogic();
	metriclogic->init();
	displayMetric();

/*
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("test.plist");
	CCSpriteBatchNode * batchnode = CCSpriteBatchNode::create("test.png");
	this->addChild(batchnode);

	CCSpriteFrame *frame1 = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("back.png");
	CCSprite *sp11 = CCSprite::createWithSpriteFrame(frame1);
	sp11->setPosition(ccp(300,300));
	batchnode->addChild(sp11);

	CCSpriteFrame *frame2 = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("backorange.png");
	CCSprite *sp21 = CCSprite::createWithSpriteFrame(frame2);
	sp21->setPosition(ccp(300,400));
	batchnode->addChild(sp21);
	*/
    return true;
}

void HelloWorld::displayMetric()
{
	T_MetricNode *metricNode;
	metriclogic->dismissLine();
	metricNode = metriclogic->getmetricnode();
	for (int i = 0; i < deadSpriteNum; i++)
	{
		this->removeChild(pNodeSprite[i]);


	}
	deadSpriteNum = 0;
	for (int i = 0; i< 10; i++)
	{
		for (int j = 0; j<24; j++)
		{

			if (metricNode->number < 10)
			{
                CCSprite *spritenode = CCSprite::create("nodered.png");
				pNodeSprite[deadSpriteNum] = spritenode;
				deadSpriteNum++;
			    spritenode->setScale(0.5f); 
			    spritenode->setPosition(ccp(XLogictoPhysic[metricNode->X], YLogictoPhysic[metricNode->Y]));
			    this->addChild(spritenode);
			}
			metricNode++;
		}
	}
}
void HelloWorld::createNextNode()
{
	factory = new MetricFactory();
	NodeType nodetype = createNodeType();
    m_nexttype = nodetype;
    pnextactiveNode = factory->create(m_nexttype);
	pnextactiveNode->initnext();
	
	T_MetricNode* nextactivenode = pnextactiveNode->getActiveNode();
	pnextMetric0 = CCSprite::create("nodegreen.png");
    // position the sprite on the center of the screen
    pnextMetric0->setScale(0.5f);               // 精灵的缩放
	pnextMetric0->setPosition(ccp(nextactivenode[0].X, nextactivenode[0].Y));
    // add the sprite as a child to this layer
    this->addChild(pnextMetric0, 0);
    pnextMetric1 = CCSprite::create("nodeyellow.png");
    // position the sprite on the center of the screen
    pnextMetric1->setScale(0.5f);               // 精灵的缩放
	pnextMetric1->setPosition(ccp(nextactivenode[1].X, nextactivenode[1].Y));
    // add the sprite as a child to this layer
    this->addChild(pnextMetric1, 0);
    pnextMetric2 = CCSprite::create("nodeyellow.png");
    // position the sprite on the center of the screen
    pnextMetric2->setScale(0.5f);               // 精灵的缩放
	pnextMetric2->setPosition(ccp(nextactivenode[2].X, nextactivenode[2].Y));
    // add the sprite as a child to this layer
    this->addChild(pnextMetric2, 0);
    pnextMetric3 = CCSprite::create("nodepurple.png");
    // position the sprite on the center of the screen
    pnextMetric3->setScale(0.5f);               // 精灵的缩放
	pnextMetric3->setPosition(ccp(nextactivenode[3].X, nextactivenode[3].Y));
    // add the sprite as a child to this layer
    this->addChild(pnextMetric3, 0);

}
NodeType HelloWorld::createNodeType()
{
		cc_timeval psv;   
CCTime::gettimeofdayCocos2d( &psv, NULL );    // 计算时间种子   
unsigned int tsrans = psv.tv_sec * 1000 + psv.tv_usec / 1000;    // 初始化随机数   
srand( tsrans ); 
 int i = CCRANDOM_0_1() * 100;

 if (i >= 0 && i < 5)
 {
	 return LINE;
 }
 else if (i >= 5 && i< 15)
 {
	 return SQUARE;
 }
  else if (i >= 15 && i< 35)
 {
	 return THREEONE;
 }
  else if (i >= 35 && i< 55)
 {
	 return ONETHREE;
 }
   else if (i >= 55 && i< 75)
 {
	 return TWOTWOLEFT;
 }
   else if (i >= 75 && i< 95)
 {
	 return TWOTWORIGHT;
 }
    else if (i >= 95 && i<=100)
 {
	 return TTYPE;
 }

}
void HelloWorld::ActivenextNode()
{
		//pactiveNode = new SquareNode();
	//MetricFactory *factory = new MetricFactory();


   m_activetype = m_nexttype;

	pactiveNode = factory->create(m_activetype);
	//pactiveNode = factory->create(SQUARE);
	pactiveNode->init();

	pMetric0 = CCSprite::create("nodeblue.png"); //改为从next中判断创建正确的精灵
    // position the sprite on the center of the screen
    pMetric0->setScale(0.5f);               // 精灵的缩放
    //pMetric->setPosition(ccp(30, 600));
    // add the sprite as a child to this layer
    this->addChild(pMetric0, 0);
	pMetric1 = CCSprite::create("nodegreen.png");
    // position the sprite on the center of the screen
    pMetric1->setScale(0.5f);               // 精灵的缩放
    //pMetric1->setPosition(ccp(30, 610));
    this->addChild(pMetric1, 0);
    pMetric2 = CCSprite::create("nodeyellow.png");
    // position the sprite on the center of the screen
    pMetric2->setScale(0.5f);               // 精灵的缩放
    //pMetric->setPosition(ccp(30, 600));
    // add the sprite as a child to this layer
    this->addChild(pMetric2, 0);
	pMetric3 = CCSprite::create("nodepurple.png");
    // position the sprite on the center of the screen
    pMetric3->setScale(0.5f);               // 精灵的缩放
    //pMetric1->setPosition(ccp(30, 610));
    this->addChild(pMetric3, 0);	


}
void HelloWorld::destroyActiveNode()
{
	this->removeChild(pMetric0);
	this->removeChild(pMetric1);
    this->removeChild(pMetric2);
    this->removeChild(pMetric3);
    this->removeChild(pnextMetric0);
	this->removeChild(pnextMetric1);
    this->removeChild(pnextMetric2);
    this->removeChild(pnextMetric3);
}

void HelloWorld::saveActiveNode(T_MetricNode activenode[])
{
	oldactivenode[0] = activenode[0];
	oldactivenode[1] = activenode[1];
    oldactivenode[2] = activenode[2];
	oldactivenode[3] = activenode[3];
}
void HelloWorld::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	CCTouch *touch = (CCTouch *)pTouches->anyObject();
	CCPoint point = touch->getLocation();
	CCLog("%.2f,%.2f",point.x,point.y);
	saveActiveNode(pactiveNode->getActiveNode());
	if (point.x < 90.0 && point.y < 90.0)
	{
		pactiveNode->moveLeft();
	}
	else if (point.x < 180.0 && point.y < 90.0)
	{
		pactiveNode->moveRight();
	}
	else if (point.x < 270.0 && point.y < 90.0)
	{
		pactiveNode->rotate();
	}
	else if (point.x < 360.0 && point.y < 90.0)
	{
		pactiveNode->moveDown();
	}
	else if (point.x > 270.0 && point.x < 360.0 && point.y < 180.0 && point.y > 90.0)
	{
		while (1)
		{
			pactiveNode->moveDown();
			if (checkConflid())
			{
				return;
			}
			saveActiveNode(pactiveNode->getActiveNode());
		};
	}

	checkConflid();
}

void HelloWorld::updateGame(float f)
{
    saveActiveNode(pactiveNode->getActiveNode());
	pactiveNode->moveDown();
	checkConflid();
	//CCMoveTo *pmove = CCMoveTo::create(10.0f, ccp(30,200));
	//static int i=20;
	T_MetricNode* activenode = pactiveNode->getActiveNode();
	pMetric0->setPosition(ccp(XLogictoPhysic[activenode->X], YLogictoPhysic[activenode->Y]));
	
	activenode++;
	pMetric1->setPosition(ccp(XLogictoPhysic[activenode->X], YLogictoPhysic[activenode->Y]));

	activenode++;
	pMetric2->setPosition(ccp(XLogictoPhysic[activenode->X], YLogictoPhysic[activenode->Y]));

	activenode++;
	pMetric3->setPosition(ccp(XLogictoPhysic[activenode->X], YLogictoPhysic[activenode->Y]));
	//i+=20;
	//pMetric->runAction(pmove);
}
bool HelloWorld::checkConflid()
{
	CCLog("123456");
	static int i = 10;
	i++;
    T_MetricNode* activenode = pactiveNode->getActiveNode();
    T_MetricNode *metricNode = metriclogic->getmetricnode();
	T_MetricNode tempnode[24][10];
	memcpy(&tempnode, metricNode, sizeof(tempnode));
	unsigned char *toppos = metriclogic->getmaxposition();
	int flag = 0;
	for (int i = 0; i< 4; i++)
	{
		for (int j = 0; j< 10; j++)
		{
			for (int k = toppos[j]-1; k >= 0; k--)
			{
				if ((activenode[i].Y==65535) || (activenode[i].X == tempnode[k][j].X && activenode[i].Y == tempnode[k][j].Y && tempnode[k][j].number < 10))
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				break;
			}
		}
        if (flag == 1)
        {
            break;
        }
	}


	if (flag ==1)
	{
		metriclogic->addnewNode(oldactivenode);
        displayMetric();
		destroyActiveNode();
	    ActivenextNode();
		createNextNode();
		return true;
	}
	else
	{
		return false;
	}
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
