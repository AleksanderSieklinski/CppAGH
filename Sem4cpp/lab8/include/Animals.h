#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "GeneralAnimal.h"

class Sheep: public GeneralAnimal{
public:
    //constructor of Sheep that creates it by using GeneralAnimal as a base and adding a bool sheared value
    explicit Sheep(const std::string &name):GeneralAnimal(name),_sheared(false){}
    //function shearing a sheep, changing bool sheared value
    void shear(){_sheared = true;}
    //function printing the name of the species, name of the animal and the status of shearing
    void print()const override;
    //destructor printing the name of species, name of animal, and the name of its home
    ~Sheep();
private:
    bool _sheared;
};

class Cow: public GeneralAnimal{
public:
    //constructor of Cow that creates it by using GeneralAnimal as a base
    explicit Cow(const std::string &name):GeneralAnimal(name){}
    //function printing the name of the species, name of the animal and the status of shearing
    void print()const override;
    //destructor printing the name of species, name of animal, and the name of its home
    ~Cow();
};

class Horse: public GeneralAnimal{
public:
//constructor of Cow that creates it by using GeneralAnimal as a base
    explicit Horse(const std::string &name):GeneralAnimal(name){}
    //function printing the name of the species, name of the animal and the status of shearing
    void print()const override;
    //destructor printing the name of species, name of animal, and the name of its home
    ~Horse();
};
