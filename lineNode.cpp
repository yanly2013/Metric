#include "lineNode.h"

void LineNode::initnext()
{
	m_activeNode[0].X = 300;
	m_activeNode[0].Y = 550;
	m_activeNode[0].number = 2;
	m_activeNode[0].color = RED;
	m_activeNode[0].tools = 0;
    
	m_activeNode[1].X = 320;
	m_activeNode[1].Y = 550;
	m_activeNode[1].number = 2;
	m_activeNode[1].color = RED;
	m_activeNode[1].tools = 0;
   
	m_activeNode[2].X = 300;
	m_activeNode[2].Y = 530;
	m_activeNode[2].number = 2;
	m_activeNode[2].color = RED;
	m_activeNode[2].tools = 0;
    
	m_activeNode[3].X = 320;
	m_activeNode[3].Y = 530;
	m_activeNode[3].number = 2;
	m_activeNode[3].color = RED;
	m_activeNode[3].tools = 0;
}

void LineNode::init()
{
	m_activeNode[0].X = 3;
	m_activeNode[0].Y = 22;
	m_activeNode[0].number = 2;
	m_activeNode[0].color = RED;
	m_activeNode[0].tools = 0;
    
	m_activeNode[1].X = 4;
	m_activeNode[1].Y = 22;
	m_activeNode[1].number = 2;
	m_activeNode[1].color = RED;
	m_activeNode[1].tools = 0;
   
	m_activeNode[2].X = 5;
	m_activeNode[2].Y = 22;
	m_activeNode[2].number = 2;
	m_activeNode[2].color = RED;
	m_activeNode[2].tools = 0;
    
	m_activeNode[3].X = 6;
	m_activeNode[3].Y = 22;
	m_activeNode[3].number = 2;
	m_activeNode[3].color = RED;
	m_activeNode[3].tools = 0;
}

void LineNode::rotate()
{
	static int i = 0;
	switch(i)
	{
	case 0:
	m_activeNode[0].X+=1;
	m_activeNode[0].Y-=2;
	m_activeNode[1].Y-=1;
	m_activeNode[2].X-=1;
	m_activeNode[3].X-=2;
	m_activeNode[3].Y+=1;
	i=1;
	break;
	case 1:
	m_activeNode[0].X+=2;
	m_activeNode[0].Y+=2;
	m_activeNode[1].X+=1;
	m_activeNode[1].Y+=1;
	m_activeNode[3].X-=1;
	m_activeNode[3].Y-=1;
	i=2;	
	break;
    case 2:
	m_activeNode[0].X-=2;
	m_activeNode[0].Y+=1;
	m_activeNode[1].X-=1;
	m_activeNode[2].Y-=1;
	m_activeNode[3].X+=1;
	m_activeNode[3].Y-=2;
	i=3;	
	break;
    case 3:
	m_activeNode[0].X-=1;
	m_activeNode[0].Y-=1;
	m_activeNode[2].X+=1;
	m_activeNode[2].Y+=1;
	m_activeNode[3].X+=2;
	m_activeNode[3].Y+=2;
	i=0;	
	break;
	}
}