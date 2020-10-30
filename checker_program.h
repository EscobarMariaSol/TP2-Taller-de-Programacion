#ifndef CHECKER_PROGRAM_H
#define CHECKER_PROGRAM_H

#include "file_repository.h"
#include "checker.h"
#include "output_repository.h"
#include <vector>

class CheckerProgram {

private:
    FileRepository file_repo;
    OutputRepository output_repo;
    void saveFiles(std::vector<std::string>& files);
    int verifyFiles();

public:
    CheckerProgram();
    ~CheckerProgram();
    int start(std::vector<std::string>& files);
};

#endif // CHECKER_PROGRAM_H