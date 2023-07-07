// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na koncu tego
// pliku.

// Prosze napisac klasę Fraction reprezentujacą ułamek i
// klasę FractionArray - reprezentującą tablicę ułamków.

// Klasa Maths zawiera narzędzie do wyliczania
// największego wspólnego dzielnika, przydatne do skracania
// ułamków (funkcja simlify).
// Oprócz tego proszę zaimplementować operatory dodawania +, 
// mnożenia *, wypisania na wyjście standardowe, konwersję do double Fraction
// i operator[] dla klasy FractionArray.
// 
// W wybranych miejscach po odkomentowaniu program nie powinien się kompilować.

// Pliku lab01.cpp nie modyfikujemy (poza odkomentowaniem "błędnych" linii.

// Program prosze kompilowac przynajmniej z flaga -Wall.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.


#include "Fraction.h"
#include "FractionArray.h"
#include <iostream>

int main()
{
  Fraction f1(6,8);
  const Fraction f2(1,2);

  std::cout << f1 << std::endl; 
  std::cout << f2 << std::endl; 

  double val = double(f1);
  std::cout << "Ułamek dziesiętny f1: " << val << std::endl; 

  std::cout << "Po skroceniu:" << std::endl; 

  f1.simplify(); 

  std::cout << f1 << std::endl; 
  std::cout << f2 << std::endl; 
  
  std::cout << "Prosta matematyka:" << std::endl; 
  Fraction f3 = f1 * f2;
  std::cout << "Iloczyn: " << f3 << std::endl; 
  std::cout << "Suma: " << f1 + f2 << std::endl; 
  std::cout << "Znow iloczyn: " << 3 * f2 << std::endl; 

  //f1+f2 = f3; // co zrobić, by się nie kompilowało po odkomentowaniu?

  FractionArray tab(2);
  tab[0] = f1; //OK
  f1 = tab[0]; //OK
  std::cout << tab[0] << ", " << f1 << std::endl; 

  const FractionArray tab_const(2);
  f1 = tab_const[1]; // OK
  //tab_const[0] = f1; // ma się nie kompilować,
  // ponieważ chcemy zapobiec modyfikowaniu obiektów const

  return 0;
}
/* Oto wynik dzialania programu:
6/8
1/2
Ułamek dziesiętny f1: 0.75
Po skroceniu:
3/4
1/2
Prosta matematyka:
Iloczyn: 3/8
Suma: 10/8
Znow iloczyn: 3/2
3/4, 3/4
*/