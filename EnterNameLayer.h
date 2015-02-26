#ifndef __ENTERNAME_LAYER_H__
#define __ENTERNAME_LAYER_H__

#include "cocos2d.h"


class EnterNameLayer : public cocos2d::CCLayer, public cocos2d::CCTextFieldDelegate
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
    CREATE_FUNC(EnterNameLayer);
// 重写CCTextFieldDelegate的回调函数
// 当用户启动虚拟键盘的时候回调函数
// 要有输出口
virtual bool onTextFieldAttachWithIME(cocos2d::CCTextFieldTTF * sender);
// 当用户关闭虚拟键盘的时候回调函数
virtual bool onTextFieldDetachWithIME(cocos2d::CCTextFieldTTF * sender);
// 当用户进行输入 虚拟键盘的时候回调函数
virtual bool onTextFieldInsertText(cocos2d::CCTextFieldTTF * sender, const char * text, int nLen);
// 当用户进行删除文字 虚拟键盘的时候回调函数
virtual bool onTextFieldDeleteBackward(cocos2d::CCTextFieldTTF * sender, const char * delText, int nLen);


	//virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    // 模态对话框菜单   
    cocos2d::CCMenu *m_pMenu;  
  // 记录菜单点击   
    bool m_bTouchedMenu;
private:
    cocos2d::CCTextFieldTTF *textField;
};

#endif
