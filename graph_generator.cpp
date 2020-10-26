#include "graph_generator.h"

/**************** Funciones Auxiliares de GraphGenerator *********************/
std::string generateNodeId(LineMap& line_map, int& count) {
    if (!line_map.getTagId().empty()) {
        return line_map.getTagId();
    }
    count++;
    return (std::to_string(count));
}

void addNeighbors(std::string nodeId, Graph& graph, std::list<std::string>& nghbrs) {
    for (std::list<std::string>::iterator it=nghbrs.begin(); 
        it != nghbrs.end(); ++it) {
        if (graph.containsNode(*it)) {
            Node neighbour = graph.getNode(*it);
            graph.getNode(nodeId).addNeighbour(neighbour);
        }
    }
}

void setPrevNode(Graph& new_graph, LineMap& line_map, 
                std::string& prev_id, Node& new_node) {
    if (!prev_id.empty()) new_graph.getNode(prev_id).addNeighbour(new_node);
    if (line_map.canGoToTheNexLine()) prev_id = new_node.getId();
    else
        prev_id = "";
}

/**************** Métodos Privados de GraphGenerator *************************/

void GraphGenerator::addNodes(Graph& new_graph, 
                            std::map<Node, std::list<std::string>>& edges) {
    int count = 0;
    std::string prev_id;
    LineMap line_map;
    do {
        line_map = this->parser.parseLine();
        if (!line_map.isEmpty()) {
            std::string id = generateNodeId(line_map, count);
            Node new_node(id);
            setPrevNode(new_graph, line_map, prev_id, new_node);
            new_graph.addNode(new_node);
            edges.insert(
                std::pair<Node, std::list<std::string>>(
                    new_node, line_map.getNeighbors()));
        }
    } while (this->parser.hasLine());
}

void GraphGenerator::addEdges(Graph& new_graph, 
                            std::map<Node, std::list<std::string>>& edges) {
    for (std::map<Node, std::list<std::string>>::iterator it=edges.begin();
        it != edges.end(); ++it) {
        addNeighbors(it->first.getId(), new_graph, it->second);
    }
}

/**************** Métodos Públicos de GraphGenerator *************************/

GraphGenerator::GraphGenerator(const std::string path): parser(path) {
}

GraphGenerator::~GraphGenerator() {
}

Graph GraphGenerator::generateGraph() {
    Graph new_graph;
    std::map<Node, std::list<std::string>> edges;
    addNodes(new_graph, edges);
    addEdges(new_graph, edges);
    return new_graph;
} 