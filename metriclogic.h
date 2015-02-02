#ifndef __METRIC_LOGIC_H__
#define __METRIC_LOGIC_H__

#include <string>
typedef enum color
{
	BLUE,
	RED,
	YELLOW,
	PURPLE,
	GREEN
}NodeColor;

const unsigned short XLogictoPhysic[10] = 
{
	45, 65, 85, 105, 125, 145, 165, 185, 205, 225
};
const unsigned short YLogictoPhysic[24]	=
{
	135, 155, 175, 195, 215, 235, 255, 275, 295, 315, 
	335, 355, 375, 395, 415, 435, 455, 475, 495, 515,
	535, 555, 575, 595
};
const unsigned int ScoretoLevel[10] = 
{
	1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000
};


std::string SpriteNodeName[5][2] = 
{
	"nodeblue.png", "nodeblue.png",
	"nodered.png", "nodered.png",
	"nodeyellow.png", "nodeyellow.png",
	"nodepurple.png", "nodepurple.png",
	"nodegreen.png", "nodegreen.png"
};


typedef struct 
{
	unsigned short X;
	unsigned short Y;
	unsigned short number;
	unsigned short color;
	unsigned short tools;
}T_MetricNode;

class MetricLogic
{
public:
	void init();
    T_MetricNode* getmetricnode();
	unsigned char*  getmaxposition();
	void addnewNode(T_MetricNode a[4]);
	void dismissLine();
	unsigned int getLevel();
	unsigned int getScore();
	unsigned int getLine();
	bool isGameover();

	unsigned int* getdismissline();


private:
	void calcdismissScore(int dismisslinenum);
	void calcNodeScore(T_MetricNode lineNode[]);
	T_MetricNode m_metricNode[24][10];
	unsigned char m_maxposition[10];

	unsigned int m_level;
	unsigned int m_score;
    unsigned int m_line;

	unsigned int dismisscount[10];



};

#endif