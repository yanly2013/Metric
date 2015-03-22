#include "HelpScene.h"
#include "StartScene.h"
#include "DefScreenAdp.h"
USING_NS_CC;

CCScene* Help::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Help *layer = Help::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Help::init()
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


    CCSprite *item = CCSprite::create("helping.png");
    item->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	item->setScale(ScaleFactor);
	this->addChild(item,1);
	
    CCMenuItemImage *pokItem = CCMenuItemImage::create(  
                                  "returnbutton.png", //png.jpg等图片格式都是可以的  
                                  "returnbutton.png",  
                                    this,  
                                    menu_selector(Help::menuOKCallback));  	
    pokItem->setPosition(ccp(0,0));

	CCMenu* pOKMenu = CCMenu::create(pokItem, NULL);
	pOKMenu->setPosition(ccp(100,-100));
	pOKMenu->setScale(ScaleFactor);
	this->addChild(pOKMenu, 1);
    return true;
}

void  Help::menuOKCallback(CCObject* pSender)
{
    CCScene *pScene = Start::scene();

    CCTransitionFade *reScene = CCTransitionFade::create(1.0f, pScene);
    CCDirector::sharedDirector()->replaceScene(reScene); 
}