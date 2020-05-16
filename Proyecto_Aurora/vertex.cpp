#include "vertex.h"

vertex::vertex()
{

}

int vertex::getWeight() const
{
    return Weight;
}

void vertex::setWeight(int value)
{
    Weight = value;
}

int vertex::getSourceNode() const
{
    return SourceNode;
}

void vertex::setSourceNode(int value)
{
    SourceNode = value;
}

int vertex::getTargetNode() const
{
    return TargetNode;
}

void vertex::setTargetNode(int value)
{
    TargetNode = value;
}
