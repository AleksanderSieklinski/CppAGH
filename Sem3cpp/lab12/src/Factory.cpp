#include "Factory.h"
int Factory::ile=0,Factory::i=0;
TestObj* Factory::_prototype = nullptr;
TestObj* Factory::tab[3];
TestObj* Factory::produce() {
    i++;
    if(ile==0) {
        tab[i-1] = new TestObj();
        return tab[i-1];
    }
    tab[i-1] = new TestObj(*_prototype);
    return tab[i-1];
}
void Factory::prototype(const TestObj& obj) {
    _prototype = new TestObj(obj);   
    ile++;
}

std::ostream& operator<<(std::ostream& stream, const TestObj* obj)
{
    stream << obj->name();
	return stream;	
}
void Factory::erase() {
    for(int j=0;j<=3;j++) {
        delete tab[j];
    }
    delete _prototype;
    i=0;
    ile=0;
}