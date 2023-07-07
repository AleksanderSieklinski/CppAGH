#include "TestClass.h"
#include <iostream>

TestClass::TestClass(std::string in):txt(in){
	std::cout << "++ Tworze obiekt TestClass: " << txt << std::endl;
}
TestClass::~TestClass(){
	std::cout << "-- Usuwam obiekt TestClass: " << txt << std::endl;
}
