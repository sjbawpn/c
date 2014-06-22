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
void printg(long int graph[MAX_V][MAX_V+1], int max) {

    int i;
    for (i = 0; i < max; i++) {
        int j = 1;
        for(j = 1; j < graph[i][0] + 1; j++) {
            printf("%li ", graph[i][j]);
        }
        puts("");
    }
}

int remove_edge(long int graph[MAX_V][MAX_V+1], int n) {
    unsigned int v = genrand(n - 1);
    unsigned int r = genrand(graph[v][0]) + 1;
    unsigned int w = graph[v][r] - 1;
    printf("start %u end %u\n", v, w);
    int mi = min(v,w);
    int ma = max(v,w);
    printg(graph, n);
    
    
}

// get an edge 
int get_dest(long int** graph, int source) {
    int size = graph[source-1][0];
    int idx = genrand(size) + 1;


    return graph[source-1][idx];

}

int delete_reference(long int graph[MAX_V][MAX_V+1], int w) {


}

int main(int argc, char* argv[]) {  
    FILE* file = fopen("ran1.txt", "rt");
    char line[255];
    //long int** adj[MAX_V][MAX_V+1];
    long int **adj = (long int**) malloc(MAX_V * sizeof(long int*));
    int i = 0;
    while( fgets(line, 255, file) != NULL) {
         
        long int node;
        char* pEnd;
        int j = 1;
        long int v = strtol(line, &pEnd, 0) - 1;
        // Note: This does not support integers value of 0;
        while ((node = strtol(pEnd, &pEnd,0)) != 0) {
            adj[v][j] = node;
            j++;

        }
        adj[v][0] = j - 1;
    }

    fclose(file);
    unsigned int iseed = (unsigned int)time(NULL);
    srand (iseed);

    int m = genrand(MAX_V) + 1;
    int n = get_dest(adj, m);
    int v = min(m,n);
    int w = max(m,n);
    printg(adj, MAX_V);
    printf("v=%d,w=%d\n",v,w);

    
}
