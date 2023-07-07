#include <stdio.h>
#include <stdlib.h>
struct tnode {
  char value;
  struct tnode * next;
}; 
struct tnode *insert_item_sort(struct tnode *head,struct tnode *ele){
    if(head) {
        if(head->value>ele->value) {
            ele->next=head;
            head=ele;
        }
        else {
        struct tnode *tp=head;
        for(;tp->next&&tp->next->value<ele->value;tp=tp->next);
        ele->next=tp->next;
        tp->next=ele;
        }
    }
    else {
    head=ele;
    }
    return head;
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
int main(void){
    struct tnode *head=NULL;
    struct tnode *elem=malloc(sizeof(struct tnode));
    struct tnode *elem1=malloc(sizeof(struct tnode));;
    struct tnode *elem2=malloc(sizeof(struct tnode));;
    elem->value=66;
    elem1->value=55;
    elem2->value=88;
    head = insert_item_sort(head,elem);
    print(head);
    head = insert_item_sort(head,elem1);
    print(head);
    head = insert_item_sort(head,elem2);
    print(head);
    usun(head);
    return 0;	
}
