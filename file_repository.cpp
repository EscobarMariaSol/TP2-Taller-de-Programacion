#include "file_repository.h"

/**************** Métodos Públicos de FileRepository *************************/

FileRepository::FileRepository(): files(){
}

FileRepository::~FileRepository() {
}

void FileRepository::addFile(const std::string file_path) {
    this->files.push(file_path);
}

std::string FileRepository::getFile() {
    std::string aux;
    if (!this->files.empty()) {
        aux = this->files.front();
        this->files.pop();
    }
    return aux;
}