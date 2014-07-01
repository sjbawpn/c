#include "../include/stack.h"

void stack_print(stack* s)
{
    printf("------------printing------\n");
    if (s->head == NULL)
    {
        printf("empty\n");
        return;
    }
    node* current = s->head;
    while (current != NULL) {
        printf("data = %d\n", current->value);
        current = current->next;
    }
    printf("--------------------------\n");
}

int stack_push(stack* s, int data)
{
    node* n = (node*) malloc(sizeof(node*));
#ifdef DEBUG
    printf("pushing %d\n", data);
#endif
    n->value = data;
    n->next = s->head;
    s->head = n;
    return 0;

}

int stack_pop(stack* s, int* data)
{
    if ((s->head) == NULL) return -1;

    
    *data = (s->head)->value;
#ifdef DEBUG
    printf("popping %d\n", *data);
#endif
    s->head = (s->head)->next;
    return 0;
}

int main(int argc, char* argv[])
{
    stack s;
    s.head = NULL;
    stack_push(&s,1);
    stack_push(&s,2);
    stack_push(&s,3);
    stack_print(&s);
    int data;
    while (!stack_pop(&s, &data));

    return 0;
}
