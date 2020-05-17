#ifndef NODE_H
#define NODE_H
#include <vector>
#include <string>

class node
{
public:
    node();

    std::string getName() const;
    void setName(const std::string &value);
private:
    std::string name;
};

#endif // NODE_H
