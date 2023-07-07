#include <iostream>
void PrintInfo(const char*name) {
    std::cout << name << std::endl;
}
void PrintName(const char*name) {
    std::cout << "Name: ";
    PrintInfo(name);
}
