#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;

void ll_add(node* root, int value) {
    node* current = root;
    node* n = malloc(sizeof(n));
    n->value = value;
    n->next = NULL;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = n;
    //return root;
}
int main(int argc, char *argv[]) {
    node* root;
    root = malloc(sizeof(node));
    root->value=2;
    ll_add(root, 4);
    ll_add(root, 44);
    ll_add(root, 3);
    ll_add(root, 33);
    ll_add(root, 5);
    ll_add(root, 55);
    ll_add(root, 666);
    node* current = root;
    while (current != NULL) {
        printf("current=%i\n",current->value);
        current = current->next;
    }
}
