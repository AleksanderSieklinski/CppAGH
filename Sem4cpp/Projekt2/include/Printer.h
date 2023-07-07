#pragma once
#include "MyArray.h"

class Printer{
public:
  // template method for printing data of type T
  template<typename T>
  void print(const T& data);
  // template method for printing data of type T[N]
  template<typename T, size_t N>
  void print(const T (&data)[N]);
private:
    int _counter = 0;
};

template<typename T, size_t N>
void Printer::print(const T (&data)[N]){
    std::cout << ++_counter << ": ";
    for(const auto& d: data)
      std::cout << d << " ";
    std::cout << std::endl;
}

template<typename T>
void Printer::print(const T& data){
    std::cout << ++_counter << ": " << data << std::endl;
}
  


