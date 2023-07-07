#include "StudentList.h"
using namespace std;
TStudent *InitTStudent() {
    TStudent* stud=(TStudent*)malloc(sizeof(TStudent));
    stud->next=NULL;
    return stud;
}
void show(TStudent*head) {
    TStudent *temp=head;
    cout<<"Aktualny stan listy:"<<endl;
    if(!head) {
        cout<<"Lista jest pusta"<<endl;
    }
    else {
    for(;temp;temp=temp->next) {
        cout<<temp->data<<endl;
    }
    cout<<endl;
    }
}
void push_front(TStudent **head,int value) {
    TStudent *temp=InitTStudent();
    temp->next=*head;
    temp->data=value;
    (*head)=temp;
}
void clear(TStudent **head) {
    TStudent*temp=*head;
    while((*head)!=NULL) {
        temp=*head;
        (*head)=(*head)->next;
        free(temp);
    }
}