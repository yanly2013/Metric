#include "HelloWorldScene.h"
#include "SettingScene.h"
#include "activeNode.h"
#include "squareNode.h"
#include "MetricFactory.h"
#include "metriclogic.h"
#include "SaveData.h"
#include "RatingScene.h"
#include "ConfirmLayer.h"
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
    cc_timeval psv;   
    CCTime::gettimeofdayCocos2d( &psv, NULL );    // 计算时间种子   
    unsigned int tsrans = psv.tv_sec * 1000 + psv.tv_usec / 1000;    // 初始化随机数   
    srand( tsrans ); 
    // add a label shows "Hello World"
    // create and initialize a label
   
    // position the label on the center of the screen
    //pLabellevel->setPosition(ccp(origin.x + visibleSize.width/2,
      //                      origin.y + visibleSize.height - pLabel->getContentSize().height));

	// add the label as a child to this layer

    SaveData::getInstant()->readNameandScore();
	SaveData::getInstant()->readSetting();
	
    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("bg.png");
	pSprite->setScale(0.5f);               // 精灵的缩放
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);

    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("metricnode.plist");
	batchnode = CCSpriteBatchNode::create("metricnode.png");
	this->addChild(batchnode);

    CCMenuItemImage *pleftarrowItem = CCMenuItemImage::create(  
                                  "leftarrow.png", //png.jpg等图片格式都是可以的  
                                  "leftarrowlight.png",  
                                    this,  
                                    menu_selector(HelloWorld::menuButtonCallback));  
    pleftarrowItem->setPosition(ccp(0,0));
	pleftarrowItem->setTag(1);
    CCMenuItemImage *prightarrowItem = CCMenuItemImage::create(  
                                  "rightarrow.png", //png.jpg等图片格式都是可以的  
                                  "rightarrowlight.png",  
                                    this,  
                                    menu_selector(HelloWorld::menuButtonCallback));  	
    prightarrowItem->setPosition(ccp(180,0));
	prightarrowItem->setTag(2);
    CCMenuItemImage *protateItem = CCMenuItemImage::create(  
                                  "rotate.png", //png.jpg等图片格式都是可以的  
                                  "rotatelight.png",  
                                    this,  
                                    menu_selector(HelloWorld::menuButtonCallback));  	
    protateItem->setPosition(ccp(360,0));
	protateItem->setTag(3);
    CCMenuItemImage *pdownItem = CCMenuItemImage::create(  
                                  "downarrow.png", //png.jpg等图片格式都是可以的  
                                  "downarrowlight.png",  
                                    this,  
                                    menu_selector(HelloWorld::menuButtonCallback));  	
    pdownItem->setPosition(ccp(540,0));
	pdownItem->setTag(4);
    CCMenuItemImage *pquickdownItem = CCMenuItemImage::create(  
                                  "quickdown.png", //png.jpg等图片格式都是可以的  
                                  "quickdownlight.png",  
                                    this,  
                                    menu_selector(HelloWorld::menuButtonCallback));  	
    pquickdownItem->setPosition(ccp(540,180));
	pquickdownItem->setTag(5);
	CCMenu* pButtonMenu = CCMenu::create(pleftarrowItem, prightarrowItem, protateItem, pdownItem, pquickdownItem, NULL);
	pButtonMenu->setPosition(ccp(-45,-90));
	pButtonMenu->setScale(0.5f);
	this->addChild(pButtonMenu, 1);

	//CCLabelAtlas* diceCount = CCLabelAtlas::create("1", "number.png", 14, 21, '0');
	   pLabellevel = CCLabelAtlas::create("1", "number.png", 14, 21, '0');
   pLabelscore = CCLabelAtlas::create("1", "number.png", 14, 21, '0');
   pLabelline = CCLabelAtlas::create("1", "number.png", 14, 21, '0');
     pLabellevel->setPosition(ccp(300, 350));
    this->addChild(pLabellevel, 1);
    pLabellevel->setString("1");//修改文字的方法


    pLabelscore->setPosition(ccp(300, 300));
	this->addChild(pLabelscore, 1);
	pLabelscore->setString("0");


    pLabelline->setPosition(ccp(300, 250));
	this->addChild(pLabelline, 1);
	pLabelline->setString("0");

    CCMenuItemImage *ppauseItem = CCMenuItemImage::create(  
                                  "pause.png", //png.jpg等图片格式都是可以的  
                                  "pause.png");  
    CCMenuItemImage *presumeItem = CCMenuItemImage::create(  
                                  "resume.png", //png.jpg等图片格式都是可以的  
                                  "resume.png"); 
    CCMenuItemToggle *toggle = CCMenuItemToggle::createWithTarget(this, menu_selector(HelloWorld::menuPauseCallback),ppauseItem, presumeItem, NULL);
    CCMenu* pPauseMenu = CCMenu::create(toggle, NULL);
	pPauseMenu->setPosition(ccp(250,400));
	pPauseMenu->setScale(0.5f);
	this->addChild(pPauseMenu, 1);

    deadSpriteNum = 0;
	level = 0;
	score = 0;
	line = 0;
	pauseflg = false;

	createNextNode();
    ActivenextNode();
    this->removeChild(pnextMetric0);
	this->removeChild(pnextMetric1);
    this->removeChild(pnextMetric2);
    this->removeChild(pnextMetric3);
	createNextNode();
	//createNextNode();	
	this->schedule(schedule_selector(HelloWorld::updateGame), 1.0f);
	this->schedule(schedule_selector(HelloWorld::updateScore), 0.1f);

	metriclogic = new MetricLogic();
	metriclogic->init();
	metriclogic->dismissLine();
	displayMetric();


