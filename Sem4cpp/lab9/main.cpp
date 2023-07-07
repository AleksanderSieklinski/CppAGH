// Celem zadania jest utworzenie ogólnej metody sortujacej wykorzystujacej 
// zoptymalizowana funkcje swap.
//
// Nalezy napisac szablon funkcji bubble_sort (implementacja jest prosta)
// for ( i = 0; i < N; i++ )
//    for (j = i+1; j < N; ++j ) 
//       if (porownanie(tablica[i], tablica[j]))
//          swap(tablica[j], tablica[i])
//
// Tu uogolnieniem powinna byc mozliwosc podania funkcji porownania (sa one ponizej)
// Funkcja swap powinna istniec w dwoch wariantach: 
// - dla typow "pod" (Plain Old Data) powinna korzystac z memcpy (#include <string.h>)
// 	memcpy(cel, zrodlo, ilosc_bajtow);  (3 razy)
// - dla typu SkomplikowanaKlasa nalezy uzyc "zwyklej" zamiany z wywolaniem
//   konstruktora kopiującego obiektu tymczasowego itd. 
// 
// Do zadania dołączone dwie klasy: ProstaKlasa, ktorej obiekty mozna kopiowac za pomoca 
// memcpy i SkomplikowanaKlasa obiektow, ktorej nie mozna tak kopiowac.

#include <iostream>
#include "func.h"
#include "Klasy.h"
#include <iomanip>
#include <ctime>


struct tools {
  template<class T>
  static bool desc( const T& a, const T& b) {
    return a.data < b.data;
  }

  template<class T>
  static bool asc( const T& a, const T& b) {
    return a.data > b.data;
  }
};

int main() {
	std::vector<ProstaKlasa> k(5);
	k[0] = 3;
	k[1] = 1;
	k[2] = 4;
	k[3] = 2;
	k[4] = 5;

	time_t start,end;

	for (auto &val: k) std::cout << val.data << std::endl;

	std::cout << "posortowane od max do min" << std::endl;
	bubble_sort(k, tools::desc<ProstaKlasa>); 
	for (auto &val: k) std::cout << val.data << std::endl;

	std::cout << "posortowane od min do max" << std::endl;
	bubble_sort(k, tools::asc<ProstaKlasa>);
	for (auto &val: k) std::cout << val.data << std::endl;

	std::cout << "=== klasa skomplikowana ===" << std::endl;
	std::vector<SkomplikowanaKlasa> l(4);
	l[0] = "3";
	l[1] = "A";
	l[2] = "4";
	l[3] = "5555";

	bubble_sort(l, tools::desc<SkomplikowanaKlasa>);
	for (auto &val: l) std::cout << val.data << std::endl;
	
	std::cout << "=== double ===" << std::endl;
	std::vector<double> m{2.1, 0.5, 4., 0.1};
	// poniższe wywołanie działa przy ogólniejszej składni
	bubble_sort(m, [](const double& a, const double& b){return a > b;}); 
	for (auto &val: m) std::cout << val << std::endl;
	
	// ciekawoska: jak napisać szablon poniższej funkcji print?
	std::cout << "=== tablica ===" << std::endl;
	double vals[4] = {4.2, 1., 0.5};

	int start_s=clock() ; 
	for (int i=0;i<28370;i++) {
		print(vals);
	}
	int stop_s=clock(); 
	std::cout<<stop_s-start_s<<std::endl;


}
/* wyniki
3
1
4
2
5
posortowane od max do min
5
4
3
2
1
posortowane od min do max
1
2
3
4
5
=== klasa skomplikowana ===
 Dzialane tego operatora musimy widziec 
 Dzialane tego operatora musimy widziec 
 Dzialane tego operatora musimy widziec 
 Dzialane tego operatora musimy widziec 
 Dzialane tego operatora musimy widziec 
 Dzialane tego operatora musimy widziec 
 Dzialane tego operatora musimy widziec 
 Dzialane tego operatora musimy widziec 
A
5555
4
3
=== double ===
0.1
0.5
2.1
4
=== tablica ===
4.2
1
0.5
0

 */
