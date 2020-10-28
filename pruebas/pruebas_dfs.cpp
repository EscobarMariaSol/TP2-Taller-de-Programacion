#include "dfs.h"
#include "graph_generator.h"

void correr_dfs(std::string path) {
    std::cout << "~~~~~~~~~~~~~~~Crear un Objeto Dfs~~~~~~~~~~~~~~~~~~~~~~~\n";
    Dfs dfs = Dfs();
    std::string resp = ((&dfs) != NULL) ? "Ok\n" : "Falló\n";
    std::cout << "El objeto Dfs fue creado: " << resp;
    std::cout << "~~~~~~~~~~~~~~~Crear un Generador de grafos~~~~~~~~~~~~~~\n";
    GraphGenerator new_gg(path);
    resp = ((&new_gg) != NULL) ? "Ok\n" : "Falló\n";
    std::cout << "El nuevo GraphGenerator fue creado: " << resp;
    std::cout << "~~~~~~~~~~~~~~~Generar un nuevo grafo~~~~~~~~~~~~~~~~~~~~\n";
    Graph new_graph;
    resp = (new_gg.generateGraph(new_graph) == 0) ? "Ok\n" : "Falló\n";
    std::cout << "El nuevo grafo fue generado: " << resp;
    std::cout << "~~~~~~~~~~~~~~~~Los nodos guardados Son~~~~~~~~~~~~~~~~~~\n";
    std::list<Node> nodos = new_graph.getNodes();
    for (std::list<Node>::iterator it1=nodos.begin(); 
        it1 != nodos.end(); ++it1) {
        std::cout << "Nombre Nodo: " << it1->getId() << "\n";
        std::set<Node> vecinos = it1->getNeighbors();
        std::cout << "Vecinos: " << vecinos.size() << "\n";
        if (!vecinos.empty()) {
            for (std::set<Node>::iterator it2=vecinos.begin(); 
                it2 != vecinos.end(); ++it2) {
                std::cout << "      Nombre de vecino: " << it2->getId() << "\n";
            }
        }
    }
    std::cout << "~~~~~~~~~~~~~~~~~~~~Recorrer un grafo~~~~~~~~~~~~~~~~~~~~\n";
    resp = (dfs.walkGraph(new_graph) == 0) ? "Ok\n" : "Falló\n";
    std::cout << "El Grafo fue recorrido: " << resp;
    resp = (dfs.hasCycle() == 0) ? "Ok\n" : "Falló\n";
    std::cout << "El Grafo No tiene ciclos: " << resp;
    resp = (dfs.hasUnusedInstructions() == 0) ? "Ok\n" : "Falló\n";
    std::cout << "El Grafo No tiene instrucciones sin usar: " << resp;
}

int main(int argc, char *argv[]){
    std::cout << "~~~~~~~~~~~~~~~~~Pruebas Clase Dfs~~~~~~~~~~~~~~~~~~~~~~~\n";

    std::cout << "\n~~~~~~~~~~~~Pruebas Dfs con Grafo correcto~~~~~~~~~~~~~\n";
    correr_dfs("pruebas/prueba1.txt");

    std::cout << "\n~~~~~~~~~~~~~Pruebas Dfs con Grafo vacío~~~~~~~~~~~~~~~\n";
    correr_dfs("pruebas/prueba3.txt");

    std::cout << "\n~~~~~~~~~~~~~Pruebas Dfs Grafo Correcto~~~~~~~~~~~~~~~~\n";
    correr_dfs("pruebas/prueba4.txt");
        
    return 0;
}
