#ifndef __PERSISTENT_H_
#define __PERSISTENT_H

#include "Metriclogic.h"

class Persistent
{
public:
   static Persistent* getInstant();
   bool IsMusic();
   bool IsSound();
   bool IsVibrate();
   T_MetricNode* getMetricNode();
   T_MetricNode* getActiveNode();
   unsigned char* getMaxPos();
   unsigned int getLevel();
   unsigned int getScore();
   unsigned int getLine();
protected:
	Persistent();
private:
    static Persistent* m_PersistentInst;
	
    bool isMusic;
	bool isSound;
	bool isVibrate;
	T_MetricNode m_metricNode[24][10];
	unsigned char m_maxposition[10];
	T_MetricNode m_activeNode[4];
	unsigned int level;
	unsigned int score;
	unsigned int line;
	
};

#endif
