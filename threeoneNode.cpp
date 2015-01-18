#include "threeoneNode.h"

void ThreeOneNode::initnext()
{
	m_activeNode[0].X = 305;
	m_activeNode[0].Y = 560;
	m_activeNode[0].number = 2;
	m_activeNode[0].color = RED;
	m_activeNode[0].tools = 0;
    
	m_activeNode[1].X = 305;
	m_activeNode[1].Y = 540;
	m_activeNode[1].number = 2;
	m_activeNode[1].color = RED;
	m_activeNode[1].tools = 0;
   
	m_activeNode[2].X = 305;
	m_activeNode[2].Y = 520;
	m_activeNode[2].number = 2;
	m_activeNode[2].color = RED;
	m_activeNode[2].tools = 0;
    
	m_activeNode[3].X = 325;
	m_activeNode[3].Y = 560;
	m_activeNode[3].number = 2;
	m_activeNode[3].color = RED;
	m_activeNode[3].tools = 0;
}

void ThreeOneNode::init()
{
	m_activeNode[0].X = 4;
	m_activeNode[0].Y = 22;
	m_activeNode[0].number = 2;
	m_activeNode[0].color = RED;
	m_activeNode[0].tools = 0;
    
	m_activeNode[1].X = 4;
	m_activeNode[1].Y = 21;
	m_activeNode[1].number = 2;
	m_activeNode[1].color = RED;
	m_activeNode[1].tools = 0;
   
	m_activeNode[2].X = 4;
	m_activeNode[2].Y = 20;
	m_activeNode[2].number = 2;
	m_activeNode[2].color = RED;
	m_activeNode[2].tools = 0;
    
	m_activeNode[3].X = 5;
	m_activeNode[3].Y = 22;
	m_activeNode[3].number = 2;
	m_activeNode[3].color = RED;
	m_activeNode[3].tools = 0;
}

void ThreeOneNode::rotate()
{
	static int i = 0;
	switch(i)
	{
	case 0:
	m_activeNode[0].X;
	m_activeNode[0].Y-=1;
	m_activeNode[1].X+=1;
	m_activeNode[1].Y;
	m_activeNode[2].X+=2;
	m_activeNode[2].Y+=1;
	m_activeNode[3].X-=1;
	m_activeNode[3].Y;
	i=1;
	break;
	case 1:
	m_activeNode[0].X+=1;
	m_activeNode[0].Y;
	m_activeNode[1].X;
	m_activeNode[1].Y+=1;
	m_activeNode[2].X-=1;
	m_activeNode[2].Y+=2;
	m_activeNode[3].X;
	m_activeNode[3].Y-=1;
	i=2;	
	break;
    case 2:
	m_activeNode[0].X;
	m_activeNode[0].Y+=1;
	m_activeNode[1].X-=1;
	m_activeNode[1].Y;
	m_activeNode[2].X-=2;
	m_activeNode[2].Y-=1;
	m_activeNode[3].X+=1;
	m_activeNode[3].Y;
	i=3;	
	break;
    case 3:
	m_activeNode[0].X-=1;
	m_activeNode[0].Y;
	m_activeNode[1].X;
	m_activeNode[1].Y-=1;
	m_activeNode[2].X+=1;
	m_activeNode[2].Y-=2;
	m_activeNode[3].X;
	m_activeNode[3].Y+=1;
	i=0;	
	break;
	}
}