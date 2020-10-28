#include "dfs.h"

/*********************** Funciones Auxiliares de Dfs**************************/

bool wasVisited(std::list<Node>& visited, const Node& actual) {
    for (std::list<Node>::iterator it = visited.begin(); 
            it != visited.end(); ++it) {
        if (it->getId() == actual.getId()) return true;
    }
    return false;
}
/*********************** Métodos Privados de Dfs******************************/

int Dfs::visit(Graph& graph, Node& actual, std::list<Node>& visited) { 
    std::stack<Node> stack; 
    stack.push(actual); 
    while (!stack.empty()) { 
        actual = stack.top(); 
        stack.pop(); 
        if (!wasVisited(visited, actual)) visited.push_back(actual); 
        std::set<Node> neighbors = actual.getNeighbors();
        for (std::set<Node>::iterator it = neighbors.begin(); 
            it != neighbors.end(); ++it) {
            if (!wasVisited(visited, (*it)))
                stack.push(graph.getNode((*it).getId())); 
        }
    }
    return 0; 
}

/*********************** Métodos Públicos de Dfs**** *************************/

Dfs::Dfs(): cycle(false), unusedInstructions(false) {
}

Dfs::~Dfs() {
}

int Dfs::walkGraph(Graph& graph) {
    std::list<Node> visited;
    if (graph.getSize() > 0) {
        Node actual = graph.getFirst();
        visit(graph, actual, visited);
        if (!this->cycle && (visited.size() < graph.getSize())) {
            this->unusedInstructions = true;
        }
    }
    return 0;
}

bool Dfs::hasCycle() const {
    return this->cycle;
}

bool Dfs::hasUnusedInstructions() const {
    return this->unusedInstructions;
}