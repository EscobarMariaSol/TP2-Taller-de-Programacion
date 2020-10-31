#ifndef OUTPUT_REPOSITORY_H
#define OUTPUT_REPOSITORY_H

#include <set>
#include <string>
#include <iostream>
#include <mutex>
#include <functional>

class OutputRepository {

private:
    std::set<std::string> outputs;
    std::mutex mutex;

public:
    OutputRepository();
    ~OutputRepository();
    int addOutput(const std::string output);
    void showOutput();
    OutputRepository(const OutputRepository& other);
    OutputRepository& operator=(const OutputRepository& other);
};

#endif // OUTPUT_REPOSITORY_H
