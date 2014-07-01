#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct linkedlist {
    node* head;
    int size;
} linkedlist;

void linkedlist_print(linkedlist*);
int linkedlist_addtail(linkedlist*, int);
int linkedlist_deltail(linkedlist*);
int linkedlist_add(linkedlist*, int,  int);    
int linkedlist_del(linkedlist*, int);
int linkedlist_delvalue(linkedlist*, int);
