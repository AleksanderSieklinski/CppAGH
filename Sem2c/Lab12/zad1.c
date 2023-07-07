#include <stdio.h>
#include <stdlib.h>
struct tnode {
  int value;
  struct tnode * next;  
}; 
struct tnode *add_end (struct tnode *head,int value) {
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
struct tnode *usun1(struct tnode *elem){
while(elem&&elem->value!=0) {
    struct tnode *next = elem->next;
    free(elem);
    elem = next;
} 
return NULL;
}
struct tnode *merge(struct tnode *l1,struct tnode *l2) {
    struct tnode *temp=l1;
    struct tnode *temp1=l2;
    for(;l1->value==0;l1=l1->next);
    for(;l2->next!=NULL;l2=l2->next);
    l2->next=l1;
    return l2;
}
void  mergeadd(struct tnode **head1,struct tnode **head2,int val) {
    struct tnode *temp = malloc(sizeof(struct tnode));
    if (!temp) {
    return;
    }
    temp ->value = val;
    temp ->next = NULL;
    if (*head1) {
        if(*head2) {
            struct tnode *ele1 = *head1;
            struct tnode *ele2 = *head2;
            for( ;ele1 ->next; ele1=ele1 ->next);
            for( ;ele2 ->next; ele2=ele2 ->next);
            ele1->next=temp;
            ele2->next=temp;
        }
        else {
            *head2=temp;
        }
    }
    else {
        if(*head2==NULL) {
            *head2=temp;
        }
        *head1=temp;
    }
}
int check(struct tnode *l1,struct tnode *l2) {
    for(;l1->next!=NULL;l1=l1->next);
    for(;l2->next!=NULL;l2=l2->next);
    if(l1-l2==0) {
        return 1;
    }
    return -1;
}
int main(void){
    int x;
    struct tnode *l1=NULL;
    struct tnode *l2=NULL;
    scanf("%d",&x);
    while(x<20) {
        if(x==0) {
            //l1 = add_end(l1,x);
            //l2=merge(l1,l2);
            mergeadd(&l1,&l2,0);
            scanf("%d",&x);
            while(x<20) {
                l1=add_end(l1,x);
                scanf("%d",&x);
            }
            break;
        }
        if(x%2==0) {
            l1 = add_end(l1,x);
        }
        else {
            l2 = add_end(l2,x);
        }
        scanf("%d",&x);
    }
    int w=check(l1,l2);
    printf("1/powt -1/nie powt ---> %d\n",w);
    print(l1);
    print(l2);
    l1=usun(l1);
    l2=usun1(l2);
    return 0;	
}
