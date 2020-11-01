#ifndef CHECKER_H
#define CHECKER_H

#include "graph.h"
#include "graph_generator.h"
#include "dfs.h"
#include "checker_thread.h"
#include <string>

// Clase correspondiente al verificador de archivos. La misma hereda
// de la clase CheckerThread, pues cada instacia de la misma corresponderá
// a un thread.
// Los atributos de la misma son los siguientes:
// Result, un string correspondiente al resultado obtenidos luego de 
// verificar un archivo
// File_repo, corresponde al repositorio al cual se le pediran las rutas
// de los archivos que deben ser verificados
// Output_repo, corresponde al repositorio en el cual se almacenaran
// los resultados obtenidos luego de verificar los archivos
class Checker: public CheckerThread {
private:
    std::string result;
    FileRepository& file_repo;
    OutputRepository& output_repo;
    // Método que asigna el resultado obtenido luego de haber realizado
    // la verificación de un archivo
    // Pre: recibe una referencia a un DFS que ha realizado en recorrido
    // correspondiente en un grafo
    // Pos: el resultado obtenido por el DFS ha sido asignado en el 
    // atributo result, respetando el formato correspondiente
    void setResult(Dfs& dfs);
    // Método que concatena el nombre del archivo verificado junto con 
    // el resultado obtenido para obtener la salida adecuada
    // Pre: recibe la ruta del archivo que ha sido verificado y cuyo
    // rusultado ha sido asignado
    // Pos: devuelve la salida en el formato correspondiente
    std::string createOutput(std::string& path);
    
public:
    // Constructor
    Checker(FileRepository& file_repo, OutputRepository& output_repo);
    // Destructor
    ~Checker();
    // Metodo encargado de pedir archivos al repositorio, verificarlos
    // y guardar el resultado obtenido en el repositorio de salidas
    // Pos: los archivos que el repositorio le ha entregado han sido
    // verificados y sus resutados han sido almacenados en el repositorio
    // de salidas
    void verifyFile();
};

#endif // CHECKER_H
