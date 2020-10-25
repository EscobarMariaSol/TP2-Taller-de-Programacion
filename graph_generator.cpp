#include "graph_generator.h"

/**************** Funciones Auxiliares de GraphGenerator *********************/
std::string generateNodeId(LineMap& line_map, int& count) {
    if (!line_map.getTagId().empty()) {
        return line_map.getTagId();
    }
    count++;
    return (std::to_string(count));
}

void addNeighbors(Node& node, Graph& graph, std::set<std::string> nghbrs) {
    for (std::set<std::string>::iterator it=nghbrs.begin(); 
        it != nghbrs.end(); ++it) {
        if (graph.containsNode(*it)) {
            Node neighbour = graph.getNode(*it);
            node.addNeighbour(neighbour);
        }
    }
}

/**************** Métodos Públicos de GraphGenerator *************************/

GraphGenerator::GraphGenerator(const std::string path): parser(path) {
}

GraphGenerator::~GraphGenerator() {
}

Graph GraphGenerator::generateGraph() {
    Graph new_graph;
    int count = 0;
    Node *prev = nullptr;
    LineMap line_map = this->parser.parseLine();
    while (!line_map.isEmpty()) {
        std::string id = generateNodeId(line_map, count);
        std::set<std::string> neighbors = line_map.getNeighbors();
        if (prev != nullptr) neighbors.insert((*prev).getId()); 
        Node new_node(id);
        if (!neighbors.empty()) addNeighbors(new_node, new_graph, neighbors);
        if (line_map.isARet()) prev = nullptr;
        else
            prev = &new_node;
        new_graph.addNode(new_node);
        line_map = this->parser.parseLine();
    }
    return new_graph;
} 