#ifndef __SQUARE_NODE_H__
#define __SQUARE_NODE_H__

#include "activeNode.h"
class SquareNode:public ActiveNode
{
public:
	void init();
	void initnext();
    void moveLeft();
    void moveRight();
    void moveDown();
    void quickDown();
    void rotate();
};

#endif