/*
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
void HelloWorld::menuButtonCallback(CCObject* pSender)
{
	saveActiveNode(pactiveNode->getActiveNode());

	CCMenuItemImage* item = (CCMenuItemImage*)pSender;
	switch (item->getTag())
	{
	case 1:
		pactiveNode->moveLeft();
		break;
	case 2:
		pactiveNode->moveRight();
		break;
	case 3:
		pactiveNode->rotate();
        break;
	case 4:
		pactiveNode->moveDown();
        break;
	case 5:
		while (1)
		{
			pactiveNode->moveDown();
			if (checkConflid())
			{
				return;
			}
			saveActiveNode(pactiveNode->getActiveNode());
		};
		break;
	}
	checkConflid();
}
void HelloWorld::menuPauseCallback(CCObject* pSender)
{
		CCMenuItemImage* item = (CCMenuItemImage*)pSender;
		if (!pauseflg)
		{
		  //CCDirector::sharedDirector()->pause();
		
			CCAction* popupLayer = CCSequence::create(CCScaleTo::create(0.0, 0.0),
                                          CCScaleTo::create(0.06, 1.05),
                                          CCScaleTo::create(0.08, 0.95),
                                          CCScaleTo::create(0.08, 1.0), NULL);

         ConfirmLayer* confirmLayer = new ConfirmLayer();
		 confirmLayer->init();
		 confirmLayer->runAction(popupLayer);
         this->addChild(confirmLayer);
	
		  pauseflg = true;
		}
		else
		{
          CCDirector::sharedDirector()->resume();
		  pauseflg = false;
		}
}
void HelloWorld::updateGame(float f)
{
    saveActiveNode(pactiveNode->getActiveNode());
	pactiveNode->moveDown();
	checkConflid();
	dismissLineShow();
	
	T_MetricNode* activenode = pactiveNode->getActiveNode();
	pMetric0->setPosition(ccp(XLogictoPhysic[activenode->X], YLogictoPhysic[activenode->Y]));
	
	activenode++;
	pMetric1->setPosition(ccp(XLogictoPhysic[activenode->X], YLogictoPhysic[activenode->Y]));

	activenode++;
	pMetric2->setPosition(ccp(XLogictoPhysic[activenode->X], YLogictoPhysic[activenode->Y]));

	activenode++;
	pMetric3->setPosition(ccp(XLogictoPhysic[activenode->X], YLogictoPhysic[activenode->Y]));

}

void  HelloWorld::updateScore(float f)
{
   if (level != metriclogic->getLevel())
   {
      char a[10];  
	  sprintf(a, "%d", metriclogic->getLevel());
      pLabellevel->setString(a);
      // this->schedule(schedule_selector(HelloWorld::updateGame), 0.1f);
   }
   if (score != metriclogic->getScore())
   {
	  char b[10];  
	  sprintf(b, "%d", metriclogic->getScore());
      pLabelscore->setString(b);
   }
   if (line != metriclogic->getLine())
   {
	  char c[10];  
	  sprintf(c, "%d", metriclogic->getLine());
      pLabelline->setString(c);
   }
}
void HelloWorld::displayMetric()
{
	T_MetricNode *metricNode = NULL;
	//metriclogic->dismissLine();

	metricNode = metriclogic->getmetricnode();
	for (int i = 0; i < deadSpriteNum; i++)
	{
		batchnode->removeChild(pNodeSprite[i], true);
	}
	deadSpriteNum = 0;
	for (int i = 0; i< 10; i++)
	{
		for (int j = 0; j<24; j++)
		{

			if (metricNode->number < 10)
			{
				CCSpriteFrame *frame1 = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(SpriteNodeName[metricNode->color][metricNode->number]);
	            CCSprite *spritenode = CCSprite::createWithSpriteFrame(frame1); 
                //CCSprite *spritenode = CCSprite::create(SpriteNodeName[metricNode->color][metricNode->number]);
				pNodeSprite[deadSpriteNum] = spritenode;
				deadSpriteNum++;
			    spritenode->setScale(0.5f); 
			    spritenode->setPosition(ccp(XLogictoPhysic[metricNode->X], YLogictoPhysic[metricNode->Y]));
			    batchnode->addChild(spritenode);
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
    m_nodecolor = createNodeColor();
	pnextactiveNode->initnext(m_nodecolor);



    T_MetricNode* nextactivenode = pnextactiveNode->getActiveNode();
	CCSpriteFrame *frame1 = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(SpriteNodeName[m_nodecolor][10]);
	pnextMetric0 = CCSprite::createWithSpriteFrame(frame1);
    // position the sprite on the center of the screen
    pnextMetric0->setScale(0.5f);               // 精灵的缩放
	pnextMetric0->setPosition(ccp(nextactivenode[0].X, nextactivenode[0].Y));
    // add the sprite as a child to this layer
    batchnode->addChild(pnextMetric0, 0);
    pnextMetric1 = CCSprite::createWithSpriteFrame(frame1);
    // position the sprite on the center of the screen
    pnextMetric1->setScale(0.5f);               // 精灵的缩放
	pnextMetric1->setPosition(ccp(nextactivenode[1].X, nextactivenode[1].Y));
    // add the sprite as a child to this layer
    batchnode->addChild(pnextMetric1, 0);
    pnextMetric2 = CCSprite::createWithSpriteFrame(frame1);
    // position the sprite on the center of the screen
    pnextMetric2->setScale(0.5f);               // 精灵的缩放
	pnextMetric2->setPosition(ccp(nextactivenode[2].X, nextactivenode[2].Y));
    // add the sprite as a child to this layer
    batchnode->addChild(pnextMetric2, 0);
    pnextMetric3 = CCSprite::createWithSpriteFrame(frame1);
    // position the sprite on the center of the screen
    pnextMetric3->setScale(0.5f);               // 精灵的缩放
	pnextMetric3->setPosition(ccp(nextactivenode[3].X, nextactivenode[3].Y));
    // add the sprite as a child to this layer
    batchnode->addChild(pnextMetric3, 0);
/*

	T_MetricNode* nextactivenode = pnextactiveNode->getActiveNode();
	pnextMetric0 = CCSprite::create(SpriteNodeName[m_nodecolor][10]);
    // position the sprite on the center of the screen
    pnextMetric0->setScale(0.5f);               // 精灵的缩放
	pnextMetric0->setPosition(ccp(nextactivenode[0].X, nextactivenode[0].Y));
    // add the sprite as a child to this layer
    this->addChild(pnextMetric0, 0);
    pnextMetric1 = CCSprite::create(SpriteNodeName[m_nodecolor][10]);
    // position the sprite on the center of the screen
    pnextMetric1->setScale(0.5f);               // 精灵的缩放
	pnextMetric1->setPosition(ccp(nextactivenode[1].X, nextactivenode[1].Y));
    // add the sprite as a child to this layer
    this->addChild(pnextMetric1, 0);
    pnextMetric2 = CCSprite::create(SpriteNodeName[m_nodecolor][10]);
    // position the sprite on the center of the screen
    pnextMetric2->setScale(0.5f);               // 精灵的缩放
	pnextMetric2->setPosition(ccp(nextactivenode[2].X, nextactivenode[2].Y));
    // add the sprite as a child to this layer
    this->addChild(pnextMetric2, 0);
    pnextMetric3 = CCSprite::create(SpriteNodeName[m_nodecolor][10]);
    // position the sprite on the center of the screen
    pnextMetric3->setScale(0.5f);               // 精灵的缩放
	pnextMetric3->setPosition(ccp(nextactivenode[3].X, nextactivenode[3].Y));
    // add the sprite as a child to this layer
    this->addChild(pnextMetric3, 0);
*/
}
NodeType HelloWorld::createNodeType()
{

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
	else
	{return LINE;}

}
NodeColor HelloWorld::createNodeColor()
{
    int i = CCRANDOM_0_1() * 100;

    if (i >= 0 && i < 20)
    {
	     return RED;
    }
 else if (i >= 20 && i< 40)
 {
	 return BLUE;
 }
  else if (i >= 40 && i< 60)
 {
	 return YELLOW;
 }
  else if (i >= 60 && i< 80)
 {
	 return PURPLE;
 }
   else if (i >= 80 && i<= 100)
 {
	 return GREEN;
 }
   else
   {
	   return RED;
   }
}
void HelloWorld::ActivenextNode()
{
   m_activetype = m_nexttype;

	pactiveNode = factory->create(m_activetype);
	//pactiveNode = factory->create(TWOTWORIGHT);
	pactiveNode->init(m_nodecolor);
	T_MetricNode *pNode = pactiveNode->getActiveNode();

	CCSpriteFrame *frame0 = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(SpriteNodeName[m_nodecolor][pNode->number]);
	//pnextMetric0 = CCSprite::createWithSpriteFrame(frame1);

	pMetric0 = CCSprite::createWithSpriteFrame(frame0); //改为从next中判断创建正确的精灵
    // position the sprite on the center of the screen
    pMetric0->setScale(0.5f);               // 精灵的缩放
    //pMetric->setPosition(ccp(30, 600));
    // add the sprite as a child to this layer
    batchnode->addChild(pMetric0, 0);
	pNode++;
	CCSpriteFrame *frame1 = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(SpriteNodeName[m_nodecolor][pNode->number]);
	pMetric1 = CCSprite::createWithSpriteFrame(frame1); 
    // position the sprite on the center of the screen
    pMetric1->setScale(0.5f);               // 精灵的缩放
    //pMetric1->setPosition(ccp(30, 610));
    batchnode->addChild(pMetric1, 0);
	pNode++;
	CCSpriteFrame *frame2 = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(SpriteNodeName[m_nodecolor][pNode->number]);
    pMetric2 = CCSprite::createWithSpriteFrame(frame2); 
    // position the sprite on the center of the screen
    pMetric2->setScale(0.5f);               // 精灵的缩放
    //pMetric->setPosition(ccp(30, 600));
    // add the sprite as a child to this layer
    batchnode->addChild(pMetric2, 0);
	pNode++;
    CCSpriteFrame *frame3 = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(SpriteNodeName[m_nodecolor][pNode->number]);
	pMetric3 = CCSprite::createWithSpriteFrame(frame3); 
    // position the sprite on the center of the screen
    pMetric3->setScale(0.5f);               // 精灵的缩放
    //pMetric1->setPosition(ccp(30, 610));
    batchnode->addChild(pMetric3, 0);	


}
void HelloWorld::destroyActiveNode()
{
	batchnode->removeChild(pMetric0, true);
	batchnode->removeChild(pMetric1, true);
    batchnode->removeChild(pMetric2, true);
    batchnode->removeChild(pMetric3, true);
    batchnode->removeChild(pnextMetric0, true);
	batchnode->removeChild(pnextMetric1, true);
    batchnode->removeChild(pnextMetric2, true);
    batchnode->removeChild(pnextMetric3, true);
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
		
		CCScene *pScene = Setting::scene();
		CCTransitionPageTurn *reScene = CCTransitionPageTurn::create(2.0f, pScene, false);
		CCDirector::sharedDirector()->replaceScene(reScene); 

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
	else if (0)
	{
	    Pause();
	}

	checkConflid();
}


bool HelloWorld::checkConflid()
{
	//CCLog("123456");
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
		metriclogic->dismissLine();
		if (metriclogic->isGameover())
		{
		    gameOverShow();
		    return true;
		}
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
void HelloWorld::Pause()
{
    // 弹出一个层?
    // 调用Persistent 处理
    //Persistent *PersistentInst = Persistent::getInstant();
}
void HelloWorld::dismissLineShow()
{
    unsigned int *line = metriclogic->getdismissline();
	while (*line < 30)
	{
	    line++;
	};
}
void HelloWorld::gameOverShow()
{
		CCScene *pScene = Setting::scene();
		CCTransitionPageTurn *reScene = CCTransitionPageTurn::create(2.0f, pScene, false);
		CCDirector::sharedDirector()->replaceScene(reScene); 
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
