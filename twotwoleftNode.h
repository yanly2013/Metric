#ifndef __TWOTWOLEFT_NODE_H__
#define __TWOTWOLEFT_NODE_H__

#include "activeNode.h"
class TwoTwoLeftNode:public ActiveNode
{
public:
	void init();
	void initnext();
    void rotate();
};

#endif