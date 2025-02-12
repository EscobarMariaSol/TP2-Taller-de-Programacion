#include "dfs.h"

/*********************** Función Auxiliares de Dfs****************************/

// Función que indica si un nodo ya ha sido visitado
// Pre: recibe una referencia al set de nodos vistados y a un nodo
// Pos: devuelve verdadero o falso según si el nodo se encuentra
// dentro del set de nodos visitados
static bool wasVisited(std::set<Node>& visited, const Node& actual) {
    return (visited.find(actual) != visited.end());
}

// Función que indica si un nodo puede volver hacia atrás en el recorrido
// generando así un ciclo en el grafo
// Pre: recibe una referencia a un grafo, los vecinos del nodo y el set
// de nodos visitados
// Pos: devuelve verdadero si el nodo actual puede cerrar un ciclo o
// falso en caso contrario
static bool canGoBack(Graph& graph, const std::set<Node>& neighbors , 
                    std::set<Node>& visited) {
    for (std::set<Node>::iterator it = neighbors.begin(); 
            it != neighbors.end(); ++it) {
        if (visited.find(graph.getNode(it->getId())) != visited.end()) 
            return true;
    }
    return false;
}

/*********************** Métodos Privados de Dfs******************************/

int Dfs::visit(Graph& graph, Node& actual, std::set<Node>& visited) { 
    std::stack<Node> stack; 
    stack.push(actual); 
    while (!stack.empty()) { 
        actual = stack.top(); 
        stack.pop(); 
        visited.insert(actual); 
        std::set<Node> neighbors = actual.getNeighbors();
        for (std::set<Node>::iterator it = neighbors.begin(); 
            it != neighbors.end(); ++it) {
            Node child = graph.getNode(it->getId());
            if (wasVisited(visited, (*it)) && 
                canGoBack(graph, child.getNeighbors(), visited)){
                return -1;
            }
            stack.push(child);
        }
    }
    return 0; 
}

/*********************** Métodos Públicos de Dfs******************************/

Dfs::Dfs(): cycle(false), unusedInstructions(false) {
}

Dfs::~Dfs() {
}

int Dfs::walkGraph(Graph& graph) {
    std::set<Node> visited;
    if (graph.getSize() > 0) {
        Node actual = graph.getFirst();
        if (visit(graph, actual, visited) < 0) 
            this->cycle = true;
        else if (visited.size() < graph.getSize())
            this->unusedInstructions = true;
    }
    return 0;
}

bool Dfs::hasCycle() const {
    return this->cycle;
}

bool Dfs::hasUnusedInstructions() const {
    return this->unusedInstructions;
}
