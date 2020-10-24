#include "graph_generator.h"

GraphGenerator::GraphGenerator(std::string path): parser(path) {
}

GraphGenerator::~GraphGenerator() {
}

Graph GraphGenerator::generateGraph() {
    Graph new_graph;
    std::map<std::string, std::string> line_map;
    while (!(line_map = this->parser.parseLine()).empty()) {
        
    }
    return new_graph;
}