#include "output_repository.h"

/**************** Métodos Públicos de Outputrepository ***********************/

OutputRepository ::OutputRepository(): outputs() {
}

OutputRepository ::~OutputRepository() {
}

int OutputRepository::addOutput(const std::string output) {
    std::lock_guard<std::mutex> lock(this->mutex);
    std::pair<std::set<std::string>::iterator, bool> result;
    result = this->outputs.insert(output);
    if (result.second == false) return -1;
    return 0;
}
    
void OutputRepository::showOutput() {
    std::lock_guard<std::mutex> lock(this->mutex);
    for(std::set<std::string>::iterator it = this->outputs.begin();
        it != this->outputs.end(); ++it) {
            std::cout<<(*it)<<"\n";
    }
}

OutputRepository::OutputRepository(const OutputRepository& other) {
    this->outputs = std::ref(other.outputs);
}

OutputRepository& OutputRepository::operator=(const OutputRepository& other) {
    this->outputs = std::ref(other.outputs);
    return *this;
}