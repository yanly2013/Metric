#include "MetricFactory.h"
#include "squareNode.h"
#include "lineNode.h"
#include "onethreeNode.h"
#include "threeoneNode.h"

ActiveNode* MetricFactory::create(NodeType nodetype)
{
	switch (nodetype)
	{
	case SQUARE:
	{
		return new SquareNode();
	}
	case LINE:
	{
		return new LineNode();
	}
	case ONETHREE:
	{
		return new OneThreeNode();
	}
	case THREEONE:
		return new ThreeOneNode();
	}
/*	{
	SQUARE,
	LINE,
    THREEONE,
	ONETHREE,
	TWOTWOLEFT,
	TWOTWORIGHT,
	TTYPE
}NodeType;*/
}