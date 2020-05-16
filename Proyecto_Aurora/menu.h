#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <vector>
#include "node.h"
#include "vertex.h"

class Menu
{
private:
    std::vector<node> nodeList;
    std::vector<vertex> vertexList;
public:
    Menu();
    void menu();
    void AddGraph();
    void EditNode();
    void NewNode();
    void ShowNodes();
    void NewVertex();
    bool isUsed(const std::string &name);

};

#endif // MENU_H
