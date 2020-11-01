#ifndef CHECKER_PROGRAM_H
#define CHECKER_PROGRAM_H

#include "file_repository.h"
#include "checker.h"
#include "output_repository.h"
#include <vector>
#include <thread>
#include <string>

// Clase encargada de la ejecución del verificdor de archivos
// La clase cuenta con los siguientes atributos:
// file_repo, que corresponde al objeto compartido, donde se almacenarán
// las rutas a los archivos a verificar.
// output_repo, corresponde al repositorio compartido, donde se almacenan
// las salidas registradas por cada verificador.
class CheckerProgram {
private:
    FileRepository file_repo;
    OutputRepository output_repo;
    // Método utilizado para almacenar los archivos recibidos 
    // dentro del repositorio de archivos
    // Pre: recibe un vector con las rutas de los archivos
    // Pos: las rutas han sido almacenadas en el repositorio
    void saveFiles(std::vector<std::string>& files);

public:
    // Constructor
    CheckerProgram();
    // Destructor
    ~CheckerProgram();
    // Método encargado de ejecutar el verificador de archivos
    // Pre: recibe un char* correspondiente a la entrada que indica
    // la cantidad de threads que se deben lanzar durante la ejecución
    // y un vector con los archivos a verificar
    // Pos: Devuelve 0 en caso de haberse ejecutado el verificador 
    // exitosamente o -1 en caso de haberse producido algun error
    int start(const char *threads_num, std::vector<std::string>& files);
};

#endif // CHECKER_PROGRAM_H
