#ifndef __TWOTWORIGHT_NODE_H__
#define __TWOTWORIGHT_NODE_H__

#include "activeNode.h"
class TwoTwoRightNode:public ActiveNode
{
public:
	void init(NodeColor color);
	void initnext(NodeColor color);
    void rotate();
};

#endif