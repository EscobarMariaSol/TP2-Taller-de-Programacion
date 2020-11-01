#include "graph.h"

/*********************** Funciones Auxiliares de Graph ************************/

// Función que busca un nodo en la lista de nodos del grafo, de acuerdo a su id
// Pre: recibe una referencia a la lista de nodos del grafo y un id
// Pos: devuelve un elemento iterator que contiene al nodo en caso de ser 
// encontrado o una referencia al fin de la lista en caso contrario.
static std::list<Node>::iterator findNode(
    std::list<Node>& nodos, const std::string id) {
    for (std::list<Node>::iterator it = nodos.begin(); 
                it != nodos.end(); ++it) {
        if (it->getId().compare(id) == 0) return it;       
    }
    return nodos.end();
}
/*********************** Métodos Públicos de Graph ****************************/

Graph::Graph(): nodes() {
}

Graph::~Graph() {
}

size_t Graph::getSize() const {
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

Node& Graph::getFirst() {
    return this->nodes.front();
}
