#include "SmartPtr.h"

SmartPtr::SmartPtr(TestClass* ptr):ptr(ptr),ile(new int(1)){}

SmartPtr::SmartPtr(const SmartPtr& sp):ptr(sp.ptr),ile(sp.ile){
    (*ile)++;
}
SmartPtr::SmartPtr(SmartPtr&& sp):ptr(sp.ptr),ile(sp.ile){
    sp.ptr=nullptr;
    sp.ile=nullptr;
}
SmartPtr::~SmartPtr(){
    if(ptr==nullptr) return;
    (*ile)--;
    if(*ile==0){
        delete ptr;
        delete ile;
    }
}

SmartPtr& SmartPtr::operator=(const SmartPtr& sp){
    if(this!=&sp){
        (*ile)--;
        if(*ile==0){
            delete ptr;
            delete ile;
        }
        ptr=sp.ptr;
        ile=sp.ile;
        (*ile)++;
    }
    return *this;
}
SmartPtr& SmartPtr::operator=(SmartPtr&& sp){
    if(this!=&sp){
        (*ile)--;
        if(*ile==0){
            delete ptr;
            delete ile;
        }
        ptr=sp.ptr;
        ile=sp.ile;
        sp.ptr=nullptr;
        sp.ile=nullptr;
    }
    return *this;
}
TestClass& SmartPtr::operator*()const{
    return *ptr;
}

TestClass* SmartPtr::operator->()const{
    return ptr;
}

SmartPtr::operator bool()const{
    return ptr;
}

int SmartPtr::useCount()const{
    return *ile;
}
