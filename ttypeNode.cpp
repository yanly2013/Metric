#include "ttypeNode.h"

void TTypeNode::initnext(NodeColor color)
{
	m_activeNode[0].X = XNextNodePos[1];
	m_activeNode[0].Y = YNextNodePos[0];
	m_activeNode[0].number = 2;
	m_activeNode[0].color = color;
	m_activeNode[0].tools = 0;
    
	m_activeNode[1].X = XNextNodePos[2];
	m_activeNode[1].Y = YNextNodePos[0];
	m_activeNode[1].number = 2;
	m_activeNode[1].color = color;
	m_activeNode[1].tools = 0;
   
	m_activeNode[2].X = XNextNodePos[3];
	m_activeNode[2].Y = YNextNodePos[0];
	m_activeNode[2].number = 2;
	m_activeNode[2].color = color;
	m_activeNode[2].tools = 0;
    
	m_activeNode[3].X = XNextNodePos[2];
	m_activeNode[3].Y = YNextNodePos[1];
	m_activeNode[3].number = 2;
	m_activeNode[3].color = color;
	m_activeNode[3].tools = 0;
}

void TTypeNode::init(NodeColor color)
{
    looptime = 0;
	m_activeNode[0].X = 4;
	m_activeNode[0].Y = 23;
	m_activeNode[0].number = getAnumber();
	m_activeNode[0].color = color;
	m_activeNode[0].tools = 0;
    
	m_activeNode[1].X = 5;
	m_activeNode[1].Y = 23;
	m_activeNode[1].number = getAnumber();
	m_activeNode[1].color = color;
	m_activeNode[1].tools = 0;
   
	m_activeNode[2].X = 6;
	m_activeNode[2].Y = 23;
	m_activeNode[2].number = getAnumber();
	m_activeNode[2].color = color;
	m_activeNode[2].tools = 0;
    
	m_activeNode[3].X = 5;
	m_activeNode[3].Y = 22;
	m_activeNode[3].number = getAnumber();
	m_activeNode[3].color = color;
	m_activeNode[3].tools = 0;
	rotatenum=0;
}

void TTypeNode::rotate()
{

	switch(rotatenum)
	{
	case 0:
	m_activeNode[0].X+=1;
	m_activeNode[0].Y-=1;
	m_activeNode[1].X;
	m_activeNode[1].Y;
	m_activeNode[2].X-=1;
	m_activeNode[2].Y+=1;
	m_activeNode[3].X+=1;
	m_activeNode[3].Y+=1;
	rotatenum=1;
	break;
	case 1:
    if (m_activeNode[0].X == 0)
	{
	    m_activeNode[0].X+=1;
        m_activeNode[1].X+=1;	
        m_activeNode[2].X+=1;	
        m_activeNode[3].X+=1;	
	}
	m_activeNode[0].X+=1;
	m_activeNode[0].Y+=1;
	m_activeNode[1].X;
	m_activeNode[1].Y;
	m_activeNode[2].X-=1;
	m_activeNode[2].Y-=1;
	m_activeNode[3].X-=1;
	m_activeNode[3].Y+=1;
	rotatenum=2;	
	break;
    case 2:
	m_activeNode[0].X-=1;
	m_activeNode[0].Y+=1;
	m_activeNode[1].X;
	m_activeNode[1].Y;
	m_activeNode[2].X+=1;
	m_activeNode[2].Y-=1;
	m_activeNode[3].X-=1;
	m_activeNode[3].Y-=1;
	rotatenum=3;	
	break;
    case 3:
    if (m_activeNode[0].X == 9)
	{
	    m_activeNode[0].X-=1;
        m_activeNode[1].X-=1;	
        m_activeNode[2].X-=1;	
        m_activeNode[3].X-=1;	
	}
	m_activeNode[0].X-=1;
	m_activeNode[0].Y-=1;
	m_activeNode[1].X;
	m_activeNode[1].Y;
	m_activeNode[2].X+=1;
	m_activeNode[2].Y+=1;
	m_activeNode[3].X+=1;
	m_activeNode[3].Y-=1;
	rotatenum=0;	
	break;
	}
}