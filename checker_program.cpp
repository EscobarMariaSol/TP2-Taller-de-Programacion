#include "checker_program.h"

static std::string getOutput(Checker& checker, std::string& path) {
    std::string output;
    size_t index = path.find_last_of('/') + 1;
    if (index != std::string::npos) 
        output += (path.substr(index) + " " + checker.getResult() + "\n");
    else 
        output += (path + checker.getResult() + "\n");
    return output;
}

/**************** Métodos Privados de CheckerProgram *************************/


void CheckerProgram::saveFiles(std::vector<std::string>& files) {
    for (std::vector<std::string>::iterator it = files.begin();
        it != files.end(); ++it) {
        std::string path(*it);
        this->file_repo.addFile(path);
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

int CheckerProgram::start(std::vector<std::string>& files) {
    saveFiles(files);
    // Los threads deberían implementarse por acá
    // y cada hilo deberá llamar a verifyFiles
    if (verifyFiles() < 0) return -1;
    this->output_repo.showOutput();
    return 0;
}