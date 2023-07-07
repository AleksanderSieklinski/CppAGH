#include "Handler.h"

void handle(){
    try{
        throw;
    }
    catch(BadDimsException &e){
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    catch(std::out_of_range &e){
        std::cout << e.what() << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
}