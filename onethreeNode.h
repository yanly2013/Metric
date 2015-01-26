#ifndef __ONETHREE_NODE_H__
#define __ONETHREE_NODE_H__

#include "activeNode.h"
class OneThreeNode:public ActiveNode
{
public:
	void init(NodeColor color);
	void initnext(NodeColor color);
    void rotate();
};

#endif