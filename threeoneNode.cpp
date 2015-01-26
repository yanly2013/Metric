#include "threeoneNode.h"

void ThreeOneNode::initnext(NodeColor color)
{
	m_activeNode[0].X = 305;
	m_activeNode[0].Y = 560;
	m_activeNode[0].number = 2;
	m_activeNode[0].color = color;
	m_activeNode[0].tools = 0;
    
	m_activeNode[1].X = 305;
	m_activeNode[1].Y = 540;
	m_activeNode[1].number = 2;
	m_activeNode[1].color = color;
	m_activeNode[1].tools = 0;
   
	m_activeNode[2].X = 305;
	m_activeNode[2].Y = 520;
	m_activeNode[2].number = 2;
	m_activeNode[2].color = color;
	m_activeNode[2].tools = 0;
    
	m_activeNode[3].X = 325;
	m_activeNode[3].Y = 560;
	m_activeNode[3].number = 2;
	m_activeNode[3].color = color;
	m_activeNode[3].tools = 0;
}

void ThreeOneNode::init(NodeColor color)
{
	m_activeNode[0].X = 4;
	m_activeNode[0].Y = 22;
	m_activeNode[0].number = getAnumber();;
	m_activeNode[0].color = color;
	m_activeNode[0].tools = 0;
    
	m_activeNode[1].X = 4;
	m_activeNode[1].Y = 21;
	m_activeNode[1].number = getAnumber();;
	m_activeNode[1].color = color;
	m_activeNode[1].tools = 0;
   
	m_activeNode[2].X = 4;
	m_activeNode[2].Y = 20;
	m_activeNode[2].number = getAnumber();;
	m_activeNode[2].color = color;
	m_activeNode[2].tools = 0;
    
	m_activeNode[3].X = 5;
	m_activeNode[3].Y = 22;
	m_activeNode[3].number = getAnumber();;
	m_activeNode[3].color = color;
	m_activeNode[3].tools = 0;
    rotatenum=0;
}

void ThreeOneNode::rotate()
{
	switch(rotatenum)
	{
	case 0:
    if (m_activeNode[3].X == 9)
	{
	    m_activeNode[0].X-=1;
        m_activeNode[1].X-=1;	
        m_activeNode[2].X-=1;	
        m_activeNode[3].X-=1;	
	}
	m_activeNode[0].X;
	m_activeNode[0].Y-=1;
	m_activeNode[1].X+=1;
	m_activeNode[1].Y;
	m_activeNode[2].X+=2;
	m_activeNode[2].Y+=1;
	m_activeNode[3].X-=1;
	m_activeNode[3].Y;
	rotatenum=1;
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
	rotatenum=2;	
	break;
    case 2:
    if (m_activeNode[0].X == 9)
	{
	    m_activeNode[0].X-=1;
        m_activeNode[1].X-=1;	
        m_activeNode[2].X-=1;	
        m_activeNode[3].X-=1;	
	}
	m_activeNode[0].X+=1;
	m_activeNode[0].Y+=1;
	m_activeNode[1].X;
	m_activeNode[1].Y;
	m_activeNode[2].X-=1;
	m_activeNode[2].Y-=1;
	m_activeNode[3].X+=2;
	m_activeNode[3].Y;
	rotatenum=3;	
	break;
    case 3:
	m_activeNode[0].X-=2;
	m_activeNode[0].Y;
	m_activeNode[1].X-=1;
	m_activeNode[1].Y-=1;
	m_activeNode[2].X;
	m_activeNode[2].Y-=2;
	m_activeNode[3].X-=1;
	m_activeNode[3].Y+=1;
	rotatenum=0;	
	break;
	}
}