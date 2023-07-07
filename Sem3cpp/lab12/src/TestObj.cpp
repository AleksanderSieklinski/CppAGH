#include "TestObj.h"
TestObj::TestObj() {
    std::cout<< "TestObj::TestObj()"<<std::endl;
}
TestObj::TestObj(std::string name): _name{name}{
    std::cout<< "TestObj::TestObj(\""<< _name << "\")" <<std::endl;
}
TestObj::TestObj(const TestObj& obj): _name{obj._name}{
    std::cout<< "TestObj::TestObj(TestObj(\""<<obj._name <<"\"))" << std::endl;
}
TestObj::~TestObj() {
    std::cout<< "~TestObj(): "<< _name << std::endl;
}
std::string TestObj::name() const {
    return _name;
}