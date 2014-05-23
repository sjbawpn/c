#include <stdio.h>

long int count = 0;
void swap(int* a, int i, int j) {
    int buffer = a[i];
    a[i] = a[j];
    a[j] = buffer;
}
int chosePivot(int* a,int start, int end) {
    //int p = start;
    //int p = end;
    int m = ((end + start) / 2);
    int p;
    if (a[start] > a[m]) {
        if (a[m] > a[end]) {
            p = m;
        } else if (a[start] > a[end]) {
            p = end;
        } else {
            p = start;
        }

    } else {
        if (a[start] > a[end]) {
            p = start;
        } else if (a[m] > a[end]) {
            p = end;
        } else {
            p = m;
        }
    }
    //int p = a[start] < a[end] ? a[start] : a[end];
    //printf("start=%i (%i) end=%i (%i) median=%i (%i) p=%i (%i)\n", start, a[start], end, a[end],m, a[m], p, a[p]);
    return p;
}
void partition(int* a, int start, int end) {
    if (end - start < 1) return;
    count = count + end - start;
    //printf("count is %li\n", count);
    int p = chosePivot(a, start, end);
    swap(a, start, p);
    int pivot = a[start];
    int i = start + 1;
    int j;

    for (j = start + 1; j <= end; j++) {
        if (a[j] < pivot) {
            swap(a,i,j);
            i++;
        }
    }
    swap(a, start, i-1);
    partition(a, start, i-2);
    partition(a, i, end);
}

void quicksort(int* a, int size) {
    partition(a, 0, size-1);
}
int main(int argc, char* argv[]) {
   /* 
    int array[] = {11, 22, 3, 54, 15, 27, 10, 29, 110, 20, 13, 14, 16};
    unsigned long int size = sizeof(array)/sizeof(int);
    quicksort(array, size);
    
    //printf("The size %li\n", size);
    int i;
    for (i = 0; i < size; i ++)
        printf("%d ", array[i]);
    printf("\n");    
    printf("The number of counts is %li\n", count);
    */
  // /*
    //FILE *fr = fopen("QuickSort.txt", "rt");
    FILE *fr = fopen("QuickSort.txt", "rt");
    char line[10];
    int array[10000];
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
    quicksort(array, size); 
    printf("The number of counts is %li\n", count);
//*/
    int j;
    int min = 0;
    for (j = 1; j < size; j++) {
        if (array[j] < array[j-1]) {
            printf("The array is not sorted!!\n");
            break;
            
        }
        
    }
    return 1;

}
