/*
 Celem zadania jest przećwiczenie szablonowych parametrów szablonów oraz SFINAE.
 Jednym z zastosowań szablonowych parametrów szablonów jest "policy-based design",
 w którym tworzymy klasy tzw. policies odpowiadające za konkretne zachowanie i
 które będą podawane jako parametry szablonu. 
 To podejście pozwala na wybór konkretnego rozwiązania na etapie kompilacji. 
 
 Poniżej są zaimplentowane 2 klasy-policies, realizujące 2 rodzaje sortowania.
 Proszę napisać klasę szablonową Sorter, która przyjmuje jako parametry szablonu 
 typ danych oraz politykę/taktykę sortowania. Posiada ona funkcję sort, która 
 sortuje klasę szablonową NumArray w zależności od podanej polityki.

 Proszę zasotoswać SFINAE do zapewnienia, by klasa szablonowa NumArray mogła 
 przyjmować tylko typy arytmetyczne. Wskazówka: można zastosować odpowiedni
 parametr domyślny szablonu klasy stosując std::enable_if.
 Jeśli ktoś nie pamięta dokładnej składni, można skorzystać z dokumentacji:
 https://en.cppreference.com/w/cpp/types/enable_if
 oraz:
 https://en.cppreference.com/w/cpp/header/type_traits
 
 UWAGA:
 - żeby spełnić powyzsze wymagania, po odkomentowaniu linii 72-74 z flagami ERROR1, 
   ERROR2, ERROR3 program nie może się kompilować (z każdą z tych flag z osobna -- 
   jeśli się  skompiluje, odejmowane są 4 punkty) 
 - jesli ktoś zna inne rozwiązania, by NumArray działała wyłącznie dla typów
   arytmetycznych, to można je zastosować (np. częściowa specjalizacja)
 - obejście problemu tak, że nie zachodzi kompilacja, ale NumArray działa dla typów 
   niearytmetycznych, jest zadaniem nie na temat.
 
 */
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "Sorter.h"
#include "NumArray.h"

// Sorting policy using IntroSort algorithm
template <typename T>
struct IntroSorter {
    static void sort(std::vector<T>& data) {
        std::sort(data.begin(), data.end());
        std::cout << "[IntroSorter] Sorting using IntroSort algorithm." << std::endl;
    }
};

// Sorting policy using BubbleSort algorithm
template <typename T>
struct BubbleSorter {
    static void sort(std::vector<T>& data) {
        bool sorted = false;
        while (!sorted) {
            sorted = true;
            for (size_t i = 0; i < data.size() - 1; ++i) {
                if (data[i] > data[i + 1]) {
                    std::swap(data[i], data[i + 1]);
                    sorted = false;
                }
            }
        }
        std::cout << "[BubbleSorter] Sorting using BubbleSort algorithm." << std::endl;
    }
};

struct IntWrapper{
	int _val;
	IntWrapper(int a):_val(a){}
};

// #define ERROR1
// #define ERROR2
// #define ERROR3

int main(){
    NumArray<int> ints{5, 2, 8, 1, 4};
    const NumArray<int> ints_copy = ints; // copy to compare later

    Sorter<int, IntroSorter> introSorter;
    introSorter.sort(ints);  // Sort using IntroSort algorithm

    ints.print();
    ints_copy.print();
   
    NumArray<double> doubles{0.5, 1.2, -1.5, 2.4, 10.2, -4.0};
    doubles.print();
    doubles.set(-2.0, 1).set(3.5, 2);
    doubles.print();
   
    Sorter<double, BubbleSorter> bubbleSorter;
    bubbleSorter.sort(doubles);  // Sort using BubbleSort algorithm
    doubles.print();
    
    #ifdef ERROR1
    NumArray<std::string> strings{"string"};
    #endif 
    #ifdef ERROR2
    int a = 1;
    NumArray<int*> ints2{&a};
    #endif 
    #ifdef ERROR3 
    NumArray<IntWrapper> ints3{IntWrapper(1)};
    #endif 
    
    return 0;
}
/*
[IntroSorter] Sorting using IntroSort algorithm.
1	2	4	5	8	
5	2	8	1	4	
0.5	1.2	-1.5	2.4	10.2	-4	
0.5	-2	3.5	2.4	10.2	-4	
[BubbleSorter] Sorting using BubbleSort algorithm.
-4	-2	0.5	2.4	3.5	10.2	
*/