#include "RatingScene.h"
#include "StartScene.h"

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

    for (int i = 0; i< 5; i++)
    {
        CCSprite *item = CCSprite::create("item.png");
		item->setPosition(ccp(0, 100*i));
		this->addChild(item,1);
        char a[10];  
	    sprintf(a, "%d", i+1);
        CCLabelAtlas *ratingnum = CCLabelAtlas::create(a, "ratingnumber.png", 14, 21, '0');
		ratingnum->setPosition(ccp(0, 100 * i));
		this->addChild(ratingnum,2);
		sprintf(a, "name:%d", i);
        CCLabelTTF *name = CCLabelTTF::create(a, "Arial", 24);
        name->setPosition(ccp(200, 100 * i));
		this->addChild(ratingnum,2);
		
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

    CCTransitionPageTurn *reScene = CCTransitionPageTurn::create(2.0f, pScene, false);
    CCDirector::sharedDirector()->replaceScene(reScene); 
}