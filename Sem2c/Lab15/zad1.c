#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct tnode {
    int val;
    struct tnode *next;
    struct tnode *prev;
};
void print_list_next(struct tnode* elem) {
    printf("NULL <-");
    struct tnode *temp = elem;
    while(temp->prev!=NULL) {
        temp=temp->prev;
    }
    for(;temp;temp=temp->next) {
        printf(" [%d] <->",temp->val);
    }
    printf("NULL\n");
}
void print_list_prev(struct tnode* elem) {
    printf("NULL <-");
    struct tnode *temp = elem;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    for(;temp;temp=temp->prev) {
        printf(" [%d] <->",temp->val);
    }
    printf("NULL\n");
}
void add_next(struct tnode **head,int value) {
    if((*head)==NULL) {
        (*head)=(struct tnode*)malloc(sizeof(struct tnode));
        (*head)->val=value;
        (*head)->next=NULL;
        (*head)->prev=NULL;
    }
    else {
        struct tnode *temp=malloc(sizeof(struct tnode));
        if(temp==NULL) {
            printf("Mem error\n");
            return;
        }
        temp->val = value;
        temp->next = *head;
        temp->prev=NULL;
        (*head)->prev=temp;
        (*head)=temp;
    }
}
void free_list(struct tnode **head) {
    struct tnode *temp;
    while(*head!=NULL) {
        temp=(*head);
        *head=(*head)->next;
        free(temp);
    }
}
void free_list1(struct tnode **head) {
    while(*head!=NULL) {
        free((*head)->prev);
        *head=(*head)->next;
    }
    free(*head);
}
void add_next_sort(struct tnode **head,struct tnode* ele) {
    if((*head)==NULL) {
        *head=ele;
    }
    else {
        struct tnode *l=*head;
        while(l->val <=ele->val && l->next!=NULL) {
            l=l->next;
        }
        if(l->next!=NULL) {
            ele->next=l->next;
            l->next->prev=ele;
        }
        l->next=ele;
        ele->prev=l;
    }
}
struct tnode *usun(struct tnode **elem,int x) {
    int z=1;
    struct tnode *head1=(struct tnode*)malloc(sizeof(struct tnode));
    for(;(*elem)->next!=NULL;(*elem)=(*elem)->next) {
        if((*elem)->val == x) {
            if((*elem)->prev !=NULL) {
                (*elem)->prev->next=(*elem)->next;
            }
            (*elem)->next->prev=(*elem)->prev;
            if(z==1) {
                head1->val=x;
                head1->next=NULL;
                head1->prev=NULL;
                z--;
            }
            else {
                add_next(&head1,x);
            }
        }
    }
    if((*elem)->val == x) {
        (*elem)->prev->next=NULL;
        (*elem)=(*elem)->prev;
        add_next(&head1,x);
    }
    return head1;
}
struct tnode *usun1(struct tnode **elem,int x) {
    for(;(*elem)->next!=NULL;(*elem)=(*elem)->next) {
        if((*elem)->val == x) {
            if((*elem)->prev !=NULL) {
                (*elem)->prev->next=(*elem)->next;
            }
            (*elem)->next->prev=(*elem)->prev;
            struct tnode *head1=(struct tnode*)malloc(sizeof(struct tnode));
            head1->val=x;
            head1->next=NULL;
            head1->prev=NULL;
            return head1;
        }
    }
    if((*elem)->val == x) {
        (*elem)->prev->next=NULL;
        (*elem)=(*elem)->prev;
        struct tnode *head1=(struct tnode*)malloc(sizeof(struct tnode));
        head1->val=x;
        head1->next=NULL;
        head1->prev=NULL;
        return head1;
    }
}
struct tnode *div_list(struct tnode**head) {
    struct tnode *head2 = NULL;
    struct tnode *temp = *head;
    while(temp->next!=NULL) {
        if(temp->val%2==0) {
            temp=temp->next;
        }
        else {
            if(head2==NULL) {
                head2=temp;
            }
            else {
                add_next_sort(&head2,temp);
                temp->next->prev=temp->prev;
                temp->prev->next=temp->next;
            }
        }
    }
    return head2;
    
}
int main(void){
    struct tnode *head = NULL;
    add_next(&head,11);
    add_next(&head,15);
    add_next(&head,15);
    add_next(&head,15);
    add_next(&head,16);
    add_next(&head,18);
    printf("Dodawanie\n");
    print_list_next(head);
    print_list_prev(head);
    struct tnode *ele = (struct tnode*)malloc(sizeof(struct tnode));
    ele->val=14;
    ele->next=NULL;
    ele->prev=NULL;
    printf("Sortowane dodawanie\n");
    add_next_sort(&head,ele);
    print_list_next(head);
    printf("Usuwanie wszystkich takich samych\n");
    struct tnode *p=usun(&head,15);
    struct tnode *g=usun1(&head,16);
    print_list_next(head);
    print_list_next(p);
    struct tnode *niep=div_list(&head);
    printf("Podzial parzyste nieparzyste\n");
    print_list_next(head);
    print_list_next(niep);
    //print_list_next(g);
    free_list(&head);
    free_list(&p);
    //free_list(&g);
    return 0;	
}
