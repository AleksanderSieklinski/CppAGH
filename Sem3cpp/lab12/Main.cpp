// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klase TestObj, ktora ma "glosne" (tzn. wypisujace
// tekst) konstruktory i destruktor. Dodatkowo ta klasa ma nazwę.

// Prosze napisac klasę Factory, ktora tworzy obiekty typu TestObj na
// podstawie zadanego wzorca. Jeżeli nie zostanie ustawiony żaden
// wzorzec, to tworzone sa obiekty przy użyciu domyślnego
// konstrutora. Od chwili gdy jest ustawiony jakiś wzorzec, tworzone
// sa kopie obiektu wzorcowego.
// Dodatkowo, dla klasy TestObj należy zdefiniować przeciążenie operatora
// << na standardowe wyjście, tj. std::ostream.

// Prosze zadbac o dobre zarzadzanie pamiecia.
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
// * archiwum powinno zawierać katalog z zadaniem, np. lab12/
// * archiwum nie powinno zawierać katalogu build/


#include <iostream>
#include "TestObj.h"
#include "Factory.h"

int main() {
  { // test funkcjonalnosci kl. TestObj
    delete new TestObj();
    delete new TestObj("any");
    TestObj never("mind");
    delete new TestObj(never);
  }
  std::cout << "Factory:"<<std::endl;
    
  TestObj *test(nullptr); 
  test = Factory::produce();
  std::cout << "1: " << test << std::endl;
  test = Factory::produce();
  std::cout << "2: " << test << std::endl;
  {
    TestObj newPrototype("better prototype");    
    Factory::prototype(newPrototype);
  }

  test = Factory::produce();
  std::cout << "3: " << test << std::endl;
  test = Factory::produce();
  std::cout << "4: " << test << std::endl;
  std::cout << "Clear memory" << std::endl;
  Factory::erase();
}
/* wynik:
TestObj::TestObj()
~TestObj(): default
TestObj::TestObj("any")
~TestObj(): any
TestObj::TestObj("mind")
TestObj::TestObj(TestObj("mind"))
~TestObj(): mind
~TestObj(): mind
Factory:
TestObj::TestObj()
1: default
TestObj::TestObj()
2: default
TestObj::TestObj("better prototype")
TestObj::TestObj(TestObj("better prototype"))
~TestObj(): better prototype
TestObj::TestObj(TestObj("better prototype"))
3: better prototype
TestObj::TestObj(TestObj("better prototype"))
4: better prototype
Clear memory
~TestObj(): default
~TestObj(): default
~TestObj(): better prototype
~TestObj(): better prototype
~TestObj(): better prototype
*/