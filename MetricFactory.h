#ifndef __METRIC_FACTORY_H__
#define __METRIC_FACTORY_H__

#include "activeNode.h"
class ActiveNode;

class MetricFactory
{
public:
	ActiveNode* create(NodeType nodetype);

private:
};


#endif