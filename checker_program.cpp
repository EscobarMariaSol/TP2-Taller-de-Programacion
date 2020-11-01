#include "checker_program.h"

/**************** Funciones auxiliares de CheckerProgram *********************/

// Función utilizada para validar si el valor correspondiente a un número 
// recibido desde el main, corresponde a un valor númerico
// Pre: recibe una referencia a un string
// Pos: devuelve verdadero si el string corresponde a un valor numérico
// o falso en caso contrario
static bool isAValidNumber(const std::string& number) {
    for (size_t i = 0; i < number.size(); i++)
        if (!isdigit(number[i])) return false;
    return true;
}

// Función que se encarga de correr los checkers y luego unirlos nuevamente
// al thread principal
// Pre: recibe un vector con punteros a los checkers y la cantidad de checkers
// Pos: los checkers han sido ejecutados
static void runCheckers(std::vector<Checker*>& checkers, int threads_num) {
    for (int i = 0; i < threads_num; i++) checkers[i]->start();
    for (int i = 0; i < threads_num; i++) checkers[i]->join();
}
/**************** Métodos Privados de CheckerProgram *************************/

void CheckerProgram::saveFiles(std::vector<std::string>& files) {
    for (std::vector<std::string>::iterator it = files.begin();
        it != files.end(); ++it) {
        this->file_repo.addFile(*it);
    }
}

/**************** Métodos Públicos de CheckerProgram *************************/

CheckerProgram::CheckerProgram(): file_repo(), output_repo() {
}

CheckerProgram::~CheckerProgram() {
}

int CheckerProgram::start(const char *threads, 
    std::vector<std::string>& files) {
    if (isAValidNumber(std::string(threads))) {
        saveFiles(files);
        int threads_num = atoi(threads);
        std::vector<Checker*> checkers;
        checkers.reserve(threads_num);
        for (int i = 0; i < threads_num; i++) 
            checkers.push_back(new Checker(this->file_repo, this->output_repo));
        runCheckers(checkers, threads_num);
        this->output_repo.showOutput();
        for (int i = 0; i < threads_num; i++) delete checkers[i];
    }
    return 0;
}
