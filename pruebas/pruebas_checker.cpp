#include "checker.h"

void correr_checker(std::string path) {
    Checker checker;
    std::string resp = (checker.verifyFile(path) == 0) ? "Ok\n" : "Falló\n";
    std::cout << "El Archivo fue verificado: " << resp;
    std::string good = "GOOD";
    resp = (checker.getResult() == good) ? "Si\n" : "No\n";
    std::cout << "El Archivo es correcto: " << resp;
    std::string ciclo = "FAIL: cycle detected";
    resp = (checker.getResult() == ciclo) ? "Si\n" : "No\n";
    std::cout << "El Archivo Contiene un ciclo: " << resp;
    std::string unused = "FAIL: unused instructions detected";
    resp = (checker.getResult() == unused) ? "Si\n" : "No\n";
    std::cout << "El Archivo tiene instrucciones sin usar: " << resp;
}

int main(int argc, char *argv[]){
    std::cout << "~~~~~~~~~~~~~~~~ Pruebas Clase Checker ~~~~~~~~~~~~~~~~~~\n";
    std::cout << "\n~~~~~~~~~~ Pruebas Checker all_addr_modes ~~~~~~~~~~~~~\n";
    correr_checker("pruebas/all_addr_modes.bpf");
    std::cout << "\n~~~~~~~~~~ Pruebas Checker all_jmps ~~~~~~~~~~~~~~~~~~~\n";
    correr_checker("pruebas/all_jmps.bpf");
    std::cout << "\n~~~~~~~~~~ Pruebas checker arp ~~~~~~~~~~~~~~~~~~~~~~~~\n";
    correr_checker("pruebas/arp.bpf");
    std::cout << "\n~~~~~~~~~~ Pruebas checker icmp ~~~~~~~~~~~~~~~~~~~~~~~\n";
    correr_checker("pruebas/icmp.bpf");
    std::cout << "\n~~~~~~~~~~ Pruebas checker not_exec_inst ~~~~~~~~~~~~~~\n";
    correr_checker("pruebas/not_exec_inst.bpf");
    std::cout << "\n~~~~~~~~~~ Pruebas checker not_exec_inst2 ~~~~~~~~~~~~~\n";
    correr_checker("pruebas/not_exec_inst2.bpf");
    std::cout << "\n~~~~~~~~~~ Pruebas checker ret ~~~~~~~~~~~~~~~~~~~~~~~~\n";
    correr_checker("pruebas/ret.bpf");
    std::cout << "\n~~~~~~~~~~ Pruebas checker seccomp ~~~~~~~~~~~~~~~~~~~~\n";
    correr_checker("pruebas/seccomp.bpf");
    std::cout << "\n~~~~~~~~~~ Pruebas checker tcp ~~~~~~~~~~~~~~~~~~~~~~~~\n";
    correr_checker("pruebas/tcp.bpf");
    std::cout << "\n~~~~~~~~~~ Pruebas checker vlan ~~~~~~~~~~~~~~~~~~~~~~~\n";
    correr_checker("pruebas/vlan.bpf");
    std::cout << "\n~~~~~~~~~~ Pruebas checker wasted_resources ~~~~~~~~~~~\n";
    correr_checker("pruebas/wasted_resources.bpf");
    std::cout << "\n~~~~~~~~~~ Pruebas checker con_ciclo ~~~~~~~~~~~~~~~~~~\n";
    correr_checker("pruebas/con_ciclo.txt");

    return 0;
}