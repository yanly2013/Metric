#include "RatingScene.h"
#include "StartScene.h"
#include "SaveData.h"

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
	pSprite->setScale(0.5f);               // 精灵的缩放
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(pSprite, 0);

    SaveData::getInstant()->readNameandScore();


	
    for (int i = 0; i< 5; i++)
    {
        CCSprite *item = CCSprite::create("item.png");
		item->setPosition(ccp(visibleSize.width/2, item->getContentSize().height/2 *(6-i)));
		item->setScale(0.5f);
		this->addChild(item,1);
        char a[10];  
	    sprintf(a, "%d", i);
        CCLabelAtlas *ratingnum = CCLabelAtlas::create(a, "ratingnumber.png", 216, 224, '0');
		ratingnum->setPosition(ccp(visibleSize.width/2-item->getContentSize().height+25, (item->getContentSize().height/2 *(6- i)) - 25));
		ratingnum->setScale(0.2f);
		this->addChild(ratingnum,2);
		std::string aname = SaveData::getInstant()->getName(i);
		sprintf(a, "name:%s", aname);
        CCLabelTTF *name = CCLabelTTF::create(a, "Arial", 30);
		name->setColor(ccc3(126, 126, 126));
        name->setPosition(ccp(visibleSize.width/2, item->getContentSize().height/2 * (6-i)));
		this->addChild(name,2);
        int score = SaveData::getInstant()->getScore(i);
		sprintf(a, ":%d", score);
        CCLabelTTF *scores = CCLabelTTF::create(a, "Arial", 30);
		scores->setColor(ccc3(126, 126, 126));
        scores->setPosition(ccp(visibleSize.width/2+100, item->getContentSize().height/2 * (6-i)));
		this->addChild(scores,2);
		
    }
    CCMenuItemImage *pokItem = CCMenuItemImage::create(  
                                  "returnbutton.png", //png.jpg等图片格式都是可以的  
                                  "returnbutton.png",  
                                    this,  
                                    menu_selector(Rating::menuOKCallback));  	
    pokItem->setPosition(ccp(0,0));

	CCMenu* pOKMenu = CCMenu::create(pokItem, NULL);
	pOKMenu->setPosition(ccp(100,-100));
	pOKMenu->setScale(0.5f);
	this->addChild(pOKMenu, 1);
 
    return true;
}

void  Rating::menuOKCallback(CCObject* pSender)
{
    CCScene *pScene = Start::scene();

    CCTransitionFade *reScene = CCTransitionFade::create(1.0f, pScene);
    CCDirector::sharedDirector()->replaceScene(reScene); 
}