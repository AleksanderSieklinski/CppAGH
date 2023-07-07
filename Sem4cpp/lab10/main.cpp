/*
 Celem zadania jest napisanie szablonowej listy połączonej.
 Jej węzłami są obiekty, które mogą przechowywać różne typy.

 Lista połączona to łańcuch kolejnych węzłów, z których
 każdy posiada wskaźnik na kolejny węzeł.

 head
 _|__        ____           	   ____
|__|*| ---> |__|*| ---> ... ---> |__|*| ---> nullptr 

 Proszę stworzyć odpowiedni szablon klasy - węzeł.
 
 Następnie proszę stworzyć szablon klasy PLinkedList, która 
 przechowuje wskaźnik na początek listy. 
 Pamiętamy, że dla pustej listy jest to nullptr.
 Jej konstruktory i operatory= są "głośne".
 Listę tę można kopiować i przenosić (patrz funkcja main).

 Uwaga: 
 - tematem jest napisanie listy połączonej. Obejście
 problemu przez użycie vectora i innych kontenerów jest 
 zadaniem nie na temat.
 - adresy wskaźników będą inne niż w podanym wyniku. Ważne,
 by powtarzały się tam gdzie trzeba.

 Tips:
 - konstruktor przenoszący jest bardzo krótki.
 - pamiętamy o destruktorze PLinkedList
 - kod metod może się znajdować w ciele klasy (można sobie w 
 domu przepisać rozwiazanie tak żeby byly poza klasa)

 */

#include "PLinkedList.h"
#include "Node.h"
#include <iostream>
#include <vector>

template<typename T>
PLinkedList<T> copyList(PLinkedList<T> l){ // tu się uruchamia konkstruktor kopiujący
  std::cout << "=== in copyList: " << l.head() << std::endl;
  return l; 
}

int main() {
  Node<int> * n1 = new Node<int>(12);
  n1->print();
  std::cout << std::endl;
  Node<std::string> *n2 = new Node<std::string>("kitku");
  n2->print();
  Node<std::string> n3("Tom");

  std::cout << "\n========= Linked List =========" << std::endl;

  PLinkedList<std::string> list;
  list.addFront(n2).addFront(n2).addFront(&n3);
  std::cout << "list: " << list << std::endl; 
  delete n2;  // lista nadal działa

  std::cout << "=========== moving ===========" << std::endl;

  PLinkedList<std::string> list2 = copyList(list);
  std::cout << "=== after moving " << list2.head() << ", " << list.head() << std::endl;
  list.addFront(&n3);
  std::cout << "list: " << list << std::endl;
  std::cout << "list2: " << list2 << std::endl;
  delete n1;

}
/* wynik

12
kitku
========= Linked List =========
list: Tom -> kitku -> kitku
=========== moving ===========
--- copying list: Tom -> kitku -> kitku
=== in copyList: 0x55bffb70f2e0
--- moving list: Tom -> kitku -> kitku
=== after moving 0x55bffb70f2e0, 0x55bffb70f370
list: Tom -> Tom -> kitku -> kitku
list2: Tom -> kitku -> kitku

*/

// W domu można jeszcze napisać operator przypisania kopiującego i przenoszącego.
// Przykład użycia:
// list2 = list = list;
// std::cout << "list2: " << list2 << std::endl; 
