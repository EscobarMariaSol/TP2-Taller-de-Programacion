#ifndef GRAPH_GENERATOR_H
#define GRAPH_GENERATOR_H

#include "file_parser.h"
#include "graph.h"
#include "line_map.h"

class GraphGenerator {

private:
    FileParser parser;

public:
    GraphGenerator(const std::string path);
    ~GraphGenerator();
    Graph generateGraph();
};

#endif //GRAPH_GENERATOR_H
