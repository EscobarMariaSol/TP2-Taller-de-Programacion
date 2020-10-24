#ifndef GRAFO_H
#define GRAFO_H

#include "node.h"


class Graph {

private:
    std::list<Node> nodes;
    
public:
    Graph();
    ~Graph();
    int getSize() const;
    std::list<Node> getNodes() const;
    int addNode(Node& node);
};

#endif //GRAFO_H