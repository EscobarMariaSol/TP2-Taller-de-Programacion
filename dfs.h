#ifndef DFS_H
#define DFS_H

#include "graph.h"
#include <set>
#include <stack>

// Clase encargada de realizar un recorrido DFS sobre un grafo
// permitiendo así detectar ciclos y la existencia de instrucciones
// sin usar
// Cuenta con los siguientes atributos:
// Cycle, atributo booleano para indicar si se encuentra un ciclo
// UnusedInstructions, atributo booleano para indicar si se han 
// encontrado instrucciones a las cuales no se puede acceder
class Dfs {
private:
    bool cycle;
    bool unusedInstructions;
    // Método que visita todos los nodos accesibles de un grafo
    // partiendo desde un nodo que se le pasa por parametro
    // Pre: Recibe un grafo, un nodo del grafo y un set donden se
    // almacenaran los nodos visitados.
    // Pos: devuelve 0 en caso de haber visitado todos los nodos de 
    // manera exitosa o -1 en caso de hallar un ciclo.
    int visit(Graph& graph, Node& actual, std::set<Node>& visited);

public:
    // Constructor
    Dfs();
    // Destructor
    ~Dfs();
    // Método que recorre un grafo en busca de ciclos o nodos
    // que no sean accesibles
    // Pre: recibe un grafo
    // Pos: devuelve 0 en caso de haber recorrido todo el grafo
    // o -1 en caso de cualquier error
    int walkGraph(Graph& graph);
    // Método que señala si un grafo contiene un ciclo
    // Pre: un grafo ha sido recorrido previamente
    // Pos: devuelve verdadero o falso según si el grafo
    // recorrido contenia un ciclo o no
    bool hasCycle() const;
    // Método que señala si un grafo contiene instrucciones inaccesibles
    // Pre: un grafo ha sido recorrido previamente
    // Pos: devuelve verdadero o falso según si el grafo
    // recorrido contenia uno o más nodos sin visitar
    bool hasUnusedInstructions() const;
};

#endif // DFS_H
