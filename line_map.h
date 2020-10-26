#ifndef LINE_MAP_H
#define LINE_MAP_H

#include <iostream>
#include <map>
#include <string>
#include <list>

class LineMap {

private:
    std::map<std::string, std::string> line_map;
    bool isARet() const;

public:
    LineMap();
    ~LineMap();
    bool isATag(std::string tag) const;
    bool isAJump() const;
    std::string getTagId();
    std::list<std::string> getNeighbors();
    int add(std::string key, std::string value);
    bool isEmpty() const;
    bool canGoToTheNexLine() const;

};


#endif //LINE_MAP_H