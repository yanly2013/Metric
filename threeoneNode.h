#ifndef __THREEONE_NODE_H__
#define __THREEONE_NODE_H__

#include "activeNode.h"
class ThreeOneNode:public ActiveNode
{
public:
	void init();
	void initnext();
    void rotate();
};

#endif