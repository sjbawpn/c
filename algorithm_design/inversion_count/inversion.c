#include <stdio.h>

int main(int argc, char* argv[]) {
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

    for (idx = 0; idx < 100000; idx++) {
        printf("%i\n", array[idx]);
    }


}
