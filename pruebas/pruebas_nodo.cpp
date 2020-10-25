#include "node.h"

int main(int argc, char *argv[]){
    std::cout << "~~~~~~~~~~~~~~~~~~~~~Pruebas Nodo~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~Crear un Nodo~~~~~~~~~~~~~~~~~~~~~~~\n";
    Node nodo = Node("1");
    std::string resp = (nodo.getId().compare("1") == 0) ? "Ok\n" : "Falló\n";
    std::cout << "Nombre Coincide: " << resp;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~Agregar vecinos~~~~~~~~~~~~~~~~~~~~~\n";
    Node nodo1 = Node("1");
    Node nodo2 = Node("2");
    Node nodo3 = Node("3");
    nodo1.addNeighbour(nodo2);
    nodo1.addNeighbour(nodo3);
    std::set<Node> vecinos = nodo1.getNeighbors();
    for (std::set<Node>::iterator it=vecinos.begin(); 
        it != vecinos.end(); ++it) {
        std::cout << "Nombre vecino: " << it->getId() << "\n";
    }
    return 0;
}
