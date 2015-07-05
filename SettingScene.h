#ifndef __SETTING_SCENE_H__
#define __SETTING_SCENE_H__

#include "cocos2d.h"


class Setting : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuSettingCallback(CCObject* pSender);
    void menuOKCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(Setting);

	//virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);

private:
    bool isMusic;
	bool isSound;
	bool isVibrate;
	bool isTool;

};

#endif