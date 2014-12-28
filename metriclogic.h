#ifndef __METRIC_LOGIC_H__
#define __METRIC_LOGIC_H__

typedef enum color
{
	RED,
	YELLOW,
	PURPLE
}NodeColor;


typedef struct 
{
	unsigned char X;
	unsigned char Y;
	unsigned char number;
	unsigned char color;
	unsigned char tools;
}T_MetricNode;

class MetricLogic
{
public:
	void init();
	void moveLeft();
	void moveRight();
	void moveDown();
	void quickDown();
	void rotate();


private:
	T_MetricNode m_metricNode[30][10];



};

#endif