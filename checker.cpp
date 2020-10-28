#include "checker.h"

/*********************** Funciones Privadas de Checker *********************/

void Checker::setResult(Dfs& dfs) {
    if (dfs.hasCycle()) this->result = "FAIL: cycle detected";
    else if (dfs.hasUnusedInstructions()) 
        this->result = "FAIL: unused instructions detected";
    else 
        this->result = "GOOD";
}

/*********************** Métodos Públicos de Checker *************************/

Checker ::Checker(): result() {
}

Checker ::~Checker() {
}

int Checker::verifyFile(const std::string path) {
    Graph graph;
    GraphGenerator generator(path);
    Dfs dfs;
    if ((generator.generateGraph(graph) < 0) || (dfs.walkGraph(graph) < 0))
        return -1;
    setResult(dfs);
    return 0;
}

std::string Checker::getResult() const {
    return this->result;
}