#pragma once
#include "File.h"
class Directory: public File {
    std::vector<File*> files;
    int copied = 0;
    public:
        //constructor of Directory creates new Directory with name and level of depth
        Directory(std::string name) : File(name) {}
        //destructor of Directory removes all files
        virtual ~Directory()override;
        //print prints all files in directory with level of depth
        virtual void print(int level=0)const override;
        //operator-= removes file from directory
        virtual File* operator-=(std::string name)override;
        //operator+= adds new file to directory
        virtual File* operator+=(File* file)override;
        //operator>> moves all files from directory to other directory
        virtual File* operator>>(File& file)override;
        //rename renames directory
        virtual void rename(std::string name)override;
        //copy copies directory using clone
        File* copy(File* file);
        //clone creates new Directory with same name and files
        virtual File* clone();
};