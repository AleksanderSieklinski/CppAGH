/* W zadaniu mamy do czynienia z pewna hierarcha klas 
   opisujaca zestaw klas będących w róznych relacjach. 
   Proszę tak ustalić hierarchię klas, by program dawał
   oczekiwany wynik. 
   W określonych sytuacjach program powinien 
   nie kompilować się (w przeciwnym razie -2 pkt).
         
   Skończone zadanie proszę spakować i wysłać na UPEL, np.
   tar -czvf lab.tar.gz lab
 */

#include <iostream>
#include "Urzadzenia.h"

void wlacz_urzadzenie(Urzadzenie& u) {
	u.wlacz();
}

int main() {

	Skaner* s = new Skaner( Rozdzielczosc(1000, 1600) );   
	Ksero* k = new Ksero( Rozdzielczosc(800, 1000) );
	Drukarka* d = new Drukarka( Rozdzielczosc(600, 800) );
	
	Papierozerne* p = d;
	std::cout << s->rozdzielczosc() << std::endl;
	std::cout << k->rozdzielczosc() << std::endl;
	std::cout << p->rozdzielczosc() << std::endl;

	wlacz_urzadzenie(*p);
	wlacz_urzadzenie(*s);
	wlacz_urzadzenie(*s);

	{
		Kserokopiarka *o = new Kserokopiarka( Rozdzielczosc(600, 1200) );
		//static_cast<Ksero*>(o)->wlacz(); // proszę tak ustalić zależność między klasami, by wykomentowanie tej linii powodowało błąd kompilacji
		delete o;
	}
	p->wylacz();
	s->wylacz();
	k->wylacz();
	
	delete s;
	delete k;
	delete p;
}
/* wynik

Urzadzenie 1000x1600
Skaner 1000x1600
Urzadzenie 800x1000
Papierozerne 800x1000
Ksero 800x1000
Urzadzenie 600x800
Papierozerne 600x800
Drukarka 600x800
1000x1600
800x1000
600x800
wlaczam drukarke
wlaczam skaner
Urzadzenie juz wlaczone
Urzadzenie 600x1200
Papierozerne 600x1200
Drukarka 600x1200
Urzadzenie 600x1200
Papierozerne 600x1200
Ksero 600x1200
Kserokopiarka 
~Kserokopiarka
~Ksero
~Papierozerne
~Urzadzenie
~Drukarka
~Papierozerne
~Urzadzenie
wylaczam drukarke
wylaczam skaner
Urzadzenie juz wylaczone
~Urzadzenie
~Ksero
~Papierozerne
~Urzadzenie
~Papierozerne
~Urzadzenie

 */