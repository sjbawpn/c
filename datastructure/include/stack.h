#include "common.h"

typedef struct  node {
    int value;
    struct node* next; 
} node;

typedef struct stack {
    int size;
    node* head;
} stack;

void stack_print(stack* s);
int stack_push(stack* s, int data);
int stack_pop(stack* s, int* data);
