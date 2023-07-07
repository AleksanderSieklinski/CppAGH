#pragma once
#include "TestClass.h"
#include <iostream>
class SmartPtr{
public:
    SmartPtr(TestClass* ptr);
    SmartPtr(const SmartPtr& sp);
    SmartPtr(SmartPtr&& sp);
    ~SmartPtr();
    SmartPtr& operator=(const SmartPtr& sp);
    SmartPtr& operator=(SmartPtr&& sp);
    TestClass& operator*()const;
    TestClass* operator->()const;
    operator bool()const;
    int useCount()const;
private:
    TestClass* ptr;
    int *ile;
};