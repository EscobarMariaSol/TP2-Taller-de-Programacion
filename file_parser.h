#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>

#include "line_map.h"


class FileParser {

private:
    std::fstream file;
    
public:
    FileParser(const std::string file_name);
    ~FileParser();
    LineMap parseLine();
    bool hasLine() const;
};

#endif //FILE_PARSER_H
