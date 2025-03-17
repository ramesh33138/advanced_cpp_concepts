#include <iostream>
#include "singleton.h"
//static members we have to initialize outside the class
int Logger::counter = 0;
#ifdef THREAD_SAFE
    std::mutex Logger::mtx;
#endif
Logger* Logger::logger_instance = nullptr;
Logger::Logger() {
    counter++;
    std::cout<<"Number of Instance created "<< counter << std::endl;
}
void Logger::getLog(std::string str) {
    std::cout<< str << counter << std::endl;
}
Logger* Logger::getLogger() {
    if (logger_instance == nullptr) {
        #ifdef THREAD_SAFE
            mtx.lock();
        #endif
        if(logger_instance == nullptr)
            logger_instance = new Logger();
        #ifdef THREAD_SAFE
            mtx.unlock();
        #endif
    }
    return logger_instance;
}