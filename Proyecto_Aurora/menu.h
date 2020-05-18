#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <vector>
#include "node.h"
#include "edge.h"

class Menu
{
private:
    std::vector<node> nodeList;
    std::vector<edge> edgeList;
public:
    Menu();
    void menu();
    void AddGraph();
    void EditNode();
    void NewNode();
    void ShowNodes();
    void NewEdge();
    void ShowEdges();
    void Prim();
    void Dijkstra();
    bool isUsed(const std::string &name);

};

#endif // MENU_H
