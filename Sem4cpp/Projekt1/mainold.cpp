/*
 Celem zadania jest napisanie kilku klas związanych relacją
 dziedziczenia. Klasy te opisują system plików.

 - funkcja print() wypisuje dla klas:
   - File - nazwę pliku klasy 
   - Directory - strukturę i zawartość podkatalogów (patrz w treści) 
  
 - do wypisania wcięć można przekazać do print zmienną informującą 
   o poziomie.
 - do katalogu można dodawać inne pliki (i katalogi): katalog += plik
 - oraz usuwać (bezpośrednio, bez wyszukiwania niżej): katalog -= nazwa pliku
 - można przenosić zawartość katalogu w inne miejsce: operator >>

 Uwaga: 
 - można użyć std::vector oraz std::string. 
 - na laboratoriach zadanie zostanie rozbudowane o nowe funkcjonlaności.
 */

#include <iostream>
#include "File.h"
#include "Directory.h"

int main() {
  Directory *ppo = new Directory("PPO");
  *ppo += new File("main.cpp");
  ppo->print();
  
  Directory *src = new Directory("src");
  File* cppFile = new File("Klasa.h");
  cppFile->print(); 
  *src += cppFile;
  *src += new File("Klasa.cpp");

  std::cout << "=========== src: ===========" << std::endl;
  File *srcPtr = src;
  srcPtr->print();

  std::cout << "=========== ppo: ===========" << std::endl;
  *ppo += src;
  ppo->print();

  File *h = *src -= "Klasa.h"; // jeśli brak takiego pliku, to zwraca nullptr
  std::cout << "========== ppo 2: ==========" << std::endl;
  ppo->print();
  delete h;

  Directory lab02("Lab02");
  *ppo >> lab02;

  std::cout << "========= old: =========" << std::endl;
  ppo->print(); 
  std::cout << "========= new: =========" << std::endl;
  lab02.print(); 

  delete ppo;
}
/* wynik

PPO
__main.cpp
Klasa.h
=========== src: ===========
src
__Klasa.h
__Klasa.cpp
=========== ppo: ===========
PPO
__main.cpp
__src
____Klasa.h
____Klasa.cpp
========== ppo 2: ==========
PPO
__main.cpp
__src
____Klasa.cpp
========= old: =========
PPO
========= new: =========
Lab02
__main.cpp
__src
____Klasa.cpp

 */
