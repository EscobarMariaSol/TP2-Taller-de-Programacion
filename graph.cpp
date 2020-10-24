#include "graph.h"


Graph::Graph(): nodes() {
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