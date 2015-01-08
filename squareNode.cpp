#include "squareNode.h"

void SquareNode::init()
{
	m_activeNode[0].X = 50;
	m_activeNode[0].Y = 700;
	m_activeNode[0].number = 2;
	m_activeNode[0].color = RED;
	m_activeNode[0].tools = 0;
    
	m_activeNode[1].X = 70;
	m_activeNode[1].Y = 700;
	m_activeNode[1].number = 2;
	m_activeNode[1].color = RED;
	m_activeNode[1].tools = 0;
   
	m_activeNode[2].X = 50;
	m_activeNode[2].Y = 650;
	m_activeNode[2].number = 2;
	m_activeNode[2].color = RED;
	m_activeNode[2].tools = 0;
    
	m_activeNode[3].X = 70;
	m_activeNode[3].Y = 650;
	m_activeNode[3].number = 2;
	m_activeNode[3].color = RED;
	m_activeNode[3].tools = 0;
}
void SquareNode::moveLeft()
{
	m_activeNode[0].X-=30;
	m_activeNode[1].X-=20;
}
void SquareNode::moveRight()
{

}
void SquareNode::moveDown()
{
	m_activeNode[0].Y-=30;
	m_activeNode[1].Y-=30;
}
void SquareNode::quickDown()
{

}
void SquareNode::rotate()
{

}