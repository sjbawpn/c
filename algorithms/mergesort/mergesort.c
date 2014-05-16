#include <stdio.h>
#include <strings.h>
#include "mergesort.h"

void merge(int* a, int start, int mid, int end, int * b) {
    int i = start;
    int j = mid;
    int len = end - start;
    int idx = 0;
    
    for (idx = start; idx < end; idx++) {
        if ((i < mid) && ( (j >= end) || (a[i] < a[j]) )) {
            b[idx] = a[i];
            i++;
        } else {
            b[idx] = a[j];
            j++;
        }
    }
    
}

void copy(int* b, int start, int end, int* a) {
    int i;
    for (i = start; i < end; i++) {
        a[i] = b[i];
    }
}
void sort(int* a, int start, int end, int* b) {
    unsigned long int size = sizeof(*a)/sizeof(int);
    if (end - start < 2) return;
    int m = (start + end) / 2;
    sort(a, start, m, b);
    sort(a, m, end, b);
    merge(a, start, m, end, b);
    copy(b, start, end, a);
}

void merge_sort(int* a, int size) {
    int b[size];
    unsigned long int l = sizeof(a);
    printf("%lu\n",l);
    int i;
    for (i = 0; i < size; i++)
        b[i] = 0;
    sort(a, 0, size, b);
}
int main(int argc, char* argv[]) {

    int a[] = {10, 22, 3, 54, 15, 27, 10};
    unsigned long int size = sizeof(a)/sizeof(int);
    merge_sort(a, size);
    
    int i;
    for (i = 0; i < size; i ++)
        printf("%d ", a[i]);
    printf("\n");    
    return 0;
}
