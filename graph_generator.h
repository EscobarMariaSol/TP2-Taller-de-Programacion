#ifndef GRAPH_GENERATOR_H
#define GRAPH_GENERATOR_H

#include "file_parser.h"
#include "graph.h"
#include "line_map.h"

class GraphGenerator {

private:
    FileParser parser;
    int addNodes(Graph& new_graph, std::map<Node, std::set<std::string>>& edges);
    int addEdges(Graph& new_graph, std::map<Node, std::set<std::string>>& edges);

public:
    GraphGenerator(const std::string path);
    ~GraphGenerator();
    int generateGraph(Graph& new_graph);
};

#endif //GRAPH_GENERATOR_H
