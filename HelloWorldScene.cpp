#include "HelloWorldScene.h"
#include "SettingScene.h"
#include "activeNode.h"
#include "squareNode.h"
#include "MetricFactory.h"
#include "metriclogic.h"
#include "SaveData.h"
#include "RatingScene.h"
#include "ConfirmLayer.h"
#include "SimpleAudioEngine.h"
//#include "CCFileUtilsWin32.h"
#include "EnterNameLayer.h"
#include "DefScreenAdp.h"
#include "GameOverLayer.h"

USING_NS_CC;
using namespace CocosDenshion;

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
    // 3. add your codes below...
    cc_timeval psv;   
    CCTime::gettimeofdayCocos2d( &psv, NULL );    // 计算时间种子   
    unsigned int tsrans = psv.tv_sec * 1000 + psv.tv_usec / 1000;    // 初始化随机数   
    srand( tsrans ); 

    SaveData::getInstant()->readNameandScore();
	SaveData::getInstant()->readSetting();
	
    CCSprite* pSprite = CCSprite::create("bg.png");
	pSprite->setScale(ScaleFactor);               // 精灵的缩放
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
	pButtonMenu->setScale(ScaleFactor);
	this->addChild(pButtonMenu, 1);

	//CCLabelAtlas* diceCount = CCLabelAtlas::create("1", "number.png", 14, 21, '0');
    pLabellevel = CCLabelAtlas::create("1", "number.png", 14, 21, '0');
    pLabelscore = CCLabelAtlas::create("1", "number.png", 14, 21, '0');
    pLabelline = CCLabelAtlas::create("1", "number.png", 14, 21, '0');
    pLabellevel->setPosition(ccp(295, 410));
    this->addChild(pLabellevel, 1);
    pLabellevel->setString("1");//修改文字的方法


    pLabelscore->setPosition(ccp(295, 330));
	this->addChild(pLabelscore, 1);
	pLabelscore->setString("0");


    pLabelline->setPosition(ccp(295, 250));
	this->addChild(pLabelline, 1);
	pLabelline->setString("0");

    CCMenuItemImage *ppauseItem = CCMenuItemImage::create(  
                                  "pause.png", //png.jpg等图片格式都是可以的  
                                  "pauselight.png");  
    CCMenuItemImage *presumeItem = CCMenuItemImage::create(  
                                  "pause.png", //png.jpg等图片格式都是可以的  
                                  "pauselight.png"); 
    CCMenuItemToggle *toggle = CCMenuItemToggle::createWithTarget(this, menu_selector(HelloWorld::menuPauseCallback),ppauseItem, presumeItem, NULL);
    CCMenu* pPauseMenu = CCMenu::create(toggle, NULL);
	pPauseMenu->setPosition(ccp(220,450));
	pPauseMenu->setScale(ScaleFactor);
	this->addChild(pPauseMenu, 1);

    deadSpriteNum = 0;
	level = 0;
	score = 0;
	line = 0;
	pauseflg = false;

	createNextNode();
    ActivenextNode();
    batchnode->removeChild(pnextMetric0, true);
	batchnode->removeChild(pnextMetric1, true);
    batchnode->removeChild(pnextMetric2, true);
    batchnode->removeChild(pnextMetric3, true);
	createNextNode();

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
	// 保存当前场景图
