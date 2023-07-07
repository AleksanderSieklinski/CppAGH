/*
 Celem zadania jest napisanie kilku klas związanych relacją
 dziedziczenia. Klasy te opisują pliki.
 
 Rozbudowujemy program o możliwość kopiowania pliku lub katalogu
 z cala zawartoscia. Powinna to być głęboka kopia, aby uniknac 
 problemow z pamiecia. W tym celu przydatna będzie wirtualna
 funkcja clone() z wykorzystaniem tzw. kowariancji typu zwracanego,
 do skopiowania obiektów różnych typów.

 Kolejnym dodatkiem jest funkcja rename.
 Dodatkowo, tworzymy nowy rodzaj pliku, czyli Symlink - link symboliczny.
 */

#include <iostream>
#include "File.h"
#include "Directory.h"
#include "Symlink.h"

int main() {
  Directory *ppo = new Directory("PPO");
  *ppo += new File("main.cpp");
  ppo->print();
  
  Directory *src = new Directory("src");
  File* cppFile = new File("Klasa.cpp");
  cppFile->print(); 
  *src += cppFile;

  std::cout << "=========== src: ===========" << std::endl;
  File *srcPtr = src;
  srcPtr->print();

  std::cout << "=========== ppo: ===========" << std::endl;
  *ppo += src;
  ppo->print();

  Directory *lab02 = new Directory("Lab02");
// przekopiowanie do lab02 całego katalogu src z podkatalogami
  lab02->copy(ppo);
  src->rename("SOURCE");

  std::cout << "========= copied: =========" << std::endl;
  lab02->print(); 
  std::cout << "======== original: ========" << std::endl;
  ppo->print(); 
  
  lab02->copy(cppFile); 
  Symlink * sl = new Symlink("link", cppFile);
  cppFile->rename("Class.cpp");
  *lab02 += sl;
  std::cout << "======== original: ========" << std::endl;
  ppo->print(); 
  std::cout << "======= more copies: =======" << std::endl;
  lab02-> print(); 
  std::cout << "========  symlink : ========" << std::endl;
  (*sl) -> print();

  delete ppo;
  delete lab02;
}
/* wynik

PPO
__main.cpp
Klasa.cpp
=========== src: ===========
src
__Klasa.cpp
=========== ppo: ===========
PPO
__main.cpp
__src
____Klasa.cpp
========= copied: =========
Lab02
__PPO
____main.cpp
____src
______Klasa.cpp
======== original: ========
PPO
__main.cpp
__SOURCE
____Klasa.cpp
======== original: ========
PPO
__main.cpp
__SOURCE
____Class.cpp
======= more copies: =======
Lab02
__PPO
____main.cpp
____src
______Klasa.cpp
__Klasa.cpp
__link -> Class.cpp
========  symlink : ========
Class.cpp

 */