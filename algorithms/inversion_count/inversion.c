#include <stdio.h>
#include <strings.h>

long int count(int* a, int start, int mid, int end, int * b) {
    int i = start;
    int j = mid;
    int len = end - start;
    int idx = 0;
    long int c = 0; 
    for (idx = start; idx < end; idx++) {
        if ((i < mid) && ( (j >= end) || (a[i] < a[j]) )) {
            b[idx] = a[i];
            i++;
        } else {
            b[idx] = a[j];
            c = c + mid - i;
            j++;
        }
    }

    return c;
    
}

void copy(int* b, int start, int end, int* a) {
    int i;
    for (i = start; i < end; i++) {
        a[i] = b[i];
    }
}
long int sort(int* a, int start, int end, int* b) {
    unsigned long int size = sizeof(*a)/sizeof(int);
    if (end - start < 2) return 0;
    
    int m = (start + end) / 2;
    long int x = 0;
    long int y = 0;
    long int z = 0;
    x = sort(a, start, m, b);
    y = sort(a, m, end, b);
    z = count(a, start, m, end, b);
    copy(b, start, end, a);
    return x + y + z;
}

long int inversion_count(int* a, int size) {
    int b[size];
    unsigned long int l = sizeof(a);
    int i;
    for (i = 0; i < size; i++)
        b[i] = 0;
    long int c = sort(a, 0, size, b);
    return c;
}
int main(int argc, char* argv[]) {

    //int a[] = {10, 22, 3, 54, 15, 27, 10};
    FILE *fr = fopen("IntegerArray.txt", "rt");
    char line[10];
    int array[100000];
    int i;
    int idx = 0;
    while(fgets(line,10,fr) != NULL) {
        sscanf(line, "%i", &i);
        array[idx++] = i;
        //printf("%i\n", i);

    }

    fclose(fr);
    //int a[] = {1, 3, 5, 2, 4, 6};
    unsigned long int size = sizeof(array)/sizeof(int);
    printf("%lu\n", size);
    long int c = inversion_count(array, size);
    printf("%li\n", c);
    
    return 0;
}
