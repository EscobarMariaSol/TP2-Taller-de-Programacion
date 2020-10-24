#include "node.h"

/*********************** Funciones Auxiliares de Node ************************/


/*********************** Métodos Públicos de Node ****************************/

Node::Node(const std::string name): neighbors() {
    this->name = name;
}

Node::~Node(){
}

std::string Node::getName() const {
    return this->name;
}

std::list<Node> Node::getNeighbors() const {
    return this->neighbors;
}

int Node::addNeighbour(Node& neighbour) {
    this->neighbors.push_back(neighbour);
    return 0;
}