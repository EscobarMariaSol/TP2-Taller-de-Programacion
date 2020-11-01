#ifndef CHECKER_THREAD_H
#define CHECKER_THREAD_H

#include <utility>
#include <thread>
#include "file_repository.h"
#include "output_repository.h"

// Clase encargada de crear un thread para cada checker y ejecutar el
// correspondiente verificador
// Cuenta con un único atributo correspondiente al thread que se lanzará
// para cada instacia de un Checker
class CheckerThread {
private:
    std::thread thread;
   
public:
    // Constructor
    CheckerThread();
    // Destructor
    virtual ~CheckerThread();
    // Metodo que inicializa el atributo thread y llama al método
    // que debe ejecutar, verifyFile, pasandole una instancia de sí mismo.
    // Pos: el método verifyFile se ha ejecutado
    void start();
    // Método que realiza un join del thread al thread main
    // Pre: el atributo thread ha sido inicializado
    // Pos: el thread se ha unido al thread main.
    void join();
    // Método que se encarga de verificar un archivo
    // el métod es virtual, pues ha de ser implementado por las clases 
    // que hereden de CheckerThread
    virtual void verifyFile() = 0;
    // Impide que se realice una copia del CheckerThread
    CheckerThread(const CheckerThread& other) = delete;
    // Impide que se realice una asignación del CheckerThread
    CheckerThread& operator=(const CheckerThread& other) = delete;
    // Constructor por movimiento
    CheckerThread(CheckerThread&& other);
    // Método que permite que se realice una asignación por movimiento
    CheckerThread& operator=(CheckerThread&& other);
};

#endif // CHECKER_THREAD_H
