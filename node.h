#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <string>
#include <set>

class Node {

private:
    std::string id;
    std::set<Node> neighbors;

public:
    Node(const std::string id);
    ~Node();
    std::string getId() const;
    std::set<Node> getNeighbors() const;
    int addNeighbour(Node& neighbour);
    bool operator<(const Node& other) const;
    bool operator==(const Node& other) const;
};

#endif //NODO_H
