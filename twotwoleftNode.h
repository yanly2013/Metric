#ifndef __TWOTWOLEFT_NODE_H__
#define __TWOTWOLEFT_NODE_H__

#include "activeNode.h"
class TwoTwoLeftNode:public ActiveNode
{
public:
	void init(NodeColor color);
	void initnext(NodeColor color);
    void rotate();
};

#endif