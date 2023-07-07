#pragma once
#include <string>

class GeneralAnimal{
public:
	explicit GeneralAnimal(const std::string &name):_name(name){}
	virtual ~GeneralAnimal(){}
	std::string name()const{return _name;}
	virtual void print()const = 0;
private:
	std::string _name; // imię zwierzęcia
};
