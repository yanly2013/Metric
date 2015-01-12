#ifndef __ONETHREE_NODE_H__
#define __ONETHREE_NODE_H__

#include "activeNode.h"
class OneThreeNode:public ActiveNode
{
public:
	void init();
	void initnext();
    void rotate();
};

#endif