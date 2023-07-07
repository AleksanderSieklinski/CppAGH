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
    add_front(&head,'a');
    add_front(&head,'c');
    add_front(&head,'v');
    add_front(&head,'f');
    add_front(&head,'t');
    print(head);
    head = usun(head);
    return 0;	
}
