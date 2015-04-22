#include "EnterNameLayer.h"
#include "RatingScene.h"
#include "SaveData.h"
#include "DefScreenAdp.h"
USING_NS_CC;
unsigned int EnterNameLayer::m_score = 0;
CCScene* EnterNameLayer::scene(CCRenderTexture* sqr, unsigned int score)  
{  
 	m_score = score;  
    CCScene *scene = CCScene::create();  
    EnterNameLayer *layer = EnterNameLayer::create();  
     scene->addChild(layer,1);  
      //���Ӳ��֣�ʹ��Game�����н�ͼ��sqr����ͼƬ����Sprite  
    //����Sprite��ӵ�GamePause��������  
    //�õ����ڵĴ�С  
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();  
    CCSprite *back_spr = CCSprite::createWithTexture(sqr->getSprite()->getTexture());    
    back_spr->setPosition(ccp(visibleSize.width/2,visibleSize.height/2)); //����λ��,������������λ�á�  
    back_spr->setFlipY(true);            //��ת����ΪUI�����OpenGL���겻ͬ  
    back_spr->setColor(cocos2d::ccGRAY); //ͼƬ��ɫ���ɫ  
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
	pSprite->setScale(ScaleFactor);               // ���������
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
    this->addChild(textField); 
    //�󶨽ӿ�
    textField->setDelegate(this);
    //��������
    textField->attachWithIME();
    //�ر�����
    //textField->detachWithIME();


    CCMenuItemImage *pcontinueItem = CCMenuItemImage::create(
                                        "confirmbtn.png",
                                        "confirmbtnclick.png",
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
        SaveData::getInstant()->addaNameandScore((char *)textField->getString(), m_score);
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

//���û������������ʱ�Ļص�����
bool EnterNameLayer::onTextFieldAttachWithIME(CCTextFieldTTF *pSender)
{
CCLOG("��������");
return false;
//return true:������
}
//���û��ر��������ʱ�Ļص�����
bool EnterNameLayer::onTextFieldDetachWithIME(CCTextFieldTTF *pSender)
{
CCLOG("�ر�����");
return false;
//return true:���ر�
}
//���û���������ʱ�Ļص�����
bool EnterNameLayer::onTextFieldInsertText(CCTextFieldTTF *pSender,const char *text,int nLen)
{
CCLOG("�����ַ�...");
return false;
//return true:����������ַ�

}
//���û�ɾ������ʱ�Ļص�����
bool EnterNameLayer::onTextFieldDeleteBackward(CCTextFieldTTF *pSender,const char *delText,int nLen)
{
CCLOG("ɾ���ַ�");
return false;
//return true:��ɾ��
}


