#include "line_map.h"

/**************** Métodos Privados de LineMap *************************/

bool LineMap::isATag(std::string tag) const {
    if ((tag.find('#') != std::string::npos) || 
        (tag.find('[') != std::string::npos)) {
            return false;
    }
    return true;
}

bool LineMap::isAJump() const {
    if (!this->line_map.empty())
        return (this->line_map.find("INST")->second.front() == 'j');
    return false;
}

bool LineMap::isARet() const {
    if (!this->line_map.empty()) {
        std::string instuction = this->line_map.find("INST")->second;
        return (instuction.compare("ret") == 0);
    }
    return false;
}

/**************** Métodos Públicos de LineMap *************************/
LineMap::LineMap(): line_map(), status(0) {
}

LineMap::~LineMap() {
}

std::string LineMap::getTagId() {
    if (!this->line_map.empty()) {
        if (this->line_map.find("TAG") != this->line_map.end())
            return this->line_map.find("TAG")->second;
    }
    return "";
}

std::set<std::string> LineMap::getNeighbors() {
    std::set<std::string> nghbrs;
    if (this->isAJump()) {
        if (isATag(this->line_map.find("PARAM1")->second))
            nghbrs.insert(this->line_map.find("PARAM1")->second); 
        if (this->line_map.find("PARAM2") != this->line_map.end()) {
            if (isATag(this->line_map.find("PARAM2")->second))
                nghbrs.insert(this->line_map.find("PARAM2")->second); 
        } 
        if (this->line_map.find("PARAM3") != this->line_map.end()) {
            if (isATag(this->line_map.find("PARAM3")->second))
                nghbrs.insert(this->line_map.find("PARAM3")->second); 
        } 
    }
    return nghbrs;
}

int LineMap::add(std::string key, std::string value) {
    if (this->line_map.insert(
        std::pair<std::string, std::string>(key, value)).second == false)
        return -1;
    return 0;
}

bool LineMap::isEmpty() const {
    return this->line_map.empty();
}

bool LineMap::canGoToTheNexLine() const{
    if (this->isARet()) return false;
    if (this->isAJump()) {
        if ((this->line_map.find("PARAM3") != this->line_map.end()) 
            || (this->line_map.find("INST")->second == "jmp"))
            return false;
    }
    return true;
}

void LineMap::invalidate() {
    this->status = -1;
    this->line_map.clear();
}

bool LineMap::isValid() const {
    return (this->status == 0);
}
