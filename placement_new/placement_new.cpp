#include <iostream>

class Base {
    uint data;
    public:
        Base() {
            std::cout << "constructed the object" << std::endl;
        }
        ~Base() {
            std::cout << "Destructed the object " << std::endl;
        }
};

int main (int argc, char* args[]) {
    std::cout << "Base class size : " << sizeof(Base) << std::endl;
    // normal memory allocation : it switches user mode to kernel mode and kernel will allocate the memory
    Base* obj = new Base();
    std::cout << "Base class obj size : " << sizeof(obj) << std::endl;
    delete obj;
    //problem : if we want to allocate  memory for 10 objects, this occasion switching is too costly. it will reduce the execution speed
    //Base* obj1 = new Base();
    //Base* obj2 = new Base();
    //Base* obj3 = new Base();
    //soln : we have to create memory pool inside that pool we can construct and destruct our objects. In this way we can manually call destructor

    char* mem_pool = new char[10 * sizeof(Base)];
    Base* obj1 = new (&mem_pool[0])  Base;
    Base* obj2 = new (&mem_pool[4])  Base;
    Base* obj3 = new (&mem_pool[8])  Base;

    //destructor call
    obj1 -> ~Base();
    obj2 -> ~Base();
    obj3 -> ~Base();

    delete[] mem_pool;
    return 0;
}