#include "graph_generator.h"

void crear_generador(std::string path) {
    std::cout << "~~~~~~~~~~~~~~~Crear un Generador de grafos~~~~~~~~~~~~~~\n";
    GraphGenerator new_gg(path);
    
    std::string resp = ((&new_gg) != NULL) ? "Ok\n" : "Falló\n";
    std::cout << "El generador de grafos fue creado: " << resp;

    std::cout << "~~~~~~~~~~~~~~~Generar un nuevo grafo~~~~~~~~~~~~~~~~~~~~\n";
    Graph new_graph = new_gg.generateGraph();
    resp = ((&new_graph) != NULL) ? "Ok\n" : "Falló\n";
    std::cout << "El nuevo grafo fue generado: " << resp;

    std::cout << "~~~~~~~~~~~~~Los nodos guardados coinciden~~~~~~~~~~~~~~~\n";
    std::list<Node> nodos = new_graph.getNodes();
    for (std::list<Node>::iterator it=nodos.begin(); 
        it != nodos.end(); ++it) {
        std::cout << "Nombre Nodo: " << it->getId() << "\n";
    }

    std::cout << "~~~~~~~~~~~Las aristas del grafo coinciden~~~~~~~~~~~~~~~\n";
    for (std::list<Node>::iterator it1=nodos.begin(); 
        it1 != nodos.end(); ++it1) {
        std::cout << "Nombre Nodo: " << it1->getId() << "\n";
        std::list<Node> vecinos = it1->getNeighbors();
        std::cout << "Vecinos: " << vecinos.size() << "\n";
        if (!vecinos.empty()) {
            for (std::list<Node>::iterator it2=vecinos.begin(); 
                it2 != vecinos.end(); ++it2) {
                std::cout << "      Nombre de vecino: " << it2->getId() << "\n";
            }
        }
    }
}

int main(int argc, char *argv[]){

    std::cout << "~~~~~~~~~~~~~~~Pruebas Generador de grafos~~~~~~~~~~~~~~~\n";
    
    std::cout << "~~~~~~~~~~~~~~~Prueba File correcto~~~~~~~~~~~~~~~~~~~~~~\n";
    crear_generador("pruebas/prueba1.txt");

    std::cout << "~~~~~~~~~~~~~~~Prueba File con lineas vacias~~~~~~~~~~~~~\n";
    crear_generador("pruebas/prueba2.txt");

    std::cout << "~~~~~~~~~~~~~~~Prueba File vacio~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    crear_generador("pruebas/prueba3.txt");
    
    return 0;
}