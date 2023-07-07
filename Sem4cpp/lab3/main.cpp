 // Celem zadania jest zapoznanie się z regułą rule of five. 
 // Stworzymy klasę SmartPtr, będącą przykładem sprytnego wskaźnika.
 // Jest to klasa opakowująca wskaźnik, w której liczona jest liczba
 // referencji do niego. 
 
 // - Podczas konstruowania sprytnego wskaźnika przekazujemy do niego
 //   wskaźnik do obiektu stworzonego operatorem new i startujemy licznik.
 // - Każdy kolejny sprytny wskaźnik pokazujący na ten obiekt (stworzony 
 //   z innego sprytnego wskaźnika) zwiększa licznik.
 // - Każde zniszczenie sprytnego wskaźnika (np. przy wyjściu poza zakres, nadpisanie)
 //   zmniejsza licznik. 
 // - Przy przenoszeniu SmartPtr, ustawiamy przenoszony wskaźnik na nullptr. 
 // - Gdy licznik dochodzi do zera, pamięć jest zwalniana. 
 
 // Kluczową sprawą jest zapewnienie współdzielenia licznika pomiędzy różnymi
 // instancjami klasy sprytnego licznika (static nie jest rozwiązaniem - dlaczego?)
 
 // Sprytny wskaźnik ma obslugiwać prostą klasę TestClass, 
 // która ma tylko konstruktor i destruktor i metodę info() wypisujące informacje.
 
 // Skończone zadanie proszę spakować i wysłać na UPEL, np.
 // tar -czvf lab03.tar.gz lab03

#include "SmartPtr.h"
#include "TestClass.h"
#include <iostream>

void printInfo(const TestClass& info){
	std::cout << "   printInfo: " << info.info() << std::endl;
}

void printPtr(const SmartPtr& sp){
	if(sp) std::cout << "--> Juz " << sp.useCount() << " wskazniki pokazuja na " << sp->info() << std::endl;
}

int main(){
	{
		TestClass test("test_A");
		printInfo(test);
	}
	std::cout << std::endl;
	
	SmartPtr smart1( new TestClass("test_B") );
	SmartPtr smart2( new TestClass("test_C") );
	
	SmartPtr smart3 = smart1;
	smart2 = smart2;
	smart2 = smart1;          // <---- Kasujemy test_C, bo żaden inny wskaźnik na niego nie wskazuje
	printPtr(smart1);
		
	SmartPtr smart5( new TestClass("test_D") );
	smart3 = smart5;
	{
		const SmartPtr smart4 = smart2;
		printInfo(*smart4);
	}
	std::cout << "== " << smart2->info() << std::endl;
	/*
	std::cout << std::endl << "===== przenoszenie =====" << std::endl;	
	std::cout << "== smart6: ==" << std::endl;
	printPtr(smart3);
	SmartPtr smart6 = std::move(smart3);	// <-- przeniesienie smart3; ustawiamy nullptr
	printPtr(smart3);

	std::cout << "== smart7: ==" << std::endl;
	SmartPtr smart7( new TestClass("test_E") );
	smart7 = std::move(smart5);	// <-- przeniesienie smart5; ustawiamy nullptr; kasujemy test_E
	printPtr(smart5);
	printPtr(smart7);
	*/
	// Do zastanowienia się w domu:
	// jakiekolwiek porównania >, >=, <=, <, !=, == nie powinny być możliwe (jak to zapewnić najkrócej jak to możliwe?)
	// if(smart1 >= smart4 ) std::cout<< "=== Nie powinno sie skompilowac === " << "\n";
}

/* wynik działania programu:

++ Tworze obiekt TestClass: test_A
   printInfo: test_A
-- Usuwam obiekt TestClass: test_A

++ Tworze obiekt TestClass: test_B
++ Tworze obiekt TestClass: test_C
-- Usuwam obiekt TestClass: test_C
--> Juz 3 wskazniki pokazuja na test_B
++ Tworze obiekt TestClass: test_D
   printInfo: test_B
== test_B

===== przenoszenie =====
== smart6: ==
--> Juz 2 wskazniki pokazuja na test_D
== smart7: ==
++ Tworze obiekt TestClass: test_E
-- Usuwam obiekt TestClass: test_E
--> Juz 2 wskazniki pokazuja na test_D
-- Usuwam obiekt TestClass: test_D
-- Usuwam obiekt TestClass: test_B

*/
