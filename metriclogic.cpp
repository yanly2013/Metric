#include "metriclogic.h"
#include <iostream>

void MetricLogic::init()
{
	memset(&m_metricNode, 0xff, sizeof(m_metricNode));
	m_metricNode[0][0].X = 0;
	m_metricNode[0][0].Y = 0;
	m_metricNode[0][0].number = 0;
	m_metricNode[0][1].X = 1;
	m_metricNode[0][1].Y = 0;
	m_metricNode[0][1].number = 1;
	m_metricNode[0][2].X = 2;
	m_metricNode[0][2].Y = 0;
	m_metricNode[0][2].number = 2;
	m_metricNode[0][3].X = 3;
	m_metricNode[0][3].Y = 0;
	m_metricNode[0][3].number = 3;
	m_metricNode[0][4].X = 4;
	m_metricNode[0][4].Y = 0;
	m_metricNode[0][4].number = 4;
	m_metricNode[0][5].X = 5;
	m_metricNode[0][5].Y = 0;
	m_metricNode[0][5].number = 5;
	m_metricNode[0][6].X = 6;
	m_metricNode[0][6].Y = 0;
	m_metricNode[0][6].number = 6;
	m_metricNode[0][7].X = 7;
	m_metricNode[0][7].Y = 0;
	m_metricNode[0][7].number = 7;
	m_metricNode[0][8].X = 8;
	m_metricNode[0][8].Y = 0;
	m_metricNode[0][8].number = 8;
	m_metricNode[0][9].X = 9;
	m_metricNode[0][9].Y = 0;
	m_metricNode[0][9].number = 9;

	m_metricNode[1][0].X = 0;
	m_metricNode[1][0].Y = 1;
	m_metricNode[1][0].number = 20;
	m_metricNode[1][1].X = 1;
	m_metricNode[1][1].Y = 1;
	m_metricNode[1][1].number = 20;
	m_metricNode[1][2].X = 2;
	m_metricNode[1][2].Y = 1;
	m_metricNode[1][2].number = 20;
	m_metricNode[1][3].X = 3;
	m_metricNode[1][3].Y = 1;
	m_metricNode[1][3].number = 2;
	m_metricNode[1][4].X = 4;
	m_metricNode[1][4].Y = 1;
	m_metricNode[1][4].number = 3;
	m_metricNode[1][5].X = 5;
	m_metricNode[1][5].Y = 1;
	m_metricNode[1][5].number = 20;
	m_metricNode[1][6].X = 6;
	m_metricNode[1][6].Y = 1;
	m_metricNode[1][6].number = 4;
	m_metricNode[1][7].X = 7;
	m_metricNode[1][7].Y = 1;
	m_metricNode[1][7].number = 20;
	m_metricNode[1][8].X = 8;
	m_metricNode[1][8].Y = 1;
	m_metricNode[1][8].number = 5;
	m_metricNode[1][9].X = 9;
	m_metricNode[1][9].Y = 1;
	m_metricNode[1][9].number = 20;

	m_maxposition[0] = 1;
	m_maxposition[1] = 1;
    m_maxposition[2] = 1;
	m_maxposition[3] = 2;
	m_maxposition[4] = 2;
    m_maxposition[5] = 1;
	m_maxposition[6] = 2;
	m_maxposition[7] = 1;
    m_maxposition[8] = 2;
    m_maxposition[9] = 1;
}

T_MetricNode* MetricLogic::getmetricnode()
{
	return &m_metricNode[0][0];
}

unsigned char*  MetricLogic::getmaxposition()
{
	return &m_maxposition[0];
}
void MetricLogic::addnewNode(T_MetricNode a[4])
{
	m_metricNode[a[0].Y][a[0].X] = a[0];
    m_metricNode[a[1].Y][a[1].X] = a[1];
    m_metricNode[a[2].Y][a[2].X] = a[2];
    m_metricNode[a[3].Y][a[3].X] = a[3];
	for (int i = 0; i < 4; i++)
	{
	if (m_maxposition[a[i].X] < a[i].Y)
    {
        m_maxposition[a[i].X] = a[i].Y;
	}
	}
}

void MetricLogic::dismissLine()
{
	int linecount = 0;
	int dismissnum = 0;
	int dismisscount[10];
    for (int i = 0; i<23; i++)
	{
		linecount = 0;
		for (int j = 0; j<10; j++)
		{
			if (m_metricNode[i][j].number < 10)
			{
				linecount++;
			}
		}
		if (linecount == 10)
		{
			dismisscount[dismissnum]=i;
			dismissnum++;
		}
	}
	int delnum = 0;
	int tempnode[23][10];
	int tempnum = 0;
	memset(&tempnode, 0xff, sizeof(tempnode));
		for (int k= 0; k <23 ; k++)
		{
			if (delnum == dismissnum)
			{
				break;
			}

			if (k != dismisscount[delnum])
			{

			memcpy(&tempnode[tempnum], &m_metricNode[k], sizeof(T_MetricNode)*10);
			
			for (int m = 0; m< 10;m++)
			{
				m_metricNode[k][m].Y-=1;
				
			}
			delnum++;
			}
		}
		for (int j = 0; j<10; j++)
		{
			m_maxposition[j]-=delnum;
		}

		
}