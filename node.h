#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <string>
#include <set>

// Clase encargada de almacernar información acerca de cada instrucción 
// para poder armar un grafo con ella
// Cuenta con los siguiente atributos:
// Id, si la instrucción a almacenar es una etiqueta, lleva el nombre de la
// misma, sino lleva un id autogenerado.
// Neighbors, es un set que contiene la referencia a los nodos vecinos, 
// es decir, a las instrucciones a las cuales puede ir desde dicha instrucción
class Node {
private:
    std::string id;
    std::set<Node> neighbors;

public:
    explicit Node(const std::string id);
    ~Node();
    // Método para obtener el id del nodo
    // Pos: devuelve el id que se le ha indicado al nodo al
    // momento de ser construido.
    std::string getId() const;
    // Metodo para obtener a los vecinos del nodo
    // Pos: devuelve el set con las referencias al los nodos
    // vecinos del nodo
    std::set<Node> getNeighbors();
    // Método que agrega un nuevo vecino al set de vecinos del nodo
    // Pre: el nuevo nodo es un vecino válido
    // Pos: devulve 1 si el nuevo vecino fue agregado, -1 en caso de error
    int addNeighbour(Node& neighbour);
    bool operator<(const Node& other) const;
    bool operator==(const Node& other) const;
};

#endif //NODO_H
