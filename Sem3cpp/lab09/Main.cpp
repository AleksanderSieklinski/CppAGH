// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze zaimplementowac klasy Point w dwóch różnych przestrzeniach nazw,
// odpowiednio MTH, oraz MP. Klasa MTH::Point zawiera dwie składowe x, y 
// do przechowania współrzędnych; klasa MP::Point zawiera longitude, lattidude
// do przechowania współrzędnych, oraz label do przechowania nazwy punktu;
// Dodatkowo, proszę zaimplementować operatory przypisania, aby wynikiem działania
// programu był wynik przedstawiony poniżej.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod), oraz powinna być spełniona zasada
// D.R.Y. - Don't Repeat Yourself.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli dodane pliki i Main.cpp należy wgrać do UPEL 
// jako archiwum tar.gz
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab08/
// * archiwum nie powinno zawierać katalogu build/

#include "MapPoint.h"
#include <iostream>

int main ()
{
  const MTH::Point mth_p(0.2,0.1); 
  MTH::Print(mth_p);

  MP::Point map_p1("MP1", 0.1,0.2); 
  MP::Print(map_p1);

  MP::Point map_p2("MP2",mth_p); 
  MP::Print(map_p2);

  map_p1 = mth_p;
  MP::Print(map_p1);

  map_p1 = map_p1;
}
/* wynik dzialania programu:
[MTH::Point] X=0.2 Y=0.1
[MP::Point] MP1: Lattitude=0.1 Longitute=0.2
[MP::Point] MP2: Lattitude=0.2 Longitute=0.1
[MP::Point] MP1: Lattitude=0.2 Longitute=0.1
[MP::Warning] Discarding self-assignment
*/