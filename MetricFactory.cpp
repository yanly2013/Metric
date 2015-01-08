#include "MetricFactory.h"
#include "squareNode.h"

ActiveNode* MetricFactory::create(NodeType nodetype)
{
	if (nodetype == SQUARE)
	{
		return new SquareNode();
	}
}