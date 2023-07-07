#include"Vector.h"
#include"ComplexNumber.h"
#include <iostream>
using namespace REL;
int main ()
{   
  if(DEBUG){
    std::cout << "Debug mode" << std::endl;
  }
  if(RELEASE){
    std::cout << "Release mode" << std::endl;
  }

  std::string dataPath = DATAPATH;
  std::cout << "data path: " << dataPath << std::endl;

  ComplexNumber liczba (1.2, 0.0);
  liczba.Print();
  std::cout<<"\n";
  
  Vector pierwszy;
  pierwszy.SetY(1.1, 2.1).SetZ(1.3, 2.3);
  pierwszy.Print();

  double modul_1 = ComplexNumber::Abs(pierwszy.X());
  std::cout << "Moduł 1: "<< modul_1 << "\n";
  double modul_2 = static_cast<double>(pierwszy.X());
  std::cout << "Moduł 2: "<< modul_2 << "\n";

  Vector drugi = 1.; // konwersja niejawna
  drugi.Print();

}