#include "metriclogic.h"
#include <iostream>

void MetricLogic::init()
{

    m_level = 1;
	m_score = 0;
    m_line = 0;
	scoreTimes = 1;
	
	memset(&m_metricNode, 0xff, sizeof(m_metricNode));
	m_metricNode[0][0].X = 0;
	m_metricNode[0][0].Y = 0;
	m_metricNode[0][0].number = 0;
	m_metricNode[0][0].color = YELLOW;
	m_metricNode[0][1].X = 1;
	m_metricNode[0][1].Y = 0;
	m_metricNode[0][1].number = 1;
	m_metricNode[0][1].color = YELLOW;
	m_metricNode[0][2].X = 2;
	m_metricNode[0][2].Y = 0;
	m_metricNode[0][2].number = 2;
	m_metricNode[0][2].color = YELLOW;
	m_metricNode[0][3].X = 3;
	m_metricNode[0][3].Y = 0;
	m_metricNode[0][3].number = 3;
	m_metricNode[0][3].color = YELLOW;
	m_metricNode[0][4].X = 4;
	m_metricNode[0][4].Y = 0;
	m_metricNode[0][4].number = 20;
	m_metricNode[0][4].color = GREEN;
	m_metricNode[0][5].X = 5;
	m_metricNode[0][5].Y = 0;
	m_metricNode[0][5].number = 5;
	m_metricNode[0][5].color = GREEN;
	m_metricNode[0][6].X = 6;
	m_metricNode[0][6].Y = 0;
	m_metricNode[0][6].number = 6;
	m_metricNode[0][6].color = RED;
	m_metricNode[0][7].X = 7;
	m_metricNode[0][7].Y = 0;
	m_metricNode[0][7].number = 7;
	m_metricNode[0][7].color = RED;
	m_metricNode[0][8].X = 8;
	m_metricNode[0][8].Y = 0;
	m_metricNode[0][8].number = 8;
	m_metricNode[0][8].color = RED;
	m_metricNode[0][9].X = 9;
	m_metricNode[0][9].Y = 0;
	m_metricNode[0][9].number = 9;
	m_metricNode[0][9].color = RED;

	m_metricNode[1][0].X = 0;
	m_metricNode[1][0].Y = 1;
	m_metricNode[1][0].number = 20;
	m_metricNode[1][0].color = RED;
	m_metricNode[1][1].X = 1;
	m_metricNode[1][1].Y = 1;
	m_metricNode[1][1].number = 20;
	m_metricNode[1][1].color = PURPLE;
	m_metricNode[1][2].X = 2;
	m_metricNode[1][2].Y = 1;
	m_metricNode[1][2].number = 20;
	m_metricNode[1][2].color = PURPLE;
	m_metricNode[1][3].X = 3;
	m_metricNode[1][3].Y = 1;
	m_metricNode[1][3].number = 2;
	m_metricNode[1][3].color = PURPLE;
	m_metricNode[1][4].X = 4;
	m_metricNode[1][4].Y = 1;
	m_metricNode[1][4].number = 20;
	m_metricNode[1][4].color = PURPLE;
	m_metricNode[1][5].X = 5;
	m_metricNode[1][5].Y = 1;
	m_metricNode[1][5].number = 20;
	m_metricNode[1][5].color = PURPLE;
	m_metricNode[1][6].X = 6;
	m_metricNode[1][6].Y = 1;
	m_metricNode[1][6].number = 4;
	m_metricNode[1][6].color = BLUE;
	m_metricNode[1][7].X = 7;
	m_metricNode[1][7].Y = 1;
	m_metricNode[1][7].number = 20;
	m_metricNode[1][7].color = BLUE;
	m_metricNode[1][8].X = 8;
	m_metricNode[1][8].Y = 1;
	m_metricNode[1][8].number = 5;
	m_metricNode[1][8].color = BLUE;
	m_metricNode[1][9].X = 9;
	m_metricNode[1][9].Y = 1;
	m_metricNode[1][9].number = 20;
	m_metricNode[1][9].color = BLUE;

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
unsigned int MetricLogic::getLevel()
{
    return m_level;
}
unsigned int MetricLogic::getScore()
{
    return m_score;
}
unsigned int MetricLogic::getLine()
{
	return m_line; 
}
bool MetricLogic::isGameover()
{
    for (int i = 0; i < 10; i++)
    {
        if (m_maxposition[i] >= 23)
        {
            return true;
        }
    }
	return false;
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
	if (m_maxposition[a[i].X] < (a[i].Y+1))
    {
        m_maxposition[a[i].X] = a[i].Y+1;
	}
	}

    calcNodeScore(a);
	
}
void MetricLogic::calcNodeScore(T_MetricNode lineNode[])
{
	m_score += lineNode[0].number;
    m_score += lineNode[1].number;
    m_score += lineNode[2].number;
    m_score += lineNode[3].number;
}
void MetricLogic::memsetdismisscount()
{
	for (int i = 0; i< 10; i++)
	{
		dismisscount[i]=100;
	}
}
bool MetricLogic::dismissLine()
{
	int linecount = 0;
	int dismissnum = 0;
	bool toolvalid = false;
	bool tooldismiss = false;

	int templine = 0;
	T_MetricNode tempnode[24][10];
	for (int i = 0; i< 10; i++)
	{
		dismisscount[i]=100;
	}
	memset(&tempnode, 0xff, sizeof(tempnode));
    for (int i = 0; i<23; i++)
	{
		linecount = 0;
		toolvalid = false;
		for (int j = 0; j<10; j++)
		{
			if (m_metricNode[i][j].number < 10)
			{
				linecount++;
				if (m_metricNode[i][j].tools == 1)
				{
					toolvalid = true;
				}
			}
		}
		if (linecount == 10)
		{
			if (toolvalid)
			{
			    tooldismiss = true;
			}
			dismisscount[dismissnum]=i;
			dismissnum++;
			m_line++;
		}
		else
		{
			memcpy(&tempnode[templine], &m_metricNode[i], sizeof(T_MetricNode)*10);
			templine++;
		}
	}
	if (dismissnum > 0)
	{
    calcdismissScore(dismissnum);  //必须在memset之前算出来
	
	memset(&m_metricNode, 0xff, sizeof(m_metricNode));
	int dismissidx = 0;
	for (int i=0;i<24-dismissnum;i++)
	{
	    memcpy(&m_metricNode[i], &tempnode[i], sizeof(T_MetricNode)*10);

			for (int j = 0; j< 10; j++)
			{
				m_metricNode[i][j].Y=i;
			}


	}

	int maxposflag = 0;
		for (int m = 0; m<10; m++)
		{
			maxposflag = 0;
			for (int n = 22; n >= 0; n--)
			{
				if (m_metricNode[n][m].number < 10)
				{
					m_maxposition[m] = n+1;
					maxposflag = n+1;
					break;
				}
			}
			if (maxposflag == 0)
			{
				m_maxposition[m] = 0;
			}
		}

		//calcdismissScore(dismissnum);
		
	}
	return tooldismiss;	
}

