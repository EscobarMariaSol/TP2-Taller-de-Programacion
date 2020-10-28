#ifndef CHECKER_H
#define CHECKER_H

#include "graph.h"
#include "graph_generator.h"
#include "dfs.h"

class Checker {

private:
    std::string result;
    void setResult(Dfs& dfs);
    
public:
    Checker();
    ~Checker();
    int verifyFile(const std::string path);
    std::string getResult() const;
};

#endif // CHECKER_H