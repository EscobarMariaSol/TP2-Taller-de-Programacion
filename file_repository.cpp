#include "file_repository.h"

/**************** Métodos Públicos de FileRepository *************************/

FileRepository::FileRepository(): files(){
}

FileRepository::~FileRepository() {
}

void FileRepository::addFile(const std::string& file_path) {
    std::lock_guard<std::mutex> lock(this->mutex);
    this->files.push(file_path);
}

std::string FileRepository::getFile() {
    std::lock_guard<std::mutex> lock(this->mutex);
    std::string aux;
    if (!this->files.empty()) {
        aux = this->files.front();
        this->files.pop();
    }
    return aux;
}

bool FileRepository::isEmpty() const {
    return (this->files.empty());
}

FileRepository::FileRepository(const FileRepository& other) {
    this->files = std::ref(other.files);
}
    
FileRepository& FileRepository::operator=(const FileRepository& other) {
    this->files = std::ref(other.files);
    return *this;
}
