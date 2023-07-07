#include <iostream>
#include <cstdio>
//definition of a linked list
typedef struct node {
    struct node *next;
    int data;
}TStudent;
//initializing a new linked list
TStudent *InitTStudent();
//showing list from head to tail
void show(TStudent*head);
//adding element at the beginning of the linked list
void push_front(TStudent **head,int value);
//freeing memory of a linked list
void clear(TStudent **head);