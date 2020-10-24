#include "nodo.h"

int main(int argc, char *argv[]){
    std::cout << "~~~~~~~~~~~~~~~~~~~~~Pruebas Nodo~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~Crear un Nodo~~~~~~~~~~~~~~~~~~~~~~~\n";
    Nodo nodo = Nodo("1");
    std::string resp = (nodo.getName().compare("1") == 0) ? "Ok\n" : "Falló\n";
    std::cout << "Nombre Coincide: " << resp;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~Agregar vecinos~~~~~~~~~~~~~~~~~~~~~\n";
    Nodo nodo1 = Nodo("1");
    Nodo nodo2 = Nodo("2");
    Nodo nodo3 = Nodo("3");
    nodo1.addNeighbour(nodo2);
    nodo1.addNeighbour(nodo3);
    std::list<Nodo> vecinos = nodo1.getNeighbors();
    for (std::list<Nodo>::iterator it=vecinos.begin(); 
        it != vecinos.end(); ++it) {
        std::cout << "Nombre vecino: " << it->getName() << "\n";
    }
    return 0;
}
