#include "output_repository.h"

/**************** Métodos Públicos de Outputrepository ***********************/

OutputRepository ::OutputRepository(): outputs() {
}

OutputRepository ::~OutputRepository() {
}

int OutputRepository::addOutput(const std::string output) {
    if (this->outputs.insert(output).second == false)
        return -1;
    return 0;
}
    
void OutputRepository::showOutput() const {
    for(std::set<std::string>::iterator it = this->outputs.begin();
        it != this->outputs.end(); ++it) {
            std::cout<<(*it)<<"\n";
    }
}
