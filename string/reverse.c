#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[]) {
    char* str = argv[1]; 
    int len = strlen(str);
    int i;
    char str2[strlen(str)];
    strcpy(str2, str);
    printf("%s %i\n", str+5, *(str+5) == NULL);
    for (i = 0; i < len /2; i++) {
        char buf = *(str2 + i);
        *(str2 + i) = *(str2 + len - 1 - i);
        *(str2 + len - 1 - i) = buf;
    }
    printf("%s %li\n", str2, strlen(str));
}
