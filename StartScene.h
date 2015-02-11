#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"


class Start : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuStartCallback(CCObject* pSender);
    void menuSettingCallback(CCObject* pSender);


    // implement the "static node()" method manually
    CREATE_FUNC(Start);

	//virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);

private:
	


};

#endif