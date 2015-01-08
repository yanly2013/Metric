#include "metriclogic.h"
#include <iostream>

void MetricLogic::init()
{
	memset(&m_metricNode, 0, sizeof(30*10));
	m_metricNode[0][0].X = 100;
	m_metricNode[0][0].Y = 100;
	m_metricNode[0][1].X = 120;
	m_metricNode[0][1].Y = 100;
	m_metricNode[0][2].X = 140;
	m_metricNode[0][2].Y = 100;
	m_metricNode[0][3].X = 160;
	m_metricNode[0][3].Y = 100;
	m_metricNode[0][3].X = 180;
	m_metricNode[0][3].Y = 100;
	m_metricNode[0][4].X = 200;
	m_metricNode[0][4].Y = 100;
	m_metricNode[0][5].X = 220;
	m_metricNode[0][5].Y = 100;
	m_metricNode[0][6].X = 240;
	m_metricNode[0][6].Y = 100;
	m_metricNode[0][7].X = 260;
	m_metricNode[0][7].Y = 100;
	m_metricNode[0][8].X = 280;
	m_metricNode[0][8].Y = 100;
	m_metricNode[0][9].X = 300;
	m_metricNode[0][9].Y = 100;
	m_metricNode[1][0].X = 100;
	m_metricNode[1][0].Y = 120;
	m_metricNode[1][1].X = 120;
	m_metricNode[1][1].Y = 120;
	m_metricNode[1][2].X = 140;
	m_metricNode[1][2].Y = 120;
	m_metricNode[1][3].X = 160;
	m_metricNode[1][3].Y = 120;
	m_metricNode[1][3].X = 180;
	m_metricNode[1][3].Y = 120;
	m_metricNode[1][4].X = 200;
	m_metricNode[1][4].Y = 120;
	m_metricNode[1][5].X = 220;
	m_metricNode[1][5].Y = 120;
	m_metricNode[1][6].X = 240;
	m_metricNode[1][6].Y = 120;
	m_metricNode[1][7].X = 260;
	m_metricNode[1][7].Y = 120;
	m_metricNode[1][8].X = 280;
	m_metricNode[1][8].Y = 120;
	m_metricNode[1][9].X = 300;
	m_metricNode[1][9].Y = 120;
}

T_MetricNode* MetricLogic::getmetricnode()
{
	return &m_metricNode[0][0];
}