// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac strukture MapPoint, ktora reprezentuje punkt na
// mapie skladajacy sie z nazwy, dlugosci (longitude) i szerokosci
// (latitude) geograficznej bez oznaczania polkol.

// Metoda closest pobiera 2 argumenty z których wybiera ten, ktory jest
// najblizej punktu referencyjnego (obiekt na którym metoda została wywołana)
// Odległość między punktami liczymy jako pierwiastek z sumy kwadratów składowych punktu.

// Metoda half_way_to tworzy nowy punkt na mapie o zadanym
// polozeniu, ktore jest srednia arytmetyczna z polozen
// podanych punktow czyli x = (x_1 + x_2)/2

// Należy zadbać o uwzględnienie const w metodach klasy.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod).

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile)

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli dodane pliki i Main.cpp należy wgrać do UPEL 
// jako archiwum tar.gz
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab04/
// * archiwum nie powinno zawierać katalogu build/


#include <iostream>
#include "MapPoint.h"
#include "MapPoint.h"

int main() {
  using std::cout;

  cout<<"========== KRK ==========\n";
  MapPoint krk;
  krk.set_latitude(19.9383);
  krk.set_longitude(50.0613);
  krk.print();

  cout<<"========== NYC ==========\n";
  const double nyc_latitude = 40.7127;
  const double nyc_longitude = -74.0059;
  MapPoint nyc;
  nyc.set_coordinates (nyc_latitude, nyc_longitude);
  nyc.print();

  cout<<"========== PORTO & IRKUTSK ==========\n";
  MapPoint porto;
  porto.set_coordinates(41.1621, -8.6219);
  porto.print();
  MapPoint irkutsk;
  irkutsk.set_coordinates(52.2833, 104.2833);
  irkutsk.print();

  cout<<"========== CLOSEST ==========\n";
  krk.closest(porto, irkutsk).print();

  cout<<"========== SOMEWHERE ==========\n";
  krk.half_way_to(nyc).print();

  return 0;
}
/** Wynik dzialania programu:
========== KRK ==========
Point: (19.9383, 50.0613)
========== NYC ==========
Point: (40.7127, -74.0059)
========== PORTO & IRKUTSK ==========
Point: (41.1621, -8.6219)
Point: (52.2833, 104.283)
========== CLOSEST ==========
Point: (41.1621, -8.6219)
========== SOMEWHERE ==========
Point: (30.3255, -11.9723)
*/