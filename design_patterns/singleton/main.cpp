#include <iostream>
#include "singleton.h"
#include <thread>
void process1() {
    Logger* logger1 = Logger::getLogger();
    logger1->getLog("Logged by logger1 from instance");
}

void process2 () {
    Logger* logger2 = Logger::getLogger();
    logger2->getLog("Logged by logger2 from instance");
}

int main (int argc, char** args) {
    /** Not Thread safe
    Logger* logger1 = Logger::getLogger();
    logger1->getLog("Logged by logger1 from instance");
    Logger* logger2 = Logger::getLogger();
    logger2->getLog("Logged by logger2 from instance");
    */
    std::thread t1(process1);
    std::thread t2(process2);

    if (t1.joinable())
        t1.join();
    if(t2.joinable())
        t2.join();
    return 0;
}