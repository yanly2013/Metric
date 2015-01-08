#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class ActiveNode;

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

	void updateGame(float f);
    void checkConflid(float f);
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);

	virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);

private:
    cocos2d::CCSprite *pMetric;
	cocos2d::CCSprite *pMetric1;
	ActiveNode *pactiveNode;
};

#endif // __HELLOWORLD_SCENE_H__
