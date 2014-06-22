#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 1- get a node
// 2- delete reference
// 3- merrge

#define MAX_V 8
unsigned int genrand(long int max) {
    return rand () % max;
}
int min(int a,int b) {
    if(a < b) return a;
    else return b;
}
int max(int a,int b) {
    if(a > b) return a;
    else return b;
}
void printg(long int** graph) {

    int i;
    int max = **graph;
    
    for (i = 1; i < max + 1; i++) {
        int j = 1;
        printf("%d - [%d] ",i,graph[i][0]);
        for(j = 1; j < graph[i][0] + 1; j++) {
            printf("%li ", graph[i][j]);
        }
        puts("");
    }
}

int remove_edge(long int** graph, int n) {
    unsigned int v = genrand(n - 1);
    unsigned int r = genrand(graph[v][0]) + 1;
    unsigned int w = graph[v][r] - 1;
    int mi = min(v,w);
    int ma = max(v,w);
    printg(graph);
    
    
}

// get an edge 
int get_dest(long int** graph, int source) {
    int size = graph[source][0];
    int idx = genrand(size) + 1;


    return graph[source][idx];

}

int change_reference(long int** graph, int w, int v) {
    int size = **graph;
    long int* array = *(graph+w);
    int asize = *array;
    int i = 1;
    // Lookup the entries in the array to remove and iterate through them to find the entry.
    /*
    for (i = 1; i < asize + 1; i ++) {
        long int *a = graph[array[i]];
        int s = a[0];
        int j = 1;
        int offset = 0;
        for (j = 1; j < s + 1 - offset; j++) {
            if (a[j] == w) offset++;
            a[j] = a[j+offset];
        }
        a[0] = s - offset;
        a = (long int*) realloc(a, (a[0] + 1) * sizeof(long int));

    }
    */
    for (i = 1; i < asize + 1; i++) {
        long int *a = graph[array[i]];
        int s = a[0];
        int j = 1;
        for (j = 1; j < s + 1 ; j++) {
            if (a[j] == w) a[j] = v;
        }
    }
    return 0;
}

int delete_node(long int** graph, int w) {
    int size = **graph;
    
    int i = 1;
    int j = 1;

    for (i = w; i < size; i++) {
        graph[i] = graph[i+1];
    }
    graph[0][0] = size - 1;
    for (i = 1; i < size; i++) {
        int asize = graph[i][0];
        int j = 1;
        for (j = 1; j <= asize ; j++) {
            if (graph[i][j] >= w) {
                //if ( i < w)
                //graph[i][j] = graph[i][j] + 1;
                //else
                graph[i][j] = graph[i][j] - 1;
            }
        }
    }
    return 0;

}

int remove_selfloops(long int** graph, int v) {
    int size = **graph;
    long int* a = *(graph+v);
    int s = *a;
    int i = 1;
    // Lookup the entries in the array to remove and iterate through them to find the entry.
    
    int j = 1;
    int offset = 0;
    for (j = 1; j < s + 1 - offset; j++) {
        if (a[j] == v) {
            int l = 0;
            while(a[j+l] == v) {
                offset++;
                l++;
            }
            printf("removing %d from %d\n", a[j], v);
        }
        a[j] = a[j+offset];
    }
    a[0] = s - offset;
    a = (long int*) realloc(a, (a[0] + 1) * sizeof(long int));

    return 0;
}

int merge_nodes(long int ** graph, int src, int dest) {
    int size = **graph;
    long int* srcArray = *(graph+src);
    long int* destArray = *(graph+dest);
    int srcSize = *srcArray;
    int destSize = *destArray;
    destArray = (long int*) realloc(destArray, (*srcArray + *destArray + 2) * sizeof(long int));

    // TODO figure out how to reference the address of an offset of an array
    int i = 1;
    int ptr = 0;
    int offset = destSize + 1;
    for (i = 1; i <= srcSize; i++) {
        if (srcArray[i] != dest) {
            destArray[ptr+offset] = srcArray[i];
            destArray[0] = destArray[0] + 1;
            ptr++;
        }
    }


    destArray = (long int*) realloc(destArray, (destArray[0] + 1) * sizeof(long int));
    graph[dest] = destArray;
    return 0;

}

int cut(long int** graph) {
    int x = graph[0][0];
    int m = genrand(x) + 1;
    int n = get_dest(graph, m);
    int v = min(m,n);
    int w = max(m,n);
    printf("v=%d,w=%d\n",v,w);
    change_reference(graph, w, v);
    merge_nodes(graph, w, v);
    delete_node(graph, w);
    remove_selfloops(graph, v);

}
int main(int argc, char* argv[]) {  
    FILE* file = fopen("ran1.txt", "rt");
    char line[255];
    //long int** adj[MAX_V][MAX_V+1];
    long int **adj = (long int**) malloc((MAX_V+1) * sizeof(long int*));
    int i = 1;
    while( fgets(line, 255, file) != NULL) {
        *(adj+i) = (long int*) malloc((MAX_V + 1) * sizeof(long int));
        long int node;
        char* pEnd;
        int j = 1;
        long int v = strtol(line, &pEnd, 0);
        // Note: This does not support integers value of 0;
        while ((node = strtol(pEnd, &pEnd,0)) != 0) {
            *(*(adj+v)+j) = node;
            j++;

        }
        *(*(adj+v)) = j - 1;
        *(adj+i) = (long int*) realloc(*(adj+i), j * sizeof(long int));
        i++;
    }
    *adj = (long int*) malloc(sizeof(long int));
    **adj=i-1;

    fclose(file);
    unsigned int iseed = (unsigned int)time(NULL);
    srand (iseed);

    printg(adj);
    printf("-------\n");
    while (adj[0][0] > 2) {
        cut(adj);
        printg(adj);
        printf("-------\n");
    }
    //printf("size=%d\n",graph[v][0]);
}
