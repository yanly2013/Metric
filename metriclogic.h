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
	unsigned char conflidpoint;
}T_MetricNode;

class MetricLogic
{
public:
	void init();
    T_MetricNode* getmetricnode();


private:
	T_MetricNode m_metricNode[30][10];



};

#endif