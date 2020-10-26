#include "graph.h"

/*********************** Funciones Auxiliares de Graph ************************/

std::list<Node>::iterator findNode(std::list<Node>& nodos, const std::string id) {
    for (std::list<Node>::iterator it = nodos.begin(); 
                it != nodos.end(); ++it) {
        if (it->getId().compare(id) == 0) return it;       
    }
    return nodos.end();
}
/*********************** Métodos Públicos de Graph ****************************/

Graph::Graph(): nodes(std::list<Node>()) {
}

Graph::~Graph() {
}

int Graph::getSize() const {
    return this->nodes.size();
}

std::list<Node> Graph::getNodes() const {
    return this->nodes;
}

int Graph::addNode(Node& node) {
    this->nodes.push_back(node);
    return 0;
}

Node& Graph::getNode(const std::string id) { 
    return *findNode(this->nodes, id);
}

bool Graph::containsNode(const std::string id) {
    return (findNode(this->nodes, id) != this->nodes.end());
}
