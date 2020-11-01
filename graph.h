#ifndef GRAFO_H
#define GRAFO_H

#include "node.h"
#include <list>
#include <string>

// Clase que representa un grafo almacendando las instrucciones
// del programa bpf como nodos
// Cuenta con único atributo que es una lista con los nodos
// pertenecientes al grafo
class Graph {
private:
    std::list<Node> nodes;
    
public:
    // Constructor
    Graph();
    // Destructor
    ~Graph();
    // Método que devuelve el tamaño del grafo, es decir, la cantidad
    // de nodos que pertenecen al mismo
    size_t getSize() const;
    // Método que devuelve los nodos pertenecientes al grafo
    std::list<Node> getNodes() const;
    // Metodo que agrega un nodo al grafo
    // Pre: recibe un nodo
    // Pos: devuelve 0 si el nodo fue agregado al grafo o -1
    // en caso de que haya algun error
    int addNode(Node& node);
    // Método que devuelve una referencia a un nodo de acuerdo a su id
    // Pre; el id corresponde a un nodo del grafo
    // Pos: si el nodo existe en el grafo devuelve una referencia al mismo,
    // sino devuelve una referencia al final de la lista de nodos
    Node& getNode(const std::string id);
    // Método que indica si un nodo pertenece o no al grafo
    // Pre: recibe un string correspondiente al id de un nodo
    // Pos: devuelve verdadero si el nodo pertenece al grafo, o falso
    // en caso contrario
    bool containsNode(const std::string id);
    // Método que devuelve una referencia a el primer nodo del grafo
    Node& getFirst();
};

#endif //GRAFO_H
