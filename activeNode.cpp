#include "activeNode.h"
#include <time.h>
#include <stdlib.h> 
/*
void ActiveNode::init()
{
	rotatenum = 0;
    m_activeNode[0].X = 120;
	m_activeNode[0].Y = 120;
	m_activeNode[0].number = 2;
	m_activeNode[0].color = RED;
	m_activeNode[0].tools = 0;
    
	m_activeNode[1].X = 120;
	m_activeNode[1].Y = 120;
	m_activeNode[1].number = 2;
	m_activeNode[1].color = RED;
	m_activeNode[1].tools = 0;
   
	m_activeNode[2].X = 120;
	m_activeNode[2].Y = 120;
	m_activeNode[2].number = 2;
	m_activeNode[2].color = RED;
	m_activeNode[2].tools = 0;
    
	m_activeNode[3].X = 120;
	m_activeNode[3].Y = 120;
	m_activeNode[3].number = 2;
	m_activeNode[3].color = RED;
	m_activeNode[3].tools = 0;
}
*/
void ActiveNode::moveLeft()
{	
	for (int i = 0; i < 4; i++)
	{
		if (m_activeNode[i].X == 0)
		{
			return;
		}
	}
	m_activeNode[0].X-=1;
	m_activeNode[1].X-=1;
    m_activeNode[2].X-=1;
    m_activeNode[3].X-=1;
}
void ActiveNode::moveRight()
{
    for (int i = 0; i < 4; i++)
	{
		if (m_activeNode[i].X == 9)
		{
			return;
		}
	}
	m_activeNode[0].X+=1;
	m_activeNode[1].X+=1;
    m_activeNode[2].X+=1;
    m_activeNode[3].X+=1;
}
void ActiveNode::moveDown()
{
    m_activeNode[0].Y-=1;
	m_activeNode[1].Y-=1;
    m_activeNode[2].Y-=1;
	m_activeNode[3].Y-=1;
}

T_MetricNode* ActiveNode::getActiveNode()
{
	return &m_activeNode[0];
}

unsigned char ActiveNode::getAnumber()
{
     srand((int)time(0));
     return rand()%10;
}


