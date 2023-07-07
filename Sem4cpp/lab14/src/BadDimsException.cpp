#include "BadDimsException.h"

BadDimsException::BadDimsException(int a, int b){
    msg = "dimensions " + std::to_string(a) + " and " + std::to_string(b) + " are not compatible";
}

const char* BadDimsException::what() const noexcept{
    return msg.c_str();
}