#include "checker_program.h"

// Programa principal que se encarga de llamar a la clase encargada
// de ejecutar el verificador de archivos
// Pos: Devuelve 0 en caso de éxito, si ocurre un error imprime un
// mensaje notificando del mismo.
int main(int argc, char *argv[]){
    if (argc >= 3) {
        std::vector<std::string> argVector(argv + 2, argv + argc);
        CheckerProgram program;
        if (program.start(argv[1], argVector) < 0)
            std::cout<< "Ocurrió un error al ejecutar el verificador.";
    }
    return 0;
}
