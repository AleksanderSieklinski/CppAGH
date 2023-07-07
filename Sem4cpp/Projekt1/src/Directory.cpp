#include "Directory.h"

Directory::~Directory() {
    for (int i = 0; i < files.size(); ++i) {
        if (files[i] != nullptr) {
            delete files[i];
        }
    }
}
void Directory::print(int level) const{
    if (copied == 0) {
        for (int i = 0; i < level; ++i) {
            std::cout << "__";
        }
        std::cout << name << std::endl;
        for (int i = 0; i < files.size(); ++i) {
            files[i]->print(level+1);
        }
    }
    else {
        for (int i = 0; i < level; ++i) {

            std::cout << "__";
        }
        std::cout << name << std::endl;
        for (int i = 0; i < files.size(); ++i) {
            if(i==0) {
                files[i]->print(level+copied);
            }
            else {
                files[i]->print(level+1+copied);
            }
        }
    }
}
File* Directory::operator-=(std::string name){
    for (int i = 0; i < files.size(); ++i) {
        if (files[i]->name == name) {
            File* file = files[i];
            files.erase(files.begin()+i);
            return file;
        }
    }
    return nullptr;
}
File* Directory::operator+=(File* file){
    files.push_back(file);
    return this;
}
File* Directory::operator>>(File& file){
    Directory* dir = dynamic_cast<Directory*>(&file);
    for (int i = 0; i < files.size(); ++i) {
        dir->files.push_back(files[i]);
    }
    files.clear();
    return &file;
}
void Directory::rename(std::string name){
    this->name = name;
}
File* Directory::copy(File* file){
    if(Directory* dir = dynamic_cast<Directory*>(file)) {
        copied++;
        files.push_back(new Directory(dir->name));
        for (int i = 0; i < dir->files.size(); ++i) {
            files.push_back(dir->files[i]->clone());
        }
    }
    else {
        files.push_back(file->clone());
    }
    return this;
}
File* Directory::clone(){
    Directory* dir = new Directory(name);
    for (int i = 0; i < files.size(); ++i) {
        dir->files.push_back(files[i]->clone());
    }
    return dir;
}