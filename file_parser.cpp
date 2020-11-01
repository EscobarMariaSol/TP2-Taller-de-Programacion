#include "file_parser.h"

/******************** Funciones Auxiliares de FileParser *********************/

// Función que separa las palabras de un string de acuerdo a un delimitador
// Pre: recibe un string y un delimitador
// Pos: devuelve una lista con las palabras que se encuentran separadas por 
// el delimitador
static std::list<std::string> split(const std::string line, const char sep) {
    std::list<std::string>  new_list;
    std::string str;
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

// Función que inserta el nombre de una etiqueta en el LineMap
// Pre: recibe la lista con las palabras de la linea actual del archivo 
// y el LineMap
// Pos: devuelve 0 en caso de que la etiqueta se haya agregado, -1 si
// se registra algun error en el proceso
static int tagInsert(std::list<std::string>& my_list, LineMap& mapped) {
    my_list.front().pop_back();
    if (mapped.add("TAG", std::move(my_list.front())) < 0) return -1;
    return 0;
}

// Función que inserta el nombre de una instrucción en el LineMap
// Pre: recibe la lista con las palabras de la linea actual del archivo 
// y el LineMap
// Pos: devuelve 0 en caso de que la instrucción se haya agregado, -1 si
// se registra algun error en el proceso
static int instructionInsert(std::list<std::string>& my_list, LineMap& mapped) {
    if (mapped.add("INST", std::move(my_list.front())) < 0) return -1;
    return 0;
}

// Función que inserta el nombre de un parámetro en el LineMap
// Pre: recibe la lista con las palabras de la linea actual del archivo 
// y el LineMap
// Pos: devuelve 0 en caso de que el parametro se haya agregado, -1 si
// se registra algpun error en el proceso
static int paramInsert(std::list<std::string>& my_list, LineMap& mapped, int pos) {
    if (my_list.front().back() == ',') my_list.front().pop_back();
    std::string param = "PARAM" + std::to_string(pos);
    if (mapped.add(param, std::move(my_list.front())) < 0) return -1;
    return 0;
}

// Función que realiza la lógica para detectar a qué funciones llamar
// para agregar un elemento en el LineMap, de acuerdo al tipo de elemento
// Pre: recibe el LineMap, la lista con las palabras de la linea actual del  
// archivo y la posición de la lista en la que se encuentra.
// Pos: devuelve 0 en caso de que la etiqueta se haya agregado, -1 si
// se registra algpun error en el proceso
static int insertElement(LineMap& mapped, 
    std::list<std::string>& my_list, int& pos) {
    if (my_list.front().back() == ':')
            return tagInsert(my_list, mapped);
    if (pos == 0) {
        if (instructionInsert(my_list, mapped) < 0) return -1;
    } else {
        if (paramInsert(my_list, mapped, pos) < 0) return -1;
    }
    pos++;
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
        if (insertElement(mapped, my_list, pos) < 0) {
            mapped.invalidate();
            break;
        }
        my_list.pop_front();
    }
    return mapped;
}

bool FileParser::hasLine() const {
    return !this->file.eof();
}