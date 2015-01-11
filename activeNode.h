#ifndef __ACTIVE_NODE_H__
#define __ACTIVE_NODE_H__

#include "metriclogic.h"
typedef enum nodeType
{
	ONLYONE,
	SQUARE,
	LINEVER,
	LINEHOR,
	ONETWOONELEFTHIGH,
	ONETWOONERIGHTHIGH,
	TWOTWOUPRIGHT,
	TWOTWOUPLEFT
}NodeType;


class ActiveNode
{
public:

	virtual void init();
	virtual void initnext() = 0;
	virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void moveDown() = 0;
	virtual void quickDown() = 0;
	virtual void rotate() = 0;
	virtual T_MetricNode* getActiveNode();



protected:
    NodeType m_activeNodeType;
    T_MetricNode m_activeNode[4];
};


#endif