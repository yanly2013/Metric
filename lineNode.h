#ifndef __LINE_NODE_H__
#define __LINE_NODE_H__

#include "activeNode.h"
class LineNode:public ActiveNode
{
public:
	void init(NodeColor color);
	void initnext(NodeColor color);
    void rotate();
};

#endif