void MetricLogic::calcdismissScore(int dismisslinenum)
{
    int continueincnum = 1;
	int cotinueincscore = 0;
	int continuedecnum = 1;
	int cotinuedecscore = 0;
	int samenum = 1;
	int samescore = 0;

	for (int i = 0; i < dismisslinenum; i++)
	{
     int line = dismisscount[i];
      for (int j = 0; j< 10; j++)
      {
          // 正常积分值
		  m_score += (m_metricNode[line][j].number * scoreTimes);
          // 数字连续递增积分，连续个数*number累计值
		  if ((j > 0) && (m_metricNode[line][j-1].number+1 == m_metricNode[line][j].number))
		  {
		      continueincnum++;
			  cotinueincscore += m_metricNode[line][j].number;
		  }
		  else
		  {
		      if (continueincnum >= 4)
		      {
		          cotinueincscore += m_metricNode[line][j-continueincnum].number;
		          m_score += (continueincnum* cotinueincscore*scoreTimes);
		      }
		      continueincnum = 1;
			  cotinueincscore = 0;
		  }
		  // 数字连续减少积分，连续个数*number累计值
		  if ((j > 0) && (m_metricNode[line][j-1].number-1 == m_metricNode[line][j].number))
		  {
		      continuedecnum++;
			  cotinuedecscore += m_metricNode[line][j].number;
		  }
		  else
		  {
		      if (continuedecnum >= 4)
		      {
		          cotinuedecscore += m_metricNode[line][j-continuedecnum].number;
		          m_score += (continuedecnum* cotinuedecscore*scoreTimes);
		      }
		      continuedecnum = 1;
			  cotinuedecscore = 0;
		  }
          // 连续相同积分，相同个数*number累计值
          if ((j > 0) && (m_metricNode[line][j-1].number == m_metricNode[line][j].number))
		  {
		      samenum++;
			  samescore += m_metricNode[line][j].number;
		  }
		  else
		  {
		      if (samenum >= 4)
		      {
		          samescore += m_metricNode[line][j-samenum].number;
		          m_score += (samenum* samescore*scoreTimes);
		      }
		      samenum = 1;
			  samescore = 0;
		  }
      }
      // 多行积分
	  //m_score *= dismisslinenum;
	
	}

   // 积分转换为等级
   for (int i = 0; i< sizeof(ScoretoLevel)/sizeof(unsigned int); i++)
   {
	   if (m_score > ScoretoLevel[i])
		   m_level = i;
   }

}

