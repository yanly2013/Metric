#ifndef __TTYPE_NODE_H__
#define __TTYPE_NODE_H__

#include "activeNode.h"
class TTypeNode:public ActiveNode
{
public:
	void init();
	void initnext();
    void rotate();
};

#endif