#ifndef __SQUARE_NODE_H__
#define __SQUARE_NODE_H__

#include "activeNode.h"
class SquareNode:public ActiveNode
{
public:
	void init(NodeColor color);
	void initnext(NodeColor color);
    void rotate();
};

#endif