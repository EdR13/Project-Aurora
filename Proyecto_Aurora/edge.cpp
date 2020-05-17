#include "edge.h"

edge::edge()
{

}

int edge::getWeight() const
{
    return Weight;
}

void edge::setWeight(int value)
{
    Weight = value;
}

int edge::getSourceNode() const
{
    return SourceNode;
}

void edge::setSourceNode(int value)
{
    SourceNode = value;
}

int edge::getTargetNode() const
{
    return TargetNode;
}

void edge::setTargetNode(int value)
{
    TargetNode = value;
}

bool edge::getBidirectional() const
{
    return bidirectional;
}

void edge::setBidirectional(bool value)
{
    bidirectional = value;
}
