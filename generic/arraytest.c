#include <stdio.h>
#include <stdlib.h>

int delete_row(int a[10], int row, int size) {
    int i = row;
    for(i = row+1; i < size; i++) {
        a[i-1] = a[i];
    }
    a[size-1] = 0;
}

int main(int argc, char *argv[]) {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    char* b = (char*) malloc(1);
    int* c = (int*) malloc(10);
    int** d;
    *d = (int*) malloc(10);
    *(d+1) = (int*) malloc(10);
    d = (int**) malloc(10);
    printf("HERE:%u\n",sizeof(a)/sizeof(int));
    *(c) = 1;
    *(c+1) = 2;
    c[2] = 3;

    int j = 0;
    for (j = 0; j < 5; j++){
        printf("%d\n",c[j]);
    }
    *b='a';
    *(b+1)='b';
    *(b+2)='4';
    //b = realloc(b, 3);
    *(b+3)='5';
    *(b+4)='3';
    *(b+5)='4';
    *(b+6)='4';
    *(b+7)='4';
    printf("%s\n", b);
    int i = 0;
    
    delete_row(a, 3,10);
    for (i = 0; i < 10; i++) {
        printf("%d\n",a[i]);
    }

}
