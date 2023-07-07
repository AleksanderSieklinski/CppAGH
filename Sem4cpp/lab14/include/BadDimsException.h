#pragma once
#include <iostream>
#include <string>

class BadDimsException : public std::exception{
    std::string msg;
public:
    //constructor of BadDimsException creates a message that says that dimensions a and b are not compatible
    BadDimsException(int a, int b);
    //constructor of BadDimsException creates a message that explains the exception
    BadDimsException(const std::string& msg):msg(msg){}
    //what returns the message of the exception
    const char* what() const noexcept override;
};