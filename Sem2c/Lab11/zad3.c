#include <stdio.h>
#include <stdlib.h>
struct tnode {
  char value;
  struct tnode * next;
}; 

void add_front (struct tnode **head,char value) {
    struct tnode *temp = malloc(sizeof(struct tnode));
    temp  -> value = value;
    temp  -> next = *head;
    *head=temp;
}
void print(struct tnode *elem) {
    printf("Head ->");
    for(;elem;elem=elem->next) {
        printf("['%c'] -> ",elem->value);
    }
    printf("NULL\n");
}
struct tnode *zwolnij(struct tnode *elem){
while(elem) {
    struct tnode *next = elem->next;
    free(elem);
    elem = next;
} 
return NULL;
}
void merge(struct tnode **head,struct tnode *add) {
    struct tnode *temp = *head;
    temp  -> next = add;
    *head=temp;
}
struct tnode *usun (struct tnode **head,char *x) {
    struct tnode *temp = *head , *prev = NULL;
    for(;temp->next!=NULL;temp=temp->next) {
        if(temp->value==*x || temp->value==*x-32 || temp->value==*x+32) {
            if(prev==NULL) {
                (*head)=temp->next;
            }
            else {
                prev->next=temp->next;
            }
        }
        prev=temp;
    }
    if(temp->value==*x || temp->value==*x-32 || temp->value==*x+32) {
            if(prev==NULL) {
                (*head)=temp->next;
            }
            else {
                prev->next=temp->next;
            }
        }
    return *head;
}
struct tnode *usunwklej (struct tnode **head,char *x) {
    struct tnode *temp = *head , *prev = NULL;
    struct tnode *new = NULL;
    for(;temp->next!=NULL;temp=temp->next) {
        if(temp->value==*x || temp->value==*x-32 || temp->value==*x+32) {
            if(prev==NULL) {
                (*head)=temp->next;
            }
            else {
                prev->next=temp->next;
            }
            merge(&new,temp);
        }
        prev=temp;
    }
    if(temp->value==*x || temp->value==*x-32 || temp->value==*x+32) {
            if(prev==NULL) {
                (*head)=temp->next;
            }
            else {
                prev->next=temp->next;
            }
            merge(&new,temp);
        }
    return  new;
}
int main(void){
    struct tnode *head=NULL;
    struct tnode *new = NULL;
    add_front(&head,'A');
    add_front(&head,'l');
    add_front(&head,'a');
    add_front(&head,' ');
    add_front(&head,'m');
    add_front(&head,'a');
    add_front(&head,' ');
    add_front(&head,'k');
    add_front(&head,'o');
    add_front(&head,'t');
    add_front(&head,'a');
    print(head);
    //head=usun(&head,"a");
    new = usunwklej(&head,"A");
    print(head);
    //print(new);
    head = zwolnij(head);
    new= zwolnij(new);
    return 0;	
}
