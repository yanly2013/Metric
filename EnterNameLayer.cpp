#include "EnterNameLayer.h"
#include "RatingScene.h"
#include "SaveData.h"
#include "DefScreenAdp.h"
#include "StartScene.h"
USING_NS_CC;
unsigned int EnterNameLayer::m_score = 0;
CCScene* EnterNameLayer::scene(CCRenderTexture* sqr, unsigned int score)  
{  
 	m_score = score;  
    CCScene *scene = CCScene::create();  
    EnterNameLayer *layer = EnterNameLayer::create();  
     scene->addChild(layer,1);  
      //增加部分：使用Game界面中截图的sqr纹理图片创建Sprite  
    //并将Sprite添加到GamePause场景层中  
    //得到窗口的大小  
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();  
    CCSprite *back_spr = CCSprite::createWithTexture(sqr->getSprite()->getTexture());    
    back_spr->setPosition(ccp(visibleSize.width/2,visibleSize.height/2)); //放置位置,这个相对于中心位置。  
    back_spr->setFlipY(true);            //翻转，因为UI坐标和OpenGL坐标不同  
    back_spr->setColor(cocos2d::ccGRAY); //图片颜色变灰色  
    scene->addChild(back_spr);  

    return scene;  
} 
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
    CCSprite* pSprite = CCSprite::create("enternamemenu.png");
	pSprite->setScale(ScaleFactor);               // 精灵的缩放
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);
    /*CCLabelTTF *name = CCLabelTTF::create("Enter your name", "Arial", 26);
		name->setColor(ccc3(126, 126, 126));
        name->setPosition(ccp(visibleSize.width/2, visibleSize.height/2+50));
		this->addChild(name,2);
*/
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    textField = CCTextFieldTTF::textFieldWithPlaceHolder("Input your ID", "Arial", 24);
    textField->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
	textField->setColor(ccc3(255,140,0));
    this->addChild(textField); 
    //绑定接口
    textField->setDelegate(this);
    //开启输入
    textField->attachWithIME();
    //关闭输入
    //textField->detachWithIME();


    CCMenuItemImage *pcontinueItem = CCMenuItemImage::create(
                                        "confirmbtn.png",
                                        "confirmbtnclick.png",
                                        this,
                                        menu_selector(EnterNameLayer::menuconfirmCallback));
    pcontinueItem->setPosition(ccp(visibleSize.width/2-50,280));
	pcontinueItem->setScale(ScaleFactor);
    pcontinueItem->setTag(1);

    CCMenuItemImage *pcancleItem = CCMenuItemImage::create(
                                        "canclebtn.png",
                                        "canclebtnclick.png",
                                        this,
                                        menu_selector(EnterNameLayer::menuconfirmCallback));
    pcancleItem->setPosition(ccp(visibleSize.width/2+50,280));
	pcancleItem->setScale(ScaleFactor);
    pcancleItem->setTag(2);

    // create menu, it's an autorelease object
    CCMenu* pConfirmMenu = CCMenu::create(pcontinueItem, pcancleItem, NULL);
    pConfirmMenu->setPosition(ccp(0,0));
    this->addChild(pConfirmMenu, 1);
 

    return true;
}
void EnterNameLayer::menuconfirmCallback(CCObject* pSender)
{
	CCMenuItemToggle* item = (CCMenuItemToggle*)pSender;
	CCTransitionFade *reScene = NULL;
	CCScene *pScene = NULL;
	char *p = NULL;
	switch (item->getTag())
	{
	case 1:
		char name[50];
		p =(char *) textField->getString();
		strcpy(&name[0], p);
		if (strlen(name) == 0)
		{
			SaveData::getInstant()->addaNameandScore((char*)"MyID", m_score);
		}
		else
		{
            SaveData::getInstant()->addaNameandScore((char *)textField->getString(), m_score);
		}

		SaveData::getInstant()->saveNameandScore();
		
        pScene = Rating::scene();

        reScene = CCTransitionFade::create(1.0f, pScene);
        CCDirector::sharedDirector()->replaceScene(reScene); 
		break;
	case 2:
		pScene = Start::scene();
		reScene = CCTransitionFade::create(1.0f, pScene);
        CCDirector::sharedDirector()->replaceScene(reScene); 
		break;
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


