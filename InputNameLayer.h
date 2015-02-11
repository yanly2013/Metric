#ifndef __INPUTNAME_LAYER_H__
#define __INPUTNAME_LAYER_H__

#include "cocos2d.h"


class InputNameLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
   // ��Ҫ��д����ע�ắ�������¸�����������
    virtual void registerWithTouchDispatcher(void);
    // ��д������������Զ���� true �����������㣬�ﵽ ��ģ̬�� Ч��
    bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void onEnter(); 

    // implement the "static node()" method manually
    CREATE_FUNC(InputNameLayer);

	//virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    // ģ̬�Ի���˵�   
    cocos2d::CCMenu *m_pMenu;  
  // ��¼�˵����   
    bool m_bTouchedMenu;
private:

};

#endif
