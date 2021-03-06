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
	40, 60, 80, 100, 120, 140, 160, 180, 200, 220
};
const unsigned short YLogictoPhysic[24]	=
{
	135, 155, 175, 195, 215, 235, 255, 275, 295, 315, 
	335, 355, 375, 395, 415, 435, 455, 475, 495, 515,
	535, 555, 575, 595
};

const unsigned short XNextNodePos[4] = 
{
    265, 285, 305, 325
};
const unsigned short YNextNodePos[3] = 
{
    530, 510, 490
};
const unsigned int ScoretoLevel[] = 
{
	//0, 0, 50, 100, 150, 200, 250, 300, 400, 500, 600, 700, 800, 900, 1000
	0, 0, 5000, 20000, 40000, 60000, 80000, 100000, 150000, 200000, 250000, 300000, 400000, 600000, 1000000
};

const float leveltotime[] = 
{
    1.0f, 1.0f, 1.0f, 0.9f, 0.8f, 0.7f, 0.6f, 0.5f, 0.45f, 0.4f, 0.35f, 0.3f, 0.25f, 0.2f, 0.15f
};


const char* const SpriteNodeName[5][11] = 
{
	"blue0node.png","blue1node.png", "blue2node.png","blue3node.png", "blue4node.png","blue5node.png", "blue6node.png","blue7node.png", "blue8node.png", "blue9node.png","bluenode.png", 
	"red0node.png", "red1node.png","red2node.png", "red3node.png","red4node.png", "red5node.png","red6node.png", "red7node.png","red8node.png", "red9node.png","rednode.png",
	"yellow0node.png", "yellow1node.png","yellow2node.png", "yellow3node.png","yellow4node.png", "yellow5node.png","yellow6node.png", "yellow7node.png","yellow8node.png", "yellow9node.png","yellownode.png", 
	"purple0node.png", "purple1node.png","purple2node.png", "purple3node.png","purple4node.png", "purple5node.png","purple6node.png", "purple7node.png","purple8node.png", "purple9node.png","purplenode.png",
	"green0node.png", "green1node.png","green2node.png", "green3node.png","green4node.png", "green5node.png","green6node.png", "green7node.png","green8node.png", "green9node.png","greennode.png"
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
	bool dismissLine();
	unsigned int getLevel();
	unsigned int getScore();
	unsigned int getLine();
	bool isGameover();
	void memsetdismisscount();
	unsigned int* getdismissline();
	void addNewNodefrombottom(int randnum);
    void addNewNodefromup(int nodeonex, int nondtwox, int nodethreex, int color, int number);
	int getPosy(int posx);
	void setToolAttr(int toolposx, int toolposy);
	void removeToolAttr(int toolposx, int toolposy);
	void setScoreTimes(int times);

private:

	void calcdismissScore(int dismisslinenum);
	void calcNodeScore(T_MetricNode lineNode[]);


	T_MetricNode m_metricNode[24][10];
	unsigned char m_maxposition[10];

	unsigned int m_level;
	unsigned int m_score;
    unsigned int m_line;

	unsigned int dismisscount[10];

	int scoreTimes;



};

#endif