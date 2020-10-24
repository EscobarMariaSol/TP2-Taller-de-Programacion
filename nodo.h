#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <string>
#include <list>

class Nodo {

private:
    std::string name;
    std::list<Nodo> neighbors;

public:
    Nodo(const std::string name);
    ~Nodo();
    std::string getName() const;
    std::list<Nodo> getNeighbors() const;
    int addNeighbour(Nodo& neighbour);
};

#endif //NODO_H
