#ifndef __CONFIRM_LAYER_H__
#define __CONFIRM_LAYER_H__

#include "cocos2d.h"


class ConfirmLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
   // 需要重写触摸注册函数，重新给定触摸级别
    virtual void registerWithTouchDispatcher(void);
    // 重写触摸函数，永远返回 true ，屏蔽其它层，达到 “模态” 效果
    bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void onEnter(); 
    void menuconfirmCallback(CCObject* pSender);
    // implement the "static node()" method manually
    CREATE_FUNC(ConfirmLayer);

	//virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    // 模态对话框菜单   
    cocos2d::CCMenu *m_pMenu;  
  // 记录菜单点击   
    bool m_bTouchedMenu;
private:

};

#endif