//得到窗口的大小  
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();  
    CCRenderTexture *renderTexture = CCRenderTexture::create(visibleSize.width,visibleSize.height);  
   
    //遍历当前类的所有子节点信息，画入renderTexture中。  
    //这里类似截图。  
    renderTexture->begin();   
    this->getParent()->visit();  
    renderTexture->end();  
   
    //将游戏界面暂停，压入场景堆栈。并切换到GamePause界面  
    CCDirector::sharedDirector()->pushScene(ConfirmLayer::scene(renderTexture));  

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
      level = metriclogic->getLevel();
      char a[10];  
	  sprintf(a, "%d", level);
      pLabellevel->setString(a);
      this->schedule(schedule_selector(HelloWorld::updateGame), leveltotime[level]);
   }
   if (score != metriclogic->getScore())
   {
      score = metriclogic->getScore();
	  char b[10];  
	  sprintf(b, "%d", score);
      pLabelscore->setString(b);
   }
   if (line != metriclogic->getLine())
   {
      line = metriclogic->getLine();
	  char c[10];  
	  sprintf(c, "%d", line);
      pLabelline->setString(c);
   }
}
void HelloWorld::displayMetric()
{
	T_MetricNode *metricNode = NULL;


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
			    spritenode->setScale(ScaleFactor); 
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
    pnextMetric0->setScale(ScaleFactor);
	pnextMetric0->setPosition(ccp(nextactivenode[0].X, nextactivenode[0].Y));
    batchnode->addChild(pnextMetric0, 0);

	pnextMetric1 = CCSprite::createWithSpriteFrame(frame1);
    pnextMetric1->setScale(ScaleFactor);
	pnextMetric1->setPosition(ccp(nextactivenode[1].X, nextactivenode[1].Y));
    batchnode->addChild(pnextMetric1, 0);

	pnextMetric2 = CCSprite::createWithSpriteFrame(frame1);
    pnextMetric2->setScale(ScaleFactor);
	pnextMetric2->setPosition(ccp(nextactivenode[2].X, nextactivenode[2].Y));
    batchnode->addChild(pnextMetric2, 0);

	pnextMetric3 = CCSprite::createWithSpriteFrame(frame1);
    pnextMetric3->setScale(ScaleFactor); 
	pnextMetric3->setPosition(ccp(nextactivenode[3].X, nextactivenode[3].Y));
    batchnode->addChild(pnextMetric3, 0);

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
 {
     return LINE;
  }

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
	pMetric0 = CCSprite::createWithSpriteFrame(frame0); //改为从next中判断创建正确的精灵
    pMetric0->setScale(ScaleFactor);
    batchnode->addChild(pMetric0, 0);

	pNode++;
	CCSpriteFrame *frame1 = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(SpriteNodeName[m_nodecolor][pNode->number]);
	pMetric1 = CCSprite::createWithSpriteFrame(frame1); 
    pMetric1->setScale(ScaleFactor);
    batchnode->addChild(pMetric1, 0);

	pNode++;
	CCSpriteFrame *frame2 = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(SpriteNodeName[m_nodecolor][pNode->number]);
    pMetric2 = CCSprite::createWithSpriteFrame(frame2); 
    pMetric2->setScale(ScaleFactor);
    batchnode->addChild(pMetric2, 0);
	pNode++;
	
    CCSpriteFrame *frame3 = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(SpriteNodeName[m_nodecolor][pNode->number]);
	pMetric3 = CCSprite::createWithSpriteFrame(frame3); 
    pMetric3->setScale(ScaleFactor);
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
#if 0
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
#endif

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

void HelloWorld::dismissLineShow()
{
    unsigned int *line = metriclogic->getdismissline();
	int count = 0;
	while (*line < 30)
	{   
		this->removeChild(pdismissline);
        pdismissline = CCSprite::create("dismissline.png");
		pdismissline->setScale(ScaleFactor);
		pdismissline->setPosition(ccp(135,YLogictoPhysic[*line]));
		this->addChild(pdismissline);
	    CCActionInterval * blinkline = CCBlink::create(0.5f,4);
		CCActionInterval * fadeline = CCFadeOut::create(0.5f);
		CCSpawn *spawnline = CCSpawn::create(blinkline, fadeline, NULL);
        pdismissline->runAction(spawnline);
		count++;
	    line++;
	};
    CCActionInterval * blink = CCMoveTo::create(1.0f,ccp(200, 400));
    CCActionInterval * fade = CCFadeOut::create(1.0f);
    CCSpawn *spawn = CCSpawn::create(blink, fade, NULL);
	this->removeChild(pgood);//清除上次的
	switch (count)
	{
	case 1:
        pgood = CCSprite::create("good.png");
		break;
	case 2:
		pgood = CCSprite::create("excllent.png");
		break;
	case 3:
		pgood = CCSprite::create("wonderful.png");
		break;
	default:
		pgood = CCSprite::create("wonderful.png");
		break;
	}
	if (count>0)
	{
		this->addChild(pgood);
        pgood->setPosition(ccp(200, 300));
        pgood->runAction(spawn);

	    if (SaveData::getInstant()->IsSound())
	    {
            //SimpleAudioEngine::sharedEngine()->playEffect(std::string(CCFileUtils::sharedFileUtils()->fullPathFromRelativeFile("Speech.wav")).c_str(), true);
	    }
		metriclogic->memsetdismisscount();
	}
	
}
void HelloWorld::gameOverShow()
{
	// 保存当前场景图
//得到窗口的大小  
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();  
    CCRenderTexture *renderTexture = CCRenderTexture::create(visibleSize.width,visibleSize.height);  
   
    //遍历当前类的所有子节点信息，画入renderTexture中。  
    //这里类似截图。  
    renderTexture->begin();   
    this->getParent()->visit();  
    renderTexture->end();  
   
    //将游戏界面暂停，压入场景堆栈。并切换到GamePause界面  
	CCDirector::sharedDirector()->pushScene(EnterNameLayer::scene(renderTexture, metriclogic->getScore()));  
}

