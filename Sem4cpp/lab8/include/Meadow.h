#pragma once 
#include "Animals.h"
#include <map>
class Meadow{
public:
    //function adding animals to the meadow
    void add(std::unique_ptr<GeneralAnimal> animal);
    //function printing all animals in the meadow using their printing functions
    void print(const std::string &title)const;
    //function counting up how many animals are there with the same same and printing them, all in alphabetical order
    void countNames()const;
    //function returning names of all the sheep that are in the meadow
    std::vector<Sheep*> getSheepHerd()const;
private:
    std::vector<std::unique_ptr<GeneralAnimal>> _animals;
};