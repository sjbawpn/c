#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} node;

typedef struct bst {
    node* root;
} bst;

node* add_node(node* n, int data) {
    if (n == NULL) {
        node* r;
        if ((r = (node*) malloc(sizeof(node*))) == 0) {
        };
        printf("adding new data %d\n",r);
        r->value = data;
        r->right = NULL;
        r->left = NULL;
        return r;
    } 
    //if (data == n->value) return n;
    if (data > n->value) {
        printf("adding %d to the right of %d, a=%p\n", data, n->value,n);
        n->right = add_node(n->right, data);
        printf("n->right=%d\n", (n->right)->value);
    }
    else {
        n->left =  add_node(n->left, data);
    }
    return n;
    
}
int bst_add(bst* list, int data) {
    list-> root = add_node(list->root, data);
}
int main() {
    bst tree;
    tree.root = NULL;
    bst_add(&tree, 1);
    printf("%d\n", (tree.root)->value);
    
    bst_add(&tree, 2);
    node* right = (tree.root)->right;
    printf("%d\n", (right)->value);
    
    bst_add(&tree, 3);
    right = right->right;
    //printf("%d\n", (right)->value);

}
