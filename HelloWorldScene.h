#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "metriclogic.h"
#include "activeNode.h"

class ActiveNode;
class MetricLogic;
class MetricFactory;
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
    bool checkConflid();
	NodeType createNodeType();

	void createNextNode();
	void ActivenextNode();
	void destroyActiveNode();
	void saveActiveNode(T_MetricNode activenode[]);
	void displayMetric();
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);

	virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);

private:
    MetricFactory *factory;
    cocos2d::CCSprite *pMetric0;
	cocos2d::CCSprite *pMetric1;
	cocos2d::CCSprite *pMetric2;
	cocos2d::CCSprite *pMetric3;
    cocos2d::CCSprite *pnextMetric0;
	cocos2d::CCSprite *pnextMetric1;
	cocos2d::CCSprite *pnextMetric2;
	cocos2d::CCSprite *pnextMetric3;

	ActiveNode *pactiveNode;
	ActiveNode *pnextactiveNode;
	T_MetricNode oldactivenode[4];
	MetricLogic *metriclogic;

	NodeType m_nexttype;
	NodeType m_activetype;
};

#endif // __HELLOWORLD_SCENE_H__
