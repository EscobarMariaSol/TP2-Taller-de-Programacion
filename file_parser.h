#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>

#include "line_map.h"
#include <utility>

// Clase encargada de abrir un archivo, leer sus lineas y parsear el 
// texto de los archivos a información utilizable para que la clase 
// GraphGenerator pueda crear un grafo a partir de ello
// Cuenta con un único atributo correspondiente al file que se desea parsear
class FileParser {
private:
    std::fstream file;
    
public:
    // Constructor
    explicit FileParser(const std::string file_name);
    // Destructor
    ~FileParser();
    // Método que lee una línea del archivo y la procesa, almacenando toda
    // la información relevante en el LineMap que será devuelto
    // Pre: el parser se ha creado con la ruta de un file válido
    // Pos: devuelve un LineMap con la información relevante, en caso de 
    // que ocurra algún error devuelve un LineMap inválido
    LineMap parseLine();
    // Método que indica si todavía existen lineas del archivo a ser procesadas
    // Pos: devuelve verdadero o false de acuerdo a si quedan lineas por
    // procesar o no
    bool hasLine() const;
};

#endif //FILE_PARSER_H
