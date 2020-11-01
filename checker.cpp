#include "checker.h"

/*********************** Funciones Privadas de Checker *********************/

void Checker::setResult(Dfs& dfs) {
    if (dfs.hasCycle()) this->result = "FAIL: cycle detected";
    else if (dfs.hasUnusedInstructions()) 
        this->result = "FAIL: unused instructions detected";
    else 
        this->result = "GOOD";
}

std::string Checker::createOutput(std::string& path) {
    std::string output;
    size_t index = path.find_last_of('/') + 1;
    if (index != std::string::npos) 
        output += (path.substr(index) + " " + this->result);
    else 
        output += (path + " " + this->result);
    return output;
}
/*********************** Métodos Públicos de Checker *************************/

Checker ::Checker(FileRepository& file_repo, OutputRepository& output_repo) : 
    file_repo(file_repo), output_repo(output_repo) {
}

Checker ::~Checker() {
}

void Checker::verifyFile() {
    std::string output;
    std::string path;
    while (!(path = this->file_repo.getFile()).empty()) {
        Graph graph;
        GraphGenerator generator(path);
        Dfs dfs;
        if ((generator.generateGraph(graph) < 0) || (dfs.walkGraph(graph) < 0)) 
            return;
        setResult(dfs);
        output = createOutput(path);
        if (output.empty() || (this->output_repo.addOutput(output) < 0)) return;
    }
}
