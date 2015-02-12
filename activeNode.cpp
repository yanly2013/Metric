#include "activeNode.h"
#include <time.h>
#include <stdlib.h> 

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


