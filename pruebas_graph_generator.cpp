#include "graph_generator.h"

int main(int argc, char *argv[]){
    
    std::cout << "~~~~~~~~~~~~~~~Pruebas Generador de grafos~~~~~~~~~~~~~~~\n";

    std::cout << "~~~~~~~~~~~~~~~Crear un Generador de grafos~~~~~~~~~~~~~~\n";
    GraphGenerator new_gg("pruebas/prueba1.txt");
    std::string resp = ((&new_gg) != NULL) ? "Ok\n" : "Falló\n";
    std::cout << "El generador de grafos fue creado: " << resp;

    std::cout << "~~~~~~~~~~~~~~~Generar un nuevo grafo~~~~~~~~~~~~~~~~~~~~\n";
    Graph new_graph = new_gg.generateGraph();
    resp = ((&new_graph) != NULL) ? "Ok\n" : "Falló\n";
    std::cout << "El nuevo grafo fue generado: " << resp;

    std::cout << "~~~~~~~~~~~~~Los nodos guardados coinciden~~~~~~~~~~~~~~~\n";
    std::set<Node> nodos = new_graph.getNodes();
   for (std::set<Node>::iterator it=nodos.begin(); 
        it != nodos.end(); ++it) {
        std::cout << "Nombre Nodo: " << it->getId() << "\n";
    }

    return 0;
}