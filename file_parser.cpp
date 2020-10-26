#include "file_parser.h"

/******************** Funciones Auxiliares de FileParser *********************/

std::list<std::string> split(const std::string line, const char sep) {
    std::list<std::string>  new_list;
    std::string str("");
    for (size_t i = 0; i < line.size(); i++) {
        if (line[i] != sep) {
            str += line[i];
        } else if (str.size() > 0) {
            new_list.push_back(std::move(str));
            str.resize(0);
        }
    }
    if (str.size() > 0) new_list.push_back(std::move(str));
    return new_list;
}

int tagInsert(std::list<std::string>& my_list, LineMap& mapped) {
    my_list.front().pop_back();
    mapped.add("TAG", std::move(my_list.front()));
    return 0;
}

int instructionInsert(std::list<std::string>& my_list, LineMap& mapped) {
    mapped.add("INST", std::move(my_list.front()));
    return 0;
}

int paramInsert(std::list<std::string>& my_list, LineMap& mapped, int pos) {
    if (my_list.front().back() == ',') my_list.front().pop_back();
    std::string param = "PARAM" + std::to_string(pos);
    mapped.add(param, std::move(my_list.front()));
    return 0;
}

/******************** Métodos Públicos de FileParser *************************/

FileParser::FileParser(const std::string file_name) {
    this->file.open(file_name, std::fstream::in);
}

FileParser::~FileParser() {
    file.close();
}

LineMap FileParser::parseLine() {
    std::string line;
    std::list<std::string> my_list;
    LineMap mapped;
    std::getline(file, line);
    int pos = 0;
    my_list = split(line, ' ');
    while (!my_list.empty()) {
        if (my_list.front().back() == ':') {
            tagInsert(my_list, mapped);
        } else {
            if (pos == 0) instructionInsert(my_list, mapped);
            else
                paramInsert(my_list, mapped, pos);
            pos++;
        }
        my_list.pop_front();
    }
    return mapped;
}

bool FileParser::hasLine() const {
    return !this->file.eof();
}