unsigned int* MetricLogic::getdismissline()
{
	return &dismisscount[0];
}
 
void MetricLogic::addNewNodefrombottom(int randnum)
{
   for (int i = 22; i>= 0; i--)
   {
        memcpy(&m_metricNode[i+1], &m_metricNode[i], sizeof(T_MetricNode)*10);

   }
   for (int i = 22; i > 0; i--)
   {
   		for (int j = 0; j < 10; j++)
		{
			if (m_metricNode[i][j].Y != 65535)
			{
			    m_metricNode[i][j].Y +=1;
			}
		}
   }
   for (int x = 0; x < 10; x++)
   {
       m_metricNode[0][x].number = 20;
   }

   int randgap[] = {0, 3, 5, 8, 9, 1, 2, 6, 4, 7};
   int posx;
   int number;
   int color;

   for (int x = 0; x< randnum; x++)
   {
	   posx = randgap[(randnum+x)%10];
	   number = (randnum+posx)%10;
	   color = (randnum+posx)%5;
	   m_metricNode[0][posx].number = number;
	   m_metricNode[0][posx].color = color;
	   m_metricNode[0][posx].tools = 20;
	   m_maxposition[posx]+=1;
   }
}
void MetricLogic::addNewNodefromup(int nodeonex, int nondtwox, int nodethreex,  int color, int number)
{
    m_metricNode[m_maxposition[nodeonex]][nodeonex].X = nodeonex;
	m_metricNode[m_maxposition[nodeonex]][nodeonex].Y = m_maxposition[nodeonex];
	m_metricNode[m_maxposition[nodeonex]][nodeonex].number = number;
    m_metricNode[m_maxposition[nodeonex]][nodeonex].color = color;	   
	m_metricNode[m_maxposition[nodeonex]][nodeonex].tools = 20;
	m_maxposition[nodeonex] +=1;
	m_metricNode[m_maxposition[nondtwox]][nondtwox].X = nondtwox;
	m_metricNode[m_maxposition[nondtwox]][nondtwox].Y = m_maxposition[nondtwox];
	m_metricNode[m_maxposition[nondtwox]][nondtwox].number = number;
    m_metricNode[m_maxposition[nondtwox]][nondtwox].color = color;	   
	m_metricNode[m_maxposition[nondtwox]][nondtwox].tools = 20;
	m_maxposition[nondtwox] +=1;
	m_metricNode[m_maxposition[nodethreex]][nodethreex].X = nodethreex;
	m_metricNode[m_maxposition[nodethreex]][nodethreex].Y = m_maxposition[nodethreex];
	m_metricNode[m_maxposition[nodethreex]][nodethreex].number = number;
    m_metricNode[m_maxposition[nodethreex]][nodethreex].color = color;	   
	m_metricNode[m_maxposition[nodethreex]][nodethreex].tools = 20;
	m_maxposition[nodethreex] +=1;
}

int  MetricLogic::getPosy(int posx)
{
	int randposy = 0;

	for (int i = m_maxposition[posx]; i >= 0 ; i--)
	{
		if (m_metricNode[i][posx].number < 10)
		{
			return i;
		}
	}
	return randposy;
}
void MetricLogic::setToolAttr(int toolposx, int toolposy)
{
	m_metricNode[toolposy][toolposx].tools = 1;
}
void MetricLogic::removeToolAttr(int toolposx, int toolposy)
{
	m_metricNode[toolposy][toolposx].tools = 0;

}
void MetricLogic::setScoreTimes(int times)
{
	scoreTimes = times;
}