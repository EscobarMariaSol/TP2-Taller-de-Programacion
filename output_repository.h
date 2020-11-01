#ifndef OUTPUT_REPOSITORY_H
#define OUTPUT_REPOSITORY_H

#include <set>
#include <string>
#include <iostream>
#include <mutex>
#include <functional>
#include <utility>

// La clase es un repositorio encargado de almacenar las salidas 
// correspondientes al resultado de las verificaciones de los archivos
// Cuenta con los siguientes atributos:
// Outputs, es un set en el cual se almacenan la salidas 
// ordenadas alfabeticamente
// Mutex, es el mutex que se utilizará para evitar que un thread
// pueda interrumpir a otro mientras interactua con las secciones
// críticas del repositorio
class OutputRepository {
private:
    std::set<std::string> outputs;
    std::mutex mutex;

public:
    // Constructor
    OutputRepository();
    // Destructor
    ~OutputRepository();
    // Método encargado de agregar una nueva salida al set de outputs
    // Pre: recibe un string correspondiente a una salida
    // Pos: devuleve 1 si la salida ha sido almacenada, -1 en caso de error
    int addOutput(const std::string output);
    // Método que se encarga de mostrar por pantalla todas las salidas
    // que han sido almacenadas dentro del set del repositorio
    void showOutput();
    // Constructor por referencia
    OutputRepository(const OutputRepository& other);
    // Método que permite la asignación por referencia
    OutputRepository& operator=(const OutputRepository& other);
};

#endif // OUTPUT_REPOSITORY_H
