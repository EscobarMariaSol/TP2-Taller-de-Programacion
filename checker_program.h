#ifndef CHECKER_PROGRAM_H
#define CHECKER_PROGRAM_H

#include "file_repository.h"
#include "checker.h"
#include "output_repository.h"

class CheckerProgram {

private:
    FileRepository file_repo;
    OutputRepository output_repo;
    void saveFiles(const char *files[]);
    int verifyFiles();

public:
    CheckerProgram();
    ~CheckerProgram();
    int start(const char *files[]);
};

#endif // CHECKER_PROGRAM_H