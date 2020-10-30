#ifndef OUTPUT_REPOSITORY_H
#define OUTPUT_REPOSITORY_H

#include <set>
#include <string>
#include <iostream>

class OutputRepository {

private:
    std::set<std::string> outputs;

public:
    OutputRepository();
    ~OutputRepository();
    int addOutput(const std::string output);
    void showOutput() const;
};

#endif // OUTPUT_REPOSITORY_H
