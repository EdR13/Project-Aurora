#include "node.h"

node::node()
{

}

std::string node::getName() const
{
    return name;
}

void node::setName(const std::string &value)
{
    name = value;
}
