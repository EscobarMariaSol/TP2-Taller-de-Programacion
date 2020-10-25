#include "node.h"

/*********************** Funciones Auxiliares de Node ************************/


/*********************** Métodos Públicos de Node ****************************/

Node::Node(const std::string id): neighbors() {
    this->id = id;
}

Node::~Node(){
}

std::string Node::getId() const {
    return this->id;
}

std::set<Node> Node::getNeighbors() const {
    return this->neighbors;
}

int Node::addNeighbour(Node& neighbour) {
    this->neighbors.insert(neighbour);
    return 0;
}

bool Node::operator==(const Node &other) const {
    return (this->id.compare(other.getId()) == 0);      
}

bool Node::operator<(const Node &other) const {
    return (this->id.compare(other.getId()) < 0);      
}