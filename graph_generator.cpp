#include "graph_generator.h"

/**************** Funciones Auxiliares de GraphGenerator *********************/

// Función que genera un id para un nodo a partir de la información almacenada
// dentro del line map y la cantidad de nodos agregados
// Pre: recibe una referencia al lineMap y un contador correspondiente a la
// cantidad de nodos que existen en el grafo
// Pos: si el nodo corresponde a una etiqueta, su id será el nombre de la
// etiqueta, sino se le asigna un número que depende de la cantidad de 
// nodos existentes en el grafo.
static std::string generateNodeId(LineMap& line_map, int& count) {
    if (!line_map.getTagId().empty()) {
        return line_map.getTagId();
    }
    count++;
    return (std::to_string(count));
}

// Método que agrega a un nodo las refencias a sus vecinos
// Pre: recibe un id de un nodo, el grafo y los id de sus vecinos
// Pos: devuelve 0 en caso de haberse agregado todos los vecinos
// correctamente o -1 en caso de algún error
static int addNeighbors(
    std::string nodeId, Graph& graph, std::set<std::string>& nghbrs) {
    for (std::set<std::string>::iterator it=nghbrs.begin(); 
        it != nghbrs.end(); ++it) {
        if (graph.containsNode(*it)) {
            Node neighbour = graph.getNode(*it);
            if (graph.getNode(nodeId).addNeighbour(neighbour) < 0)
                return -1;
        }
    }
    return 0;
}

// Método que chequea si el nodo actual es vecino del previo, si es así
// lo asigna como vecino y luego asigna al actual como el nuevo previo
// Pre: recibe una referencia al grafo, al line map, al id del nodo previo
// y al nuevo nodo
// Pos: devuelve 0 en caso de haber actualizado correctamente el nodo previo
// o -1 en caso de algún error
static int changePrev(Graph& new_graph, 
    LineMap& line_map, std::string& prev_id, Node& new_node) {
    if (!prev_id.empty()) {
        if (new_graph.getNode(prev_id).addNeighbour(new_node) < 0)
            return -1;
    }
    if (line_map.canGoToTheNexLine()) prev_id = new_node.getId();
    else
        prev_id = "";
    return 0;
}

// Método que guarda el id de los vecinos de un nodo 
// Pre: recibe una referencia al nodo, el LineMap asociado y el set de aristas
// Pos: devuelve 0 en caso de haber agregado los correspondientes vecinos de 
// manera exitosa o -1 en caso de algún error
static int insertNeighbors(Node& new_node, LineMap& line_map, 
    std::map<Node, std::set<std::string>>& edges) {
    if (edges.insert(std::pair<Node, std::set<std::string>>(
                new_node, line_map.getNeighbors())).second == false) return -1;
    return 0;
}
/**************** Métodos Privados de GraphGenerator *************************/

int GraphGenerator::addNodes(Graph& new_graph, 
    std::map<Node, std::set<std::string>>& edges) {
    int count = 0;
    std::string prev;
    LineMap line_map;
    do {
        if (!(line_map = this->parser.parseLine()).isEmpty()) {
            Node new_node(generateNodeId(line_map, count));
            if (changePrev(new_graph, line_map, prev, new_node) < 0) return -1;
            new_graph.addNode(new_node);
            if (insertNeighbors(new_node, line_map, edges) < 0) return -1;
        }
    } while (this->parser.hasLine() && line_map.isValid());
    if (!line_map.isValid()) return -1;
    return 0;
}

int GraphGenerator::addEdges(Graph& new_graph, 
                            std::map<Node, std::set<std::string>>& edges) {
    for (std::map<Node, std::set<std::string>>::iterator it=edges.begin();
        it != edges.end(); ++it) {
        if (addNeighbors(it->first.getId(), new_graph, it->second) < 0)
            return -1;
    }
    return 0;
}

/**************** Métodos Públicos de GraphGenerator *************************/

GraphGenerator::GraphGenerator(const std::string path): parser(path) {
}

GraphGenerator::~GraphGenerator() {
}

int GraphGenerator::generateGraph(Graph& new_graph) {
    std::map<Node, std::set<std::string>> edges;
    if (addNodes(new_graph, edges) < 0) return -1;
    if (addEdges(new_graph, edges) < 0) return -1;
    return 0;
} 
