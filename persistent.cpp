#include "persistent.h"

Persistent* Persistent::m_PersistentInst = 0;

Persistent* Persistent::getInstant()
{
    if (m_PersistentInst == 0)
    {
        //m_PersistentInst = new Persistent();
    }
	return m_PersistentInst;
}

bool Persistent::IsMusic()
{
    return isMusic;
}
bool Persistent::IsSound()
{
    return isSound;
}
bool Persistent::IsVibrate()
{
    return isVibrate;
}
T_MetricNode* Persistent::getMetricNode()
{
    return &m_metricNode[0][0];
}
T_MetricNode* Persistent::getActiveNode()
{
    return &m_activeNode[0];
}
unsigned char* Persistent::getMaxPos()
{
    return &m_maxposition[0];
}
unsigned int Persistent::getLevel()
{
    return level;
}
unsigned int Persistent::getScore()
{
    return score;
}
unsigned int Persistent::getLine()
{
    return line;
}