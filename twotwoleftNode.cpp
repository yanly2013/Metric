#include "twotwoleftNode.h"

void TwoTwoLeftNode::initnext()
{
	m_activeNode[0].X = 305;
	m_activeNode[0].Y = 560;
	m_activeNode[0].number = 2;
	m_activeNode[0].color = RED;
	m_activeNode[0].tools = 0;
    
	m_activeNode[1].X = 325;
	m_activeNode[1].Y = 560;
	m_activeNode[1].number = 2;
	m_activeNode[1].color = RED;
	m_activeNode[1].tools = 0;
   
	m_activeNode[2].X = 325;
	m_activeNode[2].Y = 540;
	m_activeNode[2].number = 2;
	m_activeNode[2].color = RED;
	m_activeNode[2].tools = 0;
    
	m_activeNode[3].X = 345;
	m_activeNode[3].Y = 540;
	m_activeNode[3].number = 2;
	m_activeNode[3].color = RED;
	m_activeNode[3].tools = 0;
}

void TwoTwoLeftNode::init()
{
	m_activeNode[0].X = 4;
	m_activeNode[0].Y = 22;
	m_activeNode[0].number = 2;
	m_activeNode[0].color = RED;
	m_activeNode[0].tools = 0;
    
	m_activeNode[1].X = 5;
	m_activeNode[1].Y = 22;
	m_activeNode[1].number = 2;
	m_activeNode[1].color = RED;
	m_activeNode[1].tools = 0;
   
	m_activeNode[2].X = 5;
	m_activeNode[2].Y = 21;
	m_activeNode[2].number = 2;
	m_activeNode[2].color = RED;
	m_activeNode[2].tools = 0;
    
	m_activeNode[3].X = 6;
	m_activeNode[3].Y = 21;
	m_activeNode[3].number = 2;
	m_activeNode[3].color = RED;
	m_activeNode[3].tools = 0;
}

void TwoTwoLeftNode::rotate()
{
	static int i = 0;
	switch(i)
	{
	case 0:
	m_activeNode[0].X;
	m_activeNode[0].Y-=1;
	m_activeNode[1].X-=1;
	m_activeNode[1].Y;
	m_activeNode[2].X;
	m_activeNode[2].Y+=1;
	m_activeNode[3].X-=1;
	m_activeNode[3].Y+=2;
	i=1;
	break;
	case 1:
	m_activeNode[0].X+=1;
	m_activeNode[0].Y;
	m_activeNode[1].X;
	m_activeNode[1].Y-=1;
	m_activeNode[2].X-=1;
	m_activeNode[2].Y;
	m_activeNode[3].X-=2;
	m_activeNode[3].Y-=1;
	i=2;	
	break;
    case 2:
	m_activeNode[0].X;
	m_activeNode[0].Y+=1;
	m_activeNode[1].X+=1;
	m_activeNode[1].Y;
	m_activeNode[2].X;
	m_activeNode[2].Y-=1;
	m_activeNode[3].X+=1;
	m_activeNode[3].Y-=2;
	i=3;	
	break;
    case 3:
	m_activeNode[0].X-=1;
	m_activeNode[0].Y;
	m_activeNode[1].X;
	m_activeNode[1].Y+=1;
	m_activeNode[2].X+=1;
	m_activeNode[2].Y;
	m_activeNode[3].X+=2;
	m_activeNode[3].Y+=1;
	i=0;	
	break;
	}
}