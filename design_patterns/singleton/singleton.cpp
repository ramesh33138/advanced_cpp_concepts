#include <iostream>
#include "singleton.h"
//static members we have to initialize outside the class
int Logger::counter = 0;
Logger* Logger::logger_instance = nullptr;
Logger::Logger() {
    counter++;
    std::cout<<"Number of Instance created "<< counter << std::endl;
}
void Logger::getLog(std::string str) {
    std::cout<< str << counter << std::endl;
}
Logger* Logger::getLogger() {
    if(logger_instance == nullptr)
        logger_instance = new Logger();
    return logger_instance;
}