#ifndef GRAFO_H
#define GRAFO_H

#include "node.h"
#include <list>


class Graph {

private:
    std::list<Node> nodes;
    
public:
    Graph();
    ~Graph();
    size_t getSize() const;
    std::list<Node> getNodes() const;
    int addNode(Node& node);
    Node& getNode(const std::string id);
    bool containsNode(const std::string id);
    Node& getFirst();
};

#endif //GRAFO_H