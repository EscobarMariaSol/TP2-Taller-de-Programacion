#include "graph.h"

int main(int argc, char *argv[]){
    
    std::cout << "~~~~~~~~~~~~~~~~~~~~~Pruebas Grafo~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~Crear un Grafo~~~~~~~~~~~~~~~~~~~~~~~\n";
    Graph grafo = Graph();
    std::string resp = (grafo.getSize() == 0) ? "Ok\n" : "Falló\n";
    std::cout << "Grafo recién creado tiene tamaño 0: " << resp;
    resp = (grafo.getNodes().empty()) ? "Ok\n" : "Falló\n";
    std::cout << "Grafo recién creado no tiene nodos: " << resp;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~Agregar Nodos~~~~~~~~~~~~~~~~~~~~~~~\n";
    Node nodo1 = Node("1");
    Node nodo2 = Node("2");
    Node nodo3 = Node("3");
    grafo.addNode(nodo1);
    resp = (grafo.getNodes().size() == 1) ? "Ok\n" : "Falló\n";
    std::cout << "Luego de agregar un nodo el tamaño es 1: " << resp;
    grafo.addNode(nodo2);
    resp = (grafo.getNodes().size() == 2) ? "Ok\n" : "Falló\n";
    std::cout << "Luego de agregar otro nodo el tamaño es 2: " << resp;
    grafo.addNode(nodo3);
    resp = (grafo.getNodes().size() == 3) ? "Ok\n" : "Falló\n";
    std::cout << "Luego de agregar otro nodo el tamaño es 3: " << resp;
    
    return 0;
}