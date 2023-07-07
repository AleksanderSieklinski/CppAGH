// Calem zadania jest przećwiczenie operatora() i jego 
// wykorzystania w połączeniu z std::function.
//
// Proszę napisać klasy reprezentujące funkcje matematyczne:
// - Sin -- sin(a*x+b)
// - Linear -- funkcja liniowa a*x+b
// 
// Mają one operator(), który zwraca odpowiednią wartość funkcji.
// (mogą być we wspólnych plikach Functions.h i Functions.cpp)
// 
// Proszę także napisać klasę FunctionSeries, która przyjmuje
// i przechowuje obiekty funkcyjne i pozwala na obliczenie wyniku
// kolejnych wywołań, np. dla dwóch funkcji f1 i f2 w serii:
//
// FunctionSeries f 
// ...
// f.calc(x) := f2( f1(x) )
//
// przechowuje ona wyniki wszystkich pośrednich obliczeń, do których
// mamy dostęp przez funkcję step.
// UWAGA: polecane użycie std::vector
//
// Pliku lab02.cpp proszę nie modyfikować.
// Program proszę kompilować przynajmniej z flaga -Wall.
// 

#include "Functions.h"
#include "FunctionSeries.h"
#include <iostream>
#include <cmath>

double rec(double x){
	return x>0 ? x : 0;
}

int main()
{
  Sin sinus(M_PI, M_PI/3.);
  const Linear lin(-0.25, 1.0);

  double x = 10;

  std::cout << sinus(x) << std::endl; 
  std::cout << lin(x) << std::endl; 
  auto sqrtlambda = [](double x){return sqrt(x);}; 
  
  FunctionSeries fs;
  fs.insert(sinus);
  fs.insert(lin);
  fs.insert(sqrtlambda);
  fs.insert(rec);

  double result1 = fs.calculate(x);
  double result2 = rec(sqrtlambda(lin(sinus(x))));

  std::cout << "-- dla x=10:\t" << result1 << ", " << result2 << std::endl; 

  x=0.5;
  std::cout << "-- dla x=0.5:\t" << fs.calculate(x) << std::endl;

  // Wypisujemy wyniki pośrenich obliczeń 
  std::cout << "posrednie wyniki: " << std::endl;
  double sinx = sinus(x);
  std::cout << sinx << ", " << fs.step(0) << std::endl; 
  std::cout << lin(sinx) << ", " << fs.step(1) << std::endl; 
  std::cout << sqrt(lin(sinx)) << ", " << fs.step(2) << std::endl; 
}
/* wynik dzialania programu:

0.866025
-1.5
-- dla x=10:	0.885152, 0.767349
-- dla x=0.5:	0.935414
posrednie wyniki: 
0.5, 0.5
0.875, 0.875
0.935414, 0.935414

*/