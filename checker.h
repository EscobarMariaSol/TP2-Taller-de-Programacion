#ifndef CHECKER_H
#define CHECKER_H

#include "graph.h"
#include "graph_generator.h"
#include "dfs.h"
#include "checker_thread.h"

class Checker: public CheckerThread {

private:
    std::string result;
    FileRepository& file_repo;
    OutputRepository& output_repo;
    void setResult(Dfs& dfs);
    std::string createOutput(std::string& path);
    
public:
    Checker(FileRepository& file_repo, OutputRepository& output_repo);
    ~Checker();
    void verifyFile();
};

#endif // CHECKER_H