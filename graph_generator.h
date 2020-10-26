#ifndef GRAPH_GENERATOR_H
#define GRAPH_GENERATOR_H

#include "file_parser.h"
#include "graph.h"
#include "line_map.h"

class GraphGenerator {

private:
    FileParser parser;
    void addNodes(Graph& new_graph, std::map<Node, std::list<std::string>>& edges);
    void addEdges(Graph& new_graph, std::map<Node, std::list<std::string>>& edges);

public:
    GraphGenerator(const std::string path);
    ~GraphGenerator();
    Graph generateGraph();
};

#endif //GRAPH_GENERATOR_H
