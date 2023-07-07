#pragma once
#include <iostream>
#include <string>
#include <vector>
class File {
    public:
        //constructor of File creates new File with name and level of depth
        File(std::string name,int level=0) : name(name){}
        //default destructor of File
        virtual ~File()=default;
        //print prints name of file with level of depth
        virtual void print(int level=0) const {for(int i = 0; i < level; i++){std::cout << "__";}std::cout << name << std::endl;}
        //operator-= does nothing, defined to be overriden in Directory
        virtual File* operator-=(std::string name){return nullptr;}
        //operator+= does nothing, defined to be overriden in Directory
        virtual File* operator+=(File* file){return nullptr;}
        //operator>> does nothing, defined to be overriden in Directory
        virtual File* operator>>(File& file){return nullptr;}
        //rename renames file
        virtual void rename(std::string name){this->name = name;}
        //clone creates new File with same name
        virtual File* clone(){return new File(name);}
        std::string name;
};