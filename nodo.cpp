#include "nodo.h"

/*********************** Funciones Auxiliares de Nodo ************************/


/*********************** Métodos Públicos de Nodo ****************************/

Nodo::Nodo(const std::string name): neighbors() {
    this->name = name;
}

Nodo::~Nodo(){
}

std::string Nodo::getName() const {
    return this->name;
}

std::list<Nodo> Nodo::getNeighbors() const {
    return this->neighbors;
}

int Nodo::addNeighbour(Nodo& neighbour) {
    this->neighbors.push_back(neighbour);
    return 0;
}