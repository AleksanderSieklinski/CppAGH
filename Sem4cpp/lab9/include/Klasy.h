#pragma once
#include <vector>
#include <cstring>
#include <functional>


struct ProstaKlasa {
  ProstaKlasa() : data(0) {}
  ProstaKlasa& operator=(int rhs) {
    data = rhs;
    return *this;
  }
  int data;

private:
/*  ProstaKlasa& operator=(const ProstaKlasa& rhs) { // po napisaniu swap mozna zakomentowac
    std::cout  << " Dzialania tego operatora nie chcemy widziec " << std::endl;
    data = rhs.data;
    return *this;
  }
*/
};


struct SkomplikowanaKlasa {

  SkomplikowanaKlasa() : data("") {}
  SkomplikowanaKlasa& operator=(const std::string& rhs) {
    data = rhs;
    return *this;
  }
  SkomplikowanaKlasa& operator=(const SkomplikowanaKlasa& rhs) {
    std::cout  << " Dzialane tego operatora musimy widziec " << std::endl;
    data = rhs.data;
    return *this;
  }
  std::string data;
};


