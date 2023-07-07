#pragma once
#include "Directory.h"

class Symlink : public File {
    File* file;
public:
    //constructor of Symlink creates new Symlink with name and level of depth
    Symlink(std::string name, File* file);
    //print prints name of Symlink with level of depth
    virtual void print(int level=0) const override;
    //operator-> returns the file inside Symlink
    virtual File* operator->() const;
};