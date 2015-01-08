#include "activeNode.h"


void ActiveNode::init()
{
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

T_MetricNode* ActiveNode::getActiveNode()
{
	return &m_activeNode[0];
}

