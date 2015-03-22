#include "EnterNameLayer.h"
#include "RatingScene.h"
#include "SaveData.h"
#include "DefScreenAdp.h"
USING_NS_CC;

// on "init" you need to initialize your instance
bool EnterNameLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
	setTouchEnabled(true);
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

        // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("exitmenu.png");
	pSprite->setScale(ScaleFactor);               // 精灵的缩放
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);
    CCLabelTTF *name = CCLabelTTF::create("Enter your name", "Arial", 26);
		name->setColor(ccc3(126, 126, 126));
        name->setPosition(ccp(visibleSize.width/2, visibleSize.height/2+50));
		this->addChild(name,2);

    CCSize size=CCDirector::sharedDirector()->getWinSize();
    textField = CCTextFieldTTF::textFieldWithPlaceHolder("Input...", "Arial", 24);
    textField->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    this->addChild(textField); 
    //绑定接口
    textField->setDelegate(this);
    //开启输入
    textField->attachWithIME();
    //关闭输入
    //textField->detachWithIME();


    CCMenuItemImage *pcontinueItem = CCMenuItemImage::create(
                                        "confirmbtn.png",
                                        "confirmbtn.png",
                                        this,
                                        menu_selector(EnterNameLayer::menuconfirmCallback));
    pcontinueItem->setPosition(ccp(visibleSize.width/2,280));
	pcontinueItem->setScale(ScaleFactor);
    pcontinueItem->setTag(1);



    // create menu, it's an autorelease object
    CCMenu* pConfirmMenu = CCMenu::create(pcontinueItem, NULL);
    pConfirmMenu->setPosition(ccp(0,0));
    this->addChild(pConfirmMenu, 1);
 

    return true;
}
void EnterNameLayer::menuconfirmCallback(CCObject* pSender)
{
	CCMenuItemToggle* item = (CCMenuItemToggle*)pSender;
	switch (item->getTag())
	{
	case 1:
        //textField->getText();
        SaveData::getInstant()->addaNameandScore("yanly", 1000);
		SaveData::getInstant()->saveNameandScore();
		
        CCScene *pScene = Rating::scene();

        CCTransitionFade *reScene = CCTransitionFade::create(1.0f, pScene);
        CCDirector::sharedDirector()->replaceScene(reScene); 
		break;

	}
}
void EnterNameLayer::onEnter()
{
       CCLayer::onEnter();  
       //CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, kCCMenuTouchPriority - 1, true);  

}
bool EnterNameLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    //m_bTouchedMenu = m_pMenu->ccTouchBegan(pTouch, pEvent);  
    return true; 
}
void EnterNameLayer::registerWithTouchDispatcher(void)
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -128, true);
}

//当用户启动虚拟键盘时的回调函数
bool EnterNameLayer::onTextFieldAttachWithIME(CCTextFieldTTF *pSender)
{
CCLOG("启动输入");
return false;
//return true:不启动
}
//当用户关闭虚拟键盘时的回调函数
bool EnterNameLayer::onTextFieldDetachWithIME(CCTextFieldTTF *pSender)
{
CCLOG("关闭输入");
return false;
//return true:不关闭
}
//当用户进行输入时的回调函数
bool EnterNameLayer::onTextFieldInsertText(CCTextFieldTTF *pSender,const char *text,int nLen)
{
CCLOG("输入字符...");
return false;
//return true:不会输入进字符

}
//当用户删除文字时的回调函数
bool EnterNameLayer::onTextFieldDeleteBackward(CCTextFieldTTF *pSender,const char *delText,int nLen)
{
CCLOG("删除字符");
return false;
//return true:不删除
}


