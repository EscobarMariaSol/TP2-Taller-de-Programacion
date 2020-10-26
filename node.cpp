#include "node.h"

/*********************** Funciones Auxiliares de Node ************************/


/*********************** Métodos Públicos de Node ****************************/

Node::Node(const std::string id):
                                id(id), 
                                neighbors(std::list<Node>()) {
}

Node::~Node(){
}

std::string Node::getId() const {
    return this->id;
}

std::list<Node> Node::getNeighbors() const {
    return this->neighbors;
}

void Node::addNeighbour(Node& neighbour) {
    this->neighbors.push_back(neighbour);

}

bool Node::operator==(const Node& other) const {
    return (this->id.compare(other.getId()) == 0);      
}

bool Node::operator<(const Node& other) const {
    return (this->id.compare(other.getId()) < 0);      
}