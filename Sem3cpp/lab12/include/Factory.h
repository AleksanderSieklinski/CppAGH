#ifndef FACTORY_H
#define FACTORY_H
#include "TestObj.h"

std::ostream& operator<<(std::ostream&,const TestObj*);

class Factory {
    public:
    // function generating a new TestObj dependant if prototype exists
    static TestObj* produce();
    // creates a new prototype object that produce() will use
    static void prototype(const TestObj&);
    // freeing all memory allocated to created objects
    static void erase();
    private:
    static TestObj* _prototype;
    static int ile,i;
    static TestObj* tab[];
};
#endif