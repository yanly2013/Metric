#include "MetricFactory.h"
#include "squareNode.h"
#include "lineNode.h"
#include "onethreeNode.h"
#include "threeoneNode.h"
#include "twotwoleftNode.h"
#include "twotworightNode.h"
#include "ttypeNode.h"

ActiveNode* MetricFactory::create(NodeType nodetype)
{
	switch (nodetype)
	{
	case SQUARE:
		return new SquareNode();
	case LINE:
		return new LineNode();
	case ONETHREE:
		return new OneThreeNode();
	case THREEONE:
		return new ThreeOneNode();
	case TWOTWOLEFT:
		return new TwoTwoLeftNode();
	case TWOTWORIGHT:
		return new TwoTwoRightNode();
	case TTYPE:
		return new TTypeNode();
	}
}