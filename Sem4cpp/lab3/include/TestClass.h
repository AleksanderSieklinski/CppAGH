#pragma once
#include <string>

class TestClass{
public:
	TestClass(std::string in);
	~TestClass();
	std::string info()const{return txt;}
private:
	std::string txt;
};
