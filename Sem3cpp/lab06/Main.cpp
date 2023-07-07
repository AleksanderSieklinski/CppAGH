// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze zaimplementowac klasy ComplexNumber i Vector. 
// ComplexNumber jest to para liczb, wypisywana w nawiasie
// okraglym. Vector natomiast jest to uporządkowany zbior trzech
// ComplexNumber.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod).

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli dodane pliki i Main.cpp należy wgrać do UPEL 
// jako archiwum tar.gz
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab05/
// * archiwum nie powinno zawierać katalogu build/

#include"Vector.h"
#include"ComplexNumber.h"
#include <iostream>

int main ()
{
  ComplexNumber liczba (1.2, 2.2);
  liczba.Print();
  std::cout<<"\n";
  
  Vector* pierwszy = new Vector;
  pierwszy->SetX(1.1, 2.1).SetY(1.2, 2.2).SetZ(1.3, 2.3);
  pierwszy->Print();

  // zmiana pierwszej wspolrzednej
  pierwszy->X() = ComplexNumber(5.5, 6.6);
  pierwszy->Print();

  // przygotowanie tablicy wspolrzednych wektora
  const Vector *drugi = Vector::CreateConstVector ( // tworzy wektor o zadanym rozmiarze i wartosciach wspolrzednych
                          ComplexNumber(11.1, 12.1), 
                         ComplexNumber(11.2, 12.2), 
                          ComplexNumber(11.3, 12.3)
                          ); 
  drugi->Print();

  std::cout<<"Wspolrzedna X drugiego wektora: ";
  drugi->X().Print();
  std::cout<<"\n";


  std::cout<<"Przenoszenie:\n";
  Vector trzeci (std::move(*pierwszy));
  trzeci.Print();
  pierwszy->Print();

  Vector::Cleanup();
}
/* wynik dzialania programu:
(1.2, 2.2)
[(1.1, 2.1), (1.2, 2.2), (1.3, 2.3)]
[(5.5, 6.6), (1.2, 2.2), (1.3, 2.3)]
[(11.1, 12.1), (11.2, 12.2), (11.3, 12.3)]
Wspolrzedna X drugiego wektora: (11.1, 12.1)
Przenoszenie:
[(5.5, 6.6), (1.2, 2.2), (1.3, 2.3)]
[]
*/
