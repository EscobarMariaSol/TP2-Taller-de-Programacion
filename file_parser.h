#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>


class FileParser {

private:
    std::fstream file;
    
public:
    FileParser(const std::string file_name);
    ~FileParser();
    std::map<std::string, std::string> parseLine();
};

#endif //FILE_PARSER_H
