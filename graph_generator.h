#ifndef GRAPH_GENERATOR_H
#define GRAPH_GENERATOR_H

#include "file_parser.h"
#include "graph.h"

class GraphGenerator {

private:
    FileParser parser;

public:
    GraphGenerator(std::string path);
    ~GraphGenerator();
    Graph generateGraph();
};

#endif //GRAPH_GENERATOR_H
