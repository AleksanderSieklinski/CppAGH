/*
  Rozbudowanie klasy MyArray, w której można przechowywać 
  obiekty dowolnych typów.

  Do poprzedniej wersji dodajemy funkcje:
  - transfer, która przenosi zawartość jednej tablicy 
  do drugiej (i opróżnia pierwszą),
  - remove_if, która usuwa podaną wartość z tablicy,
  - insert, która wstawia coś na wskazanej pozycji.
  
  Proszę umieścić definicje metod poza ciałem klasy.
  Uwaga: w programie nie może być żadnych wycieków pamięci.  
  
  Można korzystać z dokumentacji, np. https://en.cppreference.com/w/cpp/container/vector
  https://en.cppreference.com/w/cpp/algorithm ,
  https://en.cppreference.com/w/cpp/memory/unique_ptr
 */

#include <iostream>
#include <string>
#include "MyArray.h"
#include "Printer.h"

MyArray::~MyArray() = default;

struct Book{
  Book(const char* title): _title(title){}
  std::string _title;
  friend std::ostream& operator<<(std::ostream &o, const Book& b){ return o << b._title; }
};

struct Point{
  Point(int x, int y): _x(x), _y(y){}
  int _x;
  int _y;
  friend std::ostream& operator<<(std::ostream &o, const Point& p){ return o << "(" << p._x << ", " << p._y << ")"; }
};

int main() {   
  MyArray a;
  a.add(7);
  a.add<std::string>("string");  
  a.add(17);
  a.add<double>(4.04);  
  ", " << a;
   
  MyArray b;
  b.add(Book("The Feynman Lectures on Physics"));
  b.add(Point(2, 1)); 
  b.add(17);
  ", " << b;

  b.remove<Point>();
  std::cout << "===== transfer =====" << std::endl;
  // przeniesienie obiektów z tablicy b do a
  a.transfer(b);
  std::cout << "a: ";
  ", " << a;
  std::cout << "b: ";
  ", " << b;
  b.add(1.7);
  ", " << b;
    
  std::cout << "===== remove if 17 =====" << std::endl;
  a.remove_if(17);
  ", " << a;
 
  std::cout << "===== insert Point =====" << std::endl;
 // wstawienie na wybranej pozycji w tablicy
 a.insert(Point(5,4), 2);
  ", " << a;
 return 0; 
}

/* wynik

7, string, 17, 4.04
The Feynman Lectures on Physics, (2, 1), 17
===== transfer =====
a: 7, string, 17, 4.04, The Feynman Lectures on Physics, 17
b: 1.7
===== remove if 17 =====
7, string, 4.04, The Feynman Lectures on Physics
===== insert Point =====
7, string, (5, 4), 4.04, The Feynman Lectures on Physics

 */
