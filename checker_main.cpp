#include "checker_program.h"

int main(int argc, char *argv[]){
    if (argc >= 3) {
        std::vector<std::string> argVector(argv + 2, argv + argc);
        CheckerProgram program;
        if (program.start(argv[1], argVector) < 0)
            std::cout<< "Ocurrió un error al ejecutar el verificador.";
    }
    return 0;
}
