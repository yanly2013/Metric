#ifndef __ENTERNAME_LAYER_H__
#define __ENTERNAME_LAYER_H__

#include "cocos2d.h"


class EnterNameLayer : public cocos2d::CCLayer, public cocos2d::CCTextFieldDelegate
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
   // ��Ҫ��д����ע�ắ�������¸�����������
    virtual void registerWithTouchDispatcher(void);
    // ��д������������Զ���� true �����������㣬�ﵽ ��ģ̬�� Ч��
    bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void onEnter(); 
    void menuconfirmCallback(CCObject* pSender);
    // implement the "static node()" method manually
    CREATE_FUNC(EnterNameLayer);
// ��дCCTextFieldDelegate�Ļص�����
// ���û�����������̵�ʱ��ص�����
// Ҫ�������
virtual bool onTextFieldAttachWithIME(cocos2d::CCTextFieldTTF * sender);
// ���û��ر�������̵�ʱ��ص�����
virtual bool onTextFieldDetachWithIME(cocos2d::CCTextFieldTTF * sender);
// ���û��������� ������̵�ʱ��ص�����
virtual bool onTextFieldInsertText(cocos2d::CCTextFieldTTF * sender, const char * text, int nLen);
// ���û�����ɾ������ ������̵�ʱ��ص�����
virtual bool onTextFieldDeleteBackward(cocos2d::CCTextFieldTTF * sender, const char * delText, int nLen);


	//virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    // ģ̬�Ի���˵�   
    cocos2d::CCMenu *m_pMenu;  
  // ��¼�˵����   
    bool m_bTouchedMenu;
private:
    cocos2d::CCTextFieldTTF *textField;
};

#endif
