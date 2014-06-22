#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;
node* ll_create(int val) {
    node* root = malloc(sizeof(node));
    root->value = val;
    root->next = NULL;
    return root;
}
node* ll_add(node* root, int value, int pos) {
    node* current = root;
    node* n = malloc(sizeof(n));
    n->value = value;
    n->next = NULL;
    node* p = NULL;
    int i = 0;
    for(i = 0; i < pos && current !=  NULL; i++) { 
        p = current;
        current = current->next;
    }
    //if (i != pos) {
    //    printf("Error: Index out of bounds\n");
    //    return root;
    //}
    if (p != NULL) {
        p->next = n;
    } else {
        root = n;
    }
     n->next = current;
    return root ;
}
void ll_add_last(node* root, int value) {
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

node* ll_del_val(node* root, int value) {
    node* current = root;
    if( current->value == value ) {
        node* n = root-> next;
        free(root);
        root=NULL;
        return n;
    }
    while (current->next != NULL) {
        if ((current->next)->value == value) {
            node* n = current->next;
            current->next = (current->next)->next;
            free(n);
            n = NULL;
            break;
        }
        current = current -> next;

    }
    return root;
}
node* ll_del(node* root, int pos) {
    node* current = root;
    node* n = malloc(sizeof(n));
    n->next = NULL;
    node* p = NULL;
    int i = 0;
    for(i = 0; i < pos && current !=  NULL; i++) { 
        p = current;
        current = current->next;
    }
    //if (i != pos) {
    //    printf("Error: Index out of bounds\n");
    //    return root;
    //}
    if (p != NULL) {
        node* n = p->next;
        if (n == NULL)
            p->next = NULL;
        else {
            p->next = n->next;
            free(n);
            n == NULL;
        }
    } else {
        printf("I'm here!\n");
        node* n = root;
        root = root->next;
        printf("%i\n", root->value);
        n = NULL;
        free(n);
    }
    return root ;
}
void ll_print(node* root) {
    node* current = root;
    while (current != NULL) {
        printf("current=%i\n",current->value);
        current = current->next;
    }
}
int main(int argc, char *argv[]) {
    node* root = ll_create(2);
    ll_add_last(root, 3);
    ll_add_last(root, 5);
    ll_add_last(root, 4);
    ll_add_last(root, 6);
    ll_print(root);
    printf("\n");
    root = ll_del_val(root, 5);
    root = ll_del_val(root, 2);
    root = ll_del_val(root, 3);
    root = ll_del_val(root, 6);

    ll_add_last(root, 5);
    ll_add_last(root, 6);
    ll_add_last(root, 7);
    ll_print(root);
    root = ll_add(root, 100, 0);
    printf("\n");
    ll_print(root);
    
    root = ll_del(root,5);
    printf("\n");
    ll_print(root);
}
