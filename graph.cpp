#include "graph.h"

/*********************** Funciones Auxiliares de Graph ************************/


/*********************** Métodos Públicos de Graph ****************************/

Graph::Graph(): nodes() {
}

Graph::~Graph() {
}

int Graph::getSize() const {
    return this->nodes.size();
}

std::set<Node> Graph::getNodes() const {
    return this->nodes;
}

int Graph::addNode(Node& node) {
    this->nodes.insert(node);
    return 0;
}

Node Graph::getNode(const std::string id) { 
    std::set<Node>::iterator it = this->nodes.find(id);
    return *it;
}

bool Graph::containsNode(const std::string id) {
    std::set<Node>::iterator it = this->nodes.find(id);
    return (it != this->nodes.end());
}

