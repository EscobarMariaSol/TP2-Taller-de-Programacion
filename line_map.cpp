#include "line_map.h"

/**************** Métodos Públicos de GraphGenerator *************************/

LineMap::LineMap() {
}

LineMap::~LineMap() {
}

bool LineMap::isATag(std::string tag) const {
    if ((tag.find('#') == std::string::npos) || 
        (tag.find('[') == std::string::npos)) {
            return false;
    }
    return true;
}

bool LineMap::isAJump() const {
    std::string inst[] = {"jmp", "ja", "jeq", "jne", 
                            "jlt", "jle", "jgt", "jge", "jset"};
    std::string instuction = this->line_map.find("INST")->second;
    return (inst->find(instuction) != std::string::npos);
}

bool LineMap::isARet() const {
    std::string instuction = this->line_map.find("INST")->second;
    return (instuction.compare("ret") == 0);
}

std::string LineMap::getTagId() {
    if (this->line_map.find("TAG") != this->line_map.end()) {
        return this->line_map.find("TAG")->second;
    }
    return "";
}

std::set<std::string> LineMap::getNeighbors() {
    std::set<std::string> nghbrs;
    if (this->isAJump()) {
        if (isATag(this->line_map.find("PARAM1")->second)) {
           nghbrs.insert(this->line_map.find("PARAM1")->second); 
        } if (isATag(this->line_map.find("PARAM2")->second)) {
           nghbrs.insert(this->line_map.find("PARAM2")->second); 
        } if (isATag(this->line_map.find("PARAM3")->second)) {
           nghbrs.insert(this->line_map.find("PARAM3")->second); 
        } 
    }
    return nghbrs;
}

int LineMap::add(std::string key, std::string value) {
    this->line_map.insert(
        std::pair<std::string, std::string>(key, value));
    return 0;
}

bool LineMap::isEmpty() const {
    return this->line_map.empty();
}