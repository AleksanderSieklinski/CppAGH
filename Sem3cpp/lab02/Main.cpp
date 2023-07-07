// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku
//
// Pliku Main.cpp, nie wolno modyfikowac.
//
// Ostateczny program powinien byc przyjazny dla programisty
// (miec czytelny i dobrze napisany kod)
//
// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani żadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile, chyba że polecenie stanowi inaczej)
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli dodane pliki i Main.cpp należy wgrać do UPEL 
// jako archiwum tar.gz
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab02/
// * archiwum nie powinno zawierać katalogu build/
// * tworzenie archiwum: tar -czvf nazwa.tar.gz zad/

#include "StudentList.h"

int main()
{
    TStudent* head = NULL; //Lista jest pusta na start
    show(head);
    TStudent* next = InitTStudent();
    next->data=1;
    next->next= head;
    head=next;
    show(head);
    push_front(&head, 2);
    push_front(&head, 3);
    push_front(&head, 4);
    show(head);
    clear(&head);
    show(head);
    return 0;
}
/** Wynik dzialania programu:
Aktualny stan listy:
Lista jest pusta
Aktualny stan listy:
1

Aktualny stan listy:
4
3
2
1

Aktualny stan listy:
Lista jest pusta
*/