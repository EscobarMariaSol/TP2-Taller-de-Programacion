#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <string>
#include <list>

class Node {

private:
    std::string id;
    std::list<Node> neighbors;

public:
    Node(const std::string id);
    ~Node();
    std::string getId() const;
    std::list<Node> getNeighbors() const;
    void addNeighbour(Node& neighbour);
    bool operator<(const Node& other) const;
    bool operator==(const Node& other) const;
};

#endif //NODO_H
