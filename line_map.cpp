#include "line_map.h"

/**************** Métodos Privados de GraphGenerator *************************/

bool LineMap::isATag(std::string tag) const {
    if ((tag.find('#') != std::string::npos) || 
        (tag.find('[') != std::string::npos)) {
            return false;
    }
    return true;
}

/**************** Métodos Públicos de GraphGenerator *************************/
LineMap::LineMap(): line_map(std::map<std::string, std::string>()) {
}

LineMap::~LineMap() {
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

std::string LineMap::getTagId() {
    if (!this->line_map.empty()) {
        if (this->line_map.find("TAG") != this->line_map.end())
            return this->line_map.find("TAG")->second;
    }
    return "";
}

std::list<std::string> LineMap::getNeighbors() {
    std::list<std::string> nghbrs;
    if (this->isAJump()) {
        if (isATag(this->line_map.find("PARAM1")->second)) {
            nghbrs.push_back(this->line_map.find("PARAM1")->second); 
        } if (this->line_map.find("PARAM2") != this->line_map.end()) {
            if (isATag(this->line_map.find("PARAM2")->second)) {
                nghbrs.push_back(this->line_map.find("PARAM2")->second); 
            }
        } if (this->line_map.find("PARAM3") != this->line_map.end()) {
            if (isATag(this->line_map.find("PARAM3")->second)) {
                nghbrs.push_back(this->line_map.find("PARAM3")->second); 
            }
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

bool LineMap::canGoToTheNexLine() const{
    if (this->isARet()) return false;
    if (this->isAJump()) {
        if (this->line_map.find("PARAM3") != this->line_map.end())
            return false;
    }
    return true;

}