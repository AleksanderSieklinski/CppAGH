#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

class Member {
public:
    //constructor creating a member with a name
    Member(std::string name) : name(name) {}
    //function to set the power level of a member
    Member& power(int p) { power_ = p; return *this; }
    //function to set the magic level of a member
    Member& magic(int m) { magic_ = m; return *this; }
    //function to set the health level of a member
    Member& health(int h) { health_ = h; return *this; }
    //function to get the power level of a member
    int power() const { return power_; }
    //function to get the magic level of a member
    int magic() const { return magic_; }
    //function to get the health level of a member
    int health() const { return health_; }
    //function to get the name of a member
    std::string getName() const { return name; }
private:
    int power_ = 0;
    int magic_ = 0;
    int health_ = 0;
    std::string name;
};