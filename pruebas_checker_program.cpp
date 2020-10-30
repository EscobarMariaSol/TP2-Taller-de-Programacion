#include "checker_program.h"

int main(int argc, char *argv[]){
    std::cout << "~~~~~~~~~~~ Pruebas Clase CheckerProgram ~~~~~~~~~~~~~~~~\n";
    std::cout << "\n~~~~~~~~~~ CheckerProgram all_addr_modes ~~~~~~~~~~~~~~\n";
    std::vector<std::string> input1;
    CheckerProgram prog1;
    input1.push_back("pruebas/all_addr_modes.bpf");
    std::string resp = (prog1.start(input1) == 0) ? "Ok\n" : "Falló\n";
    std::cout << "El programa se ejecutó correctamente: "<< resp;
    
    std::cout << "\n~~~~~~~~~~ CheckerProgram not_exec_inst ~~~~~~~~~~~~~~~\n";
    std::vector<std::string> input2;
    CheckerProgram prog2;
    input2.push_back("pruebas/not_exec_inst.bpf");
    resp = (prog2.start(input2) == 0) ? "Ok\n" : "Falló\n";
    std::cout << "El programa se ejecutó correctamente: "<< resp;
    
    std::cout << "\n~~~~~~~~~~ CheckerProgram con_ciclo ~~~~~~~~~~~~~~~~~~~\n";
    std::vector<std::string> input3;
    CheckerProgram prog3;
    input3.push_back("pruebas/con_ciclo.txt");
    resp = (prog3.start(input3) == 0) ? "Ok\n" : "Falló\n";
    std::cout << "El programa se ejecutó correctamente: "<< resp;

    return 0;
}