#include <iostream>
#include <thread>
#include <mutex>
class Logger{
    static int counter;
    static Logger* logger_instance;
    #ifdef THREAD_SAFE
        static std::mutex mtx;
    #endif
    Logger();// by making private we can control the object creation
    public:
        Logger(const Logger&) = delete; //not allowing the copy 
        Logger operator=(const Logger&) = delete;//copy assignment also not allowing
        void getLog(std::string str);
        static Logger* getLogger(); //obj creation will be happened inside this function
};