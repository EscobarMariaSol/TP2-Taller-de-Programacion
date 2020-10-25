#ifndef LINE_MAP_H
#define LINE_MAP_H

#include <map>
#include <string>
#include <set>

class LineMap {

private:
    std::map<std::string, std::string> line_map;

public:
    LineMap();
    ~LineMap();
    bool isATag(std::string tag) const;
    bool isAJump() const;
    bool isARet() const;
    std::string getTagId();
    std::set<std::string> getNeighbors();
    int add(std::string key, std::string value);
    bool isEmpty() const;

};


#endif //LINE_MAP_H