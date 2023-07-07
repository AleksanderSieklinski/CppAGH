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
        printf("['%d'] -> ",elem->value);
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
struct tnode *sortlist(struct tnode *head) {
    if(head!=NULL) {
        struct tnode *temp=head;
        for(;head->next!=NULL;head=head->next) {
            if(head->next->value%2==0) {
                struct tnode *t1=head->next;
                head->next=head->next->next;
                t1->next=temp;
                temp=t1;
            }
        }
        head=temp;
    }
    return head;
}
int main(void){
    struct tnode *head = NULL;
    add_front(&head,11);
    add_front(&head,8);
    add_front(&head,13);
    add_front(&head,24);
    add_front(&head,31);
    add_front(&head,5);
    add_front(&head,6);
    add_front(&head,7);
    print(head);
    head=sortlist(head);
    print(head);
    return 0;	
}
