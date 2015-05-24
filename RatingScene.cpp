#include "RatingScene.h"
#include "StartScene.h"
#include "SaveData.h"
#include "DefScreenAdp.h"
USING_NS_CC;

CCScene* Rating::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Rating *layer = Rating::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Rating::init()
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
    CCSprite* pSprite = CCSprite::create("ratting.png");
	pSprite->setScale(ScaleFactor);               // 精灵的缩放
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(pSprite, 0);
	
	CCMenuItemImage *pPrevItem = CCMenuItemImage::create(
                                        "prev.png",
                                        "prev.png",
                                        this,
                                        menu_selector(Rating::menumodeswitchCallback));
    
	pPrevItem->setPosition(ccp(0,0));

    pPrevItem->setTag(1);
    CCMenuItemImage *pBandItem = CCMenuItemImage::create(
                                        "rattingband.png",
                                        "rattingband.png",
                                        this,
                                        menu_selector(Rating::menumodeswitchCallback));
	pBandItem->setPosition(ccp(200,0));
    pBandItem->setTag(2);
    CCMenuItemImage *pNextItem = CCMenuItemImage::create(
                                        "next.png",
                                        "next.png",
                                        this,
                                        menu_selector(Rating::menumodeswitchCallback));
    
	pNextItem->setPosition(ccp(400,0));
    pNextItem->setTag(3);
    // create menu, it's an autorelease object
    CCMenu* pRattingModeMenu = CCMenu::create(pPrevItem, pBandItem, pNextItem, NULL);
	pRattingModeMenu->setPosition(ccp(-10, 380));
	pRattingModeMenu->setScale(ScaleFactor);//(0.2f);
    this->addChild(pRattingModeMenu, 1);

	m_gamemode = SaveData::getInstant()->getGamemode();
	showRatingband();

    CCMenuItemImage *pokItem = CCMenuItemImage::create(  
                                  "returnbutton.png", //png.jpg等图片格式都是可以的  
                                  "returnbuttonclick.png",  
                                    this,  
                                    menu_selector(Rating::menuOKCallback));  	
    pokItem->setPosition(ccp(0,0));

	CCMenu* pOKMenu = CCMenu::create(pokItem, NULL);
	pOKMenu->setPosition(ccp(100,-100));
	pOKMenu->setScale(ScaleFactor);
	this->addChild(pOKMenu, 1);
 
    return true;
}

void Rating::showRatingband()
{

	char* modename[] = {"rattingleisure.png", "rattingtime.png", "rattingcrazy.png"};
	CCSprite *pmodename = CCSprite::create(modename[m_gamemode]);
	pmodename->setPosition(ccp(180, 540));
	pmodename->setScale(ScaleFactor);
	this->addChild(pmodename,3);
    pprevname = pmodename;

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	SaveData::getInstant()->readNameandScore();
    for (int i = 0; i< 5; i++)
    {
        CCSprite *item = CCSprite::create("item.png");
		item->setPosition(ccp(visibleSize.width/2, item->getContentSize().height/2 *(6-i)));
		item->setScale(ScaleFactor);
		this->addChild(item,1);
        char a[50];  
	    sprintf(a, "%d", i);
        CCLabelAtlas *ratingnum = CCLabelAtlas::create(a, "ratingnumber.png", 86, 90, '0');
		ratingnum->setPosition(ccp(visibleSize.width/2-item->getContentSize().height+25, (item->getContentSize().height/2 *(6- i)) - 25));
		ratingnum->setScale(ScaleFactor);//(0.2f);
		this->addChild(ratingnum,2);
		std::string aname = SaveData::getInstant()->getName(i);
		if (0 == aname.compare("unkownnameunkownnameunkownnameunkownnameunkownnam"))
		{
			aname = "";
		}


        CCLabelTTF *name = CCLabelTTF::create(aname.c_str(), "Arial-BoldMT", 30);
		name->setColor(ccc3(255,140,0));
        name->setPosition(ccp(visibleSize.width/2-30, item->getContentSize().height/2 * (6-i)));
		this->addChild(name,2);
		pprevnameandscore[i*2]=name;
        int score = SaveData::getInstant()->getScore(i);
		sprintf(a, ":%d", score);
        CCLabelTTF *scores = CCLabelTTF::create(a, "Arial-BoldMT", 30);
		scores->setColor(ccc3(255,140,0));
        scores->setPosition(ccp(visibleSize.width/2+80, item->getContentSize().height/2 * (6-i)));
		this->addChild(scores,2);

		pprevnameandscore[i*2+1]=scores;
		
    }
}

void Rating::menumodeswitchCallback(CCObject* pSender)
{
	CCMenuItemImage* item = (CCMenuItemImage*)pSender;

	switch (item->getTag())
	{
	case 1:
		m_gamemode = (m_gamemode+3-1)%3;
		break;
	case 3:
		m_gamemode = (m_gamemode+1)%3;
		break;
	}
	this->removeChild(pprevname);
	for (int i = 0; i< 10; i++)
	{
		this->removeChild(pprevnameandscore[i]);
	}
	SaveData::getInstant()->saveGamemode(m_gamemode);
	showRatingband();


    
}
void  Rating::menuOKCallback(CCObject* pSender)
{
    CCScene *pScene = Start::scene();

    CCTransitionFade *reScene = CCTransitionFade::create(1.0f, pScene);
    CCDirector::sharedDirector()->replaceScene(reScene); 
}