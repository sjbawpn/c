#include "../include/queue.h"

void queue_print(queue* q) {
    printf("----- Printing -----\n");
    node** head = &(q->head);
    node** tail = &(q->tail);
    if (*head == NULL) {
         printf("empty\n");
    printf("---------------------\n");
         return;
    }
    printf("head=%d, tail=%d\n",(*head)->value,(*tail)->value);
    node *current = *head;
    while (current != NULL) {
        printf("->%d\n", current->value);
        current = current->next;
    }
    printf("---------------------\n");
}
int queue_enqueue(queue* q, int data) {
#ifdef DEBUG
    printf("enqueing = %d\n",data);
#endif
    node* n = (node*) malloc(sizeof(node*));
    n->value = data;
    n->next = NULL;
    if (q->head == NULL) {
        q->head = n; 
        q->tail = n;
    } else {
        (q->tail)->next = n;
        q->tail = (q->tail)->next;
    }

    return 0;
}

int queue_dequeue(queue* q, int* data) {
    node** head = &(q->head);
    node** tail = &(q->tail);
    if (*head == NULL) return;
    *data = (*head)->value;
    q->head = (*head)->next;
#ifdef DEBUG
    printf("dequeing = %d\n",*data);
#endif
    return 0;
}

int queue_isempty(queue* q) {
    node** head = &(q->head);
    if (*head == NULL) return 1;
    return 0;
}


int main() {
    queue q;
    q.head = NULL;
    q.tail = NULL;
    queue_enqueue(&q,1);
    queue_enqueue(&q,2);
    queue_enqueue(&q,3);
    queue_enqueue(&q,5);
    queue_print(&q);
    int d;
    while (!queue_isempty(&q)) {
        queue_dequeue(&q,&d);
    }
    queue_print(&q);
    return 0;
}


