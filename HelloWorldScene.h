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
	void menuButtonCallback(CCObject* pSender);
	void menuPauseCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);

	//virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);

private:
	void updateGame(float f);
	void updateScore(float f);
    bool checkConflid();
	NodeType createNodeType();
	NodeColor createNodeColor();

	void createNextNode();
	void ActivenextNode();
	void destroyActiveNode();
	void saveActiveNode(T_MetricNode activenode[]);
	void displayMetric();
	void Pause();

	void dismissLineShow();
	void gameOverShow();
	
    MetricFactory *factory;
	cocos2d::CCSpriteBatchNode * batchnode;
    cocos2d::CCSprite *pMetric0;
	cocos2d::CCSprite *pMetric1;
	cocos2d::CCSprite *pMetric2;
	cocos2d::CCSprite *pMetric3;
    cocos2d::CCSprite *pnextMetric0;
	cocos2d::CCSprite *pnextMetric1;
	cocos2d::CCSprite *pnextMetric2;
	cocos2d::CCSprite *pnextMetric3;
	cocos2d::CCSprite *pNodeSprite[24*10];

	cocos2d::CCSprite *pgood;
	cocos2d::CCSprite *pdismissline;
	unsigned int deadSpriteNum;
	ActiveNode *pactiveNode;
	ActiveNode *pnextactiveNode;
	T_MetricNode oldactivenode[4];
	MetricLogic *metriclogic;

	cocos2d::CCLabelAtlas* pLabellevel;
	cocos2d::CCLabelAtlas* pLabelscore;
	cocos2d::CCLabelAtlas* pLabelline;

	NodeType m_nexttype;
	NodeColor m_nodecolor;
	NodeType m_activetype;

	bool pauseflg;

    unsigned int level;
	unsigned int score;
    unsigned int line;
};

#endif // __HELLOWORLD_SCENE_H__
