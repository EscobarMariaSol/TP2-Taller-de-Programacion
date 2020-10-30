#include "checker_program.h"

static std::string getOutput(Checker& checker, std::string& path) {
    std::string output;
    size_t index = path.find_last_of('/');
    if (index != std::string::npos) 
        output += (path.substr(index) + checker.getResult() + "\n");
    else 
        output += (path + checker.getResult() + "\n");
    return output;
}

/**************** Métodos Privados de CheckerProgram *************************/


void CheckerProgram::saveFiles(const char *files[]) {
    int i = 0;
    while (files[i] != NULL) {
        this->file_repo.addFile(std::string(files[i]));
        i++;
    }
}
int CheckerProgram::verifyFiles() {
    Checker checker;
    std::string output;
    std::string path = this->file_repo.getFile();
    if (checker.verifyFile(path) < 0) return -1;
    if ((output = getOutput(checker, path)).empty()) return -1;
    if (this->output_repo.addOutput(output) < 0) return -1;
    return 0;
}
/**************** Métodos Públicos de CheckerProgram *************************/

CheckerProgram::CheckerProgram(): file_repo(), output_repo() {
}

CheckerProgram::~CheckerProgram() {
}

int CheckerProgram::start(const char *files[]) {
    saveFiles(files);
    if (verifyFiles() < 0) return -1;
    this->output_repo.showOutput();
    return 0;
}