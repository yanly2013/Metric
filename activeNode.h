#ifndef __ACTIVE_NODE_H__
#define __ACTIVE_NODE_H__

#include "metriclogic.h"
typedef enum nodeType
{
	SQUARE,
	LINE,
    THREEONE,
	ONETHREE,
	TWOTWOLEFT,
	TWOTWORIGHT,
	TTYPE
}NodeType;


class ActiveNode
{
public:

	virtual void init();
	virtual void initnext() = 0;
	virtual void moveLeft();
    virtual void moveRight();
    virtual void moveDown();
	virtual void rotate() = 0;
	virtual T_MetricNode* getActiveNode();



protected:
    NodeType m_activeNodeType;
    T_MetricNode m_activeNode[4];
	unsigned char rotatenum;
};


#endif