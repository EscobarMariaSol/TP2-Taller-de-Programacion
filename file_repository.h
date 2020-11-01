#ifndef FILE_REPOSITORY_H
#define FILE_REPOSITORY_H

#include <string>
#include <queue>
#include <mutex>
#include <iostream>
#include <functional>

// Clase encargada de almacenar las rutas a los archivos a verificar
// Cuenta con los siguientes atributos:
// files, que es una cola en la que se almacenan las rutas
// mutex, el cual será lockeado al momento de utilizar los métodos
// que son compartidos para los diferentes threads
class FileRepository {
private:
    std::queue<std::string> files;
    std::mutex mutex;

public:
    // Constructor
    FileRepository();
    // Destructor
    ~FileRepository();
    // Agrega una ruta a un file dentro de la cola del Filerepository
    // Pre: recibe una ruta a un archivo existente
    // Pos: la ruta ha sido almacenada
    void addFile(const std::string& file_path);
    // Método para obtener la próxima ruta en la cola de FileRepository
    // Pos: si la cola no está vacía devuelve la ruta a un archivo,
    // sino devuelve una ruta vacía
    std::string getFile();
    // Método para consultar si el FileRepository está vacío
    // Pos: devuelve verdadero si la cola está vacía, sino devuelve false.
    bool isEmpty() const;
    // Constructor por referencia
    FileRepository(const FileRepository&);
    // asignación por referencia
    FileRepository& operator=(const FileRepository&); 
};

#endif // FILE_REPOSITORY_H
