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
void ActiveNode::loopNumber()
{
	unsigned short temp;

	temp = m_activeNode[0].number;
	m_activeNode[0].number = m_activeNode[1].number;
	m_activeNode[1].number = m_activeNode[2].number;
	m_activeNode[2].number = m_activeNode[3].number;
	m_activeNode[3].number = temp;
}
void  ActiveNode::setLoopTime()
{
	looptime = (looptime+1) % 4;
}
unsigned int ActiveNode::getLoopTime()
{
	return looptime;
}
T_MetricNode* ActiveNode::getActiveNode()
{
	return &m_activeNode[0];
}

 unsigned char ActiveNode::getAnumber()
{
	 static int randinrand = 1;
     srand((int)time(0)+randinrand);
	 volatile int number = rand()%10;
	 randinrand = rand();
     return number;
}


