#ifndef GRAPH_GENERATOR_H
#define GRAPH_GENERATOR_H

#include "file_parser.h"
#include "graph.h"
#include "line_map.h"
#include <map>
#include <set>
#include <string>
#include <utility>

// Clase encargada de crear un grafo a partir del archivo que se le pasa
// Cuenta con un único atributo correspondiente al parser encargado de
// convertir las lineas del archivo en información de fácil manipulación
// para la creación del grafo.
class GraphGenerator {

private:
    FileParser parser;
    // Método que agrega lee el archivo y genera los nodos para 
    // agregarlos al grafo
    // Pre: recibe una referencia al grafo y un seT donde se guardan 
    // las aristas del grafo
    // Pos: devuelve 0 si los nodos han sido agregados al grafo, -1 en 
    // caso de algún error
    int addNodes(Graph& new_graph, 
        std::map<Node, std::set<std::string>>& edges);
    // Método que agrega aristas al grafo, colocando en cada nodo una
    // referencia a sus correspondiente vecinos
    // Pre: recibe una referencia al grafo y al set de aristas que se han
    // identificado al momento de agregar los nodos
    // Pos: devuelve 0 encaso de agregar todas las arista correctamente o
    // -1 en caso de que suceda algún error
    int addEdges(Graph& new_graph, 
        std::map<Node, std::set<std::string>>& edges);

public:
    // Constructor
    explicit GraphGenerator(const std::string path);
    // Destructor
    ~GraphGenerator();
    // Método que se encarga de generar un grafo
    // Pre: recibe una referencia al nuevo grafo en el cual se
    // deben insertar los nodos
    // Pos: devuelve 0 en caso de haberse generado el grafo correctamente
    // o -1 en caso de que suceda algún error
    int generateGraph(Graph& new_graph);
};

#endif //GRAPH_GENERATOR_H
