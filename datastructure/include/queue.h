#include <common.h>

typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct queue {
    node* head;
    node* tail;
} queue;

void queue_print(queue*);
int queue_enqueue(queue*, int);
int queue_dequeue(queue*, int*);
