#ifndef LINE_MAP_H
#define LINE_MAP_H

#include <iostream>
#include <map>
#include <string>
#include <set>
#include <utility>

// Clase encargada de almacenar de manera organizada la información 
// leída en las líneas de los archivos, correspondiente a las instrucciones
// Cuenta con los siguientes atributos:
// Line_map, el cual es un map donde se almacenan las instrucciones, su tipo
// y sus parámetros
// Status, indica si el LineMap es válido o ha sido corrompido por algún
// error durante su uso
class LineMap {
private:
    std::map<std::string, std::string> line_map;
    int status;
    // Método que indica si una instrucción es una instrucción "ret"
    // Pos: devuelve true o false, de acuerdo a si la instrucció en un "ret"
    bool isARet() const;
    // Método que indica si un string corresponde a una etiqueta
    // Pre: recibe un string
    // Pos: devuelve true o false, de acuerdo a si es una etiqueta o no
    bool isATag(std::string tag) const;
    // Método que indica si una instrucción es una instrucción de salto
    // Pos: devuelve true o false, de acuerdo a si la instrucción es de salto
    bool isAJump() const;

public:
    // Constructor
    LineMap();
    // Destructor
    ~LineMap();
    // Método que devuelve el nombre de la etiqueta a la cual corresponde la
    // instrucción
    // Pos: devuelve el string correspondiente al nombre de la etiqueta, si
    // no existe una etiqueta, devuelve un string vacío
    std::string getTagId();
    // Método que devuelve un set con los id correspondientes a los vecinos
    // a los cuales puede saltarse desde la instrucción actual
    // Pos: devuelve el set con los ids de los vecinos, si no hay vecinos
    // devuelve un set vacío
    std::set<std::string> getNeighbors();
    // Método que agrega un elemento al LineMap
    // Pre: recibe un elemento key y un elemento value
    // Pos: devuelve 0 si se ha agregado el elemento al map, si ocurrió algún 
    // error devuelve un -1
    int add(std::string key, std::string value);
    // Método que indica si el LineMap está vacío
    // Pos: devuelve true o false, de acuerdo a si el line_map está vacío o no
    bool isEmpty() const;
    // Método que indica si una instrucción puede dar como resultado un salto
    // a la instrucción inmediatamente consecutiva o no.
    // Pos: indica true o false, de acuerdo a si puede saltar a la instrucción
    // inmediatamente consecutiva o no.
    bool canGoToTheNexLine() const;
    // Método que invalida el LineMap luego de que suceda algún error en alguna
    // de sus operaciones
    // Pos: el LineMap ya no puede ser utilizado
    void invalidate();
    // Método que indica si el LineMap es válido o no
    // Pos: devuelve true o false, de acuerdo a si el line_map es válido o no
    bool isValid() const;
};

#endif //LINE_MAP_H
