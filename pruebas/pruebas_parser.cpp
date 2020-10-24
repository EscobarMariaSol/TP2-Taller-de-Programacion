#include "file_parser.h"

int main(int argc, char *argv[]){
    std::cout << "~~~~~~~~~~~~~~~~~Inicio Pruebas Parser~~~~~~~~~~~~~~~~~~~~\n";
    FileParser myParser("pruebas/prueba1.txt");
    std::cout << "~~~~~~~~~~~~~~~~~El parser se creó~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::string resp = ((&myParser) != NULL) ? "Ok\n" : "Falló\n";
    std::cout << "El parser fue creado: " << resp;
    std::map<std::string, std::string> mapped;
    mapped = myParser.parseLine();
    int k = 1;
    std::cout << "~~~~~~~~~~~~~~~~~Parseo por líneas~~~~~~~~~~~~~~~~~~~~~~~~\n";
    while (mapped.size() > 0) {
        std::cout << "LINEA número" << k << "\n";
        for (std::map<std::string, 
            std::string>::iterator it=mapped.begin(); 
            it!=mapped.end(); ++it) {
            std::cout << it->first << " => " << it->second << '\n';
        }
        mapped = myParser.parseLine();
        k++;
    }
    return 0;
}