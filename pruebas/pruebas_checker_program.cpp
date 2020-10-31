#include "checker_program.h"

int main(int argc, char *argv[]){
    std::cout << "~~~~~~~~~~~ Pruebas Clase CheckerProgram ~~~~~~~~~~~~~~~~\n";
    std::cout << "\n~~~~~~~~~~~~~~~~ Pruebas sin threads ~~~~~~~~~~~~~~~~~~\n";
    std::cout << "\n~~~~~~~~~~ CheckerProgram all_addr_modes ~~~~~~~~~~~~~~\n";
    std::vector<std::string> input1;
    CheckerProgram prog1;
    input1.push_back("pruebas/all_addr_modes.bpf");
    std::string resp = (prog1.start("1", input1) == 0) ? "Ok\n" : "Falló\n";
    std::cout << "El programa se ejecutó correctamente: "<< resp;
    
    std::cout << "\n~~~~~~~~~~ CheckerProgram not_exec_inst ~~~~~~~~~~~~~~~\n";
    std::vector<std::string> input2;
    CheckerProgram prog2;
    input2.push_back("pruebas/not_exec_inst.bpf");
    resp = (prog2.start("1", input2) == 0) ? "Ok\n" : "Falló\n";
    std::cout << "El programa se ejecutó correctamente: "<< resp;
    
    std::cout << "\n~~~~~~~~~~ CheckerProgram con_ciclo ~~~~~~~~~~~~~~~~~~~\n";
    std::vector<std::string> input3;
    CheckerProgram prog3;
    input3.push_back("pruebas/con_ciclo.txt");
    resp = (prog3.start("1", input3) == 0) ? "Ok\n" : "Falló\n";
    std::cout << "El programa se ejecutó correctamente: "<< resp;

    std::cout << "\n~~~~~~~~~~~~~~~~ Pruebas con threads ~~~~~~~~~~~~~~~~~~\n";

    std::cout << "\n~~~~~~~~~~ CheckerProgram parallel_bad ~~~~~~~~~~~~~~~~\n";
    std::vector<std::string> input4;
    CheckerProgram prog4;
    input4.push_back("pruebas/parallel_bad/arp.bpf");
    input4.push_back("pruebas/parallel_bad/bad_tcp.bpf");
    input4.push_back("pruebas/parallel_bad/not_exec_inst.bpf");
    input4.push_back("pruebas/parallel_bad/seccomp.bpf");
    input4.push_back("pruebas/parallel_bad/vlan.bpf");
    resp = (prog4.start("5", input4) == 0) ? "Ok\n" : "Falló\n";
    std::cout << "El programa se ejecutó correctamente: "<< resp;

    std::cout << "\n~~~~~~~~~~ CheckerProgram parallel_bad ~~~~~~~~~~~~~~~~\n";
    std::vector<std::string> input5;
    CheckerProgram prog5;
    input5.push_back("pruebas/parallel_good/arp.bpf");
    input5.push_back("pruebas/parallel_good/icmp.bpf");
    input5.push_back("pruebas/parallel_good/seccomp.bpf");
    input5.push_back("pruebas/parallel_good/tcp.bpf");
    input5.push_back("pruebas/parallel_good/vlan.bpf");
    resp = (prog5.start("5", input5) == 0) ? "Ok\n" : "Falló\n";
    std::cout << "El programa se ejecutó correctamente: "<< resp;

    return 0;
}