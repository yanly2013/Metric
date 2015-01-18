#ifndef __TWOTWORIGHT_NODE_H__
#define __TWOTWORIGHT_NODE_H__

#include "activeNode.h"
class TwoTwoRightNode:public ActiveNode
{
public:
	void init();
	void initnext();
    void rotate();
};

#endif