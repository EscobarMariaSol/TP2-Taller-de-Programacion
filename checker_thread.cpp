#include "checker_thread.h"

/******************* Funciones Públicas de CheckerThread *********************/

CheckerThread::CheckerThread() {
}

CheckerThread::~CheckerThread() {
}

void CheckerThread::start(){
    thread = std::thread(&CheckerThread::verifyFile, this);
}
    
void CheckerThread::join() {
    thread.join();
}

CheckerThread::CheckerThread(CheckerThread&& other){
    this->thread = std::move(other.thread);
}

CheckerThread& CheckerThread::operator=(CheckerThread&& other) {
    this->thread = std::move(other.thread);
    return *this;
}
