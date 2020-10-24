#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <string>
#include <list>

class Node {

private:
    std::string name;
    std::list<Node> neighbors;

public:
    Node(const std::string name);
    ~Node();
    std::string getName() const;
    std::list<Node> getNeighbors() const;
    int addNeighbour(Node& neighbour);
};

#endif //NODO_H
