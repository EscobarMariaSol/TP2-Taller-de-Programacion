#ifndef CHECKER_THREAD_H
#define CHECKER_THREAD_H

#include <thread>
#include "file_repository.h"
#include "output_repository.h"

class CheckerThread {

private:
    std::thread thread;
   
public:
    CheckerThread();
    virtual ~CheckerThread();
    void start();
    void join();
    virtual void verifyFile() = 0;
    CheckerThread(const CheckerThread& other) = delete;
    CheckerThread& operator=(const CheckerThread& other) = delete;
    CheckerThread(CheckerThread&& other);
    CheckerThread& operator=(CheckerThread&& other);

};

#endif // CHECKER_THREAD_H