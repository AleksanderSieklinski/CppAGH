#ifndef TESTOBJ_H
#define TESTOBJ_H
#include <iostream>
class TestObj {
    public:
    // default constructor printing TestObj()
    TestObj();
    // constructor with string arg printing the name of the object
    TestObj(std::string);
    // constructor with TestObj arg printing the name in a more complex way ;D
    TestObj(const TestObj&);
    // destructor printing the name of the destroyed object
    ~TestObj();
    // function returning the name of the object
    std::string name() const;
    private:
    std::string _name = "default";
};
#endif