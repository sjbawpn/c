#include "../include/linkedlist.h"

void linkedlist_print(linkedlist* list) {
    node** root = &(list->head);
    node* current = *root;
    while (current != NULL) {
        printf("current=%i\n",current->value);
        current = current->next;
    }
}

int linkedlist_addtail(linkedlist* list, int data) {
    node** root = &(list->head);
    if (*root == NULL) {
        *root = (node*) malloc(sizeof(node*));
        (*root)->value = data;
        (*root)->next = NULL;

        return 0;
    }
    node *current = *root;
    while (current->next != NULL) {
        current = current ->next;
    }
    node* n = malloc(sizeof(node*));
    n->value = data;
    n->next = NULL;
    current->next = n;
    return 0;
}

int linkedlist_deltail(linkedlist* list) {
    node** root = &(list->head);
    if (*root == NULL) return 0; // list is empty
    node *current = *root;
    if (current->next == NULL) {
        list->head = NULL;
        free(root);
        return 0;
    }
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return 0;

}

int linkedlist_add(linkedlist* list, int data,  int pos) {    
    node** root = &(list->head);
    if (*root == NULL) {
        *root = (node*) malloc(sizeof(node*));
        (*root)->value = data;
        (*root)->next = NULL;

        return 0;
    }
    if ( pos == 0 ) {
        node* new = (node*) malloc(sizeof(node*));
        new->value = data;
        new->next = *root;
        list->head = new;
        return 0;
    }
    node* current = *root;
    int i = 0;
    while (current != NULL) {
        if ( i == pos-1 ) {
            node* new = (node*) malloc(sizeof(node*));
            new->value = data;
            new->next = current->next;
            current->next = new;
            return 0;
            
        }
        current = current->next;
        i++;
    }
    fprintf(stderr,"Error: Index %d  out of bounds %d \n", i, pos);
    return 0;
}

int linkedlist_del(linkedlist* list, int pos) {
    node** root = &(list->head);
    if (*root == NULL) {
        return 0;
    }
    if (pos == 0) {
        list->head = list->head->next;
        free(root);
    }
    node* current = *root;
    int i = 0 ;
    while (current->next != NULL) {
        if ( i == pos - 1) {
            node** n = &(current->next);
            current->next = current->next->next;
            free(n);
            return 0;
        }
        current = current->next;
        i++;
    }

}

int linkedlist_delvalue(linkedlist* list, int data) {
    node** root = &(list->head);
    if (*root == NULL) return 0;

    node* current = *root;
    if (current->value == data) {
        list->head = current->next;
        free(root);
        return 0;
    }
    while(current->next != NULL) {
        if (current->next->value == data) {
            free(&(current->next));
            current->next = current->next->next;
            return 0;
        }
        current = current->next;
    }

}

//Does not work if there are 2 consecutive data values
int linkedlist_delallvalues(linkedlist* list, int data) {
    node** root = &(list->head);
    if (*root == NULL) return 0;

    node* current = *root;
    if (current->value == data) {
        node* n = current->next;
        while (n->next != NULL) {
            if (n->next->value != data) break;
            node* temp = n; // change n to temp
            n = n->next;
            free(temp);
        }
        list->head = n->next;
        return 0;
    }
    while(current->next != NULL) {
        if (current->next->value == data) {
            node* n = current->next;
            while (n->next != NULL) {
                if (n->next->value != data) break;
                node* temp = n; // change n to temp
                n = n->next;
                free(temp);
            }

            current->next = n->next;

            if (current->next == NULL) return 0;
        }
        current = current->next;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    linkedlist list;
    list.head = NULL;
    linkedlist_add(&list, 7, 1);
    linkedlist_add(&list, 4, 1);
    linkedlist_add(&list, 5, 1);
    linkedlist_add(&list, 6, 2);
    linkedlist_add(&list, 7, 2);
    linkedlist_add(&list, 7, 2);
    linkedlist_add(&list, 7, 2);
    linkedlist_addtail(&list, 7);
    linkedlist_addtail(&list, 7);
    linkedlist_addtail(&list, 7);
    linkedlist_addtail(&list, 7);
    linkedlist_addtail(&list, 7);
    linkedlist_print(&list);
    //linkedlist_del(&list, 3);
    linkedlist_delallvalues(&list,7);
    printf("-----\n");
    linkedlist_print(&list);
    //llprint(root);
    /*
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
    */
}
