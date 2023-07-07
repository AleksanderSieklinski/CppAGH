#include <stdio.h>
#include <stdlib.h>
struct tnode {
  char value;
  struct tnode * next;
}; 
void print(struct tnode *elem);
struct tnode *add_end (struct tnode *head,char value) {
    struct tnode *temp = malloc(sizeof(struct tnode));
    temp ->value = value;
    temp ->next = NULL;
    if (head!=NULL) {
        struct tnode *elem = head;
        for( ;elem->next!=NULL; elem=elem->next) ;
        elem->next=temp;
        return head;
    }
    else {
        return temp;
    }
    
}
void print(struct tnode *elem) {
    printf("Head ->");
    for(;elem;elem=elem->next) {
        printf("['%c'] -> ",elem->value);
    }
    printf("NULL\n");
}
struct tnode *usun(struct tnode *elem){
while(elem) {
    struct tnode *next = elem->next;
    free(elem);
    elem = next;
} 
return NULL;
}
int main(void){
    struct tnode *head=NULL;
    head = add_end(head,'a');
    head = add_end(head,'c');
    head = add_end(head,'v');
    head = add_end(head,'f');
    head = add_end(head,'t');
    print(head);
    head = usun(head);
    return 0;	
}
