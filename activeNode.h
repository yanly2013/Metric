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
	void init();
	virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void moveDown() = 0;
	virtual void quickDown() = 0;
	virtual void rotate() = 0;

private:
    NodeType m_activeNodeType;
    T_MetricNode m_activeNode[4];
};


#endif