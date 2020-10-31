#include "checker_program.h"

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

int CheckerProgram::start(const int threads_num, std::vector<std::string>& files) {
    saveFiles(files);
    std::vector<Checker*> checkers;
    checkers.reserve(threads_num);
    for (int i = 0; i < threads_num; i++) 
        checkers.push_back(new Checker(this->file_repo, this->output_repo));
    for (int i = 0; i < threads_num; i++) checkers[i]->start();
    for (int i = 0; i < threads_num; i++) checkers[i]->join();
    this->output_repo.showOutput();
    for (int i = 0; i < threads_num; i++) delete checkers[i];
    return 0;
}