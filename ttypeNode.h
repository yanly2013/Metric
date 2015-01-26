#ifndef __TTYPE_NODE_H__
#define __TTYPE_NODE_H__

#include "activeNode.h"
class TTypeNode:public ActiveNode
{
public:
	void init(NodeColor color);
	void initnext(NodeColor color);
    void rotate();
};

#endif