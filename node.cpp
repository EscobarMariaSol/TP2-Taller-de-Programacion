#include "node.h"


/*********************** Métodos Públicos de Node ****************************/

Node::Node(const std::string id): id(id), neighbors() {
}

Node::~Node(){
}

std::string Node::getId() const {
    return this->id;
}

std::set<Node> Node::getNeighbors(){
    return this->neighbors;
}

int Node::addNeighbour(Node& neighbour) {
    if ((this->neighbors.insert(neighbour).second == false) &&
        (this->neighbors.find(neighbour) == this->neighbors.end())) {
        return -1;
    }
    return 0;
}

bool Node::operator==(const Node& other) const {
    return (this->id.compare(other.getId()) == 0);      
}

bool Node::operator<(const Node& other) const {
    return (this->id.compare(other.getId()) < 0);      
}
