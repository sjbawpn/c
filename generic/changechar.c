#include <stdio.h>

void copy(char* src, char** dest) {
    *dest = "world";
    size_t i;
    for (i = 0; src[i]; i++) {
        src[i] = toupper(src[i]);
    }

}
int main(int argc, char* argv[]) {
    char* mychar = "hello";
    char* newchar;

    newchar = "new";
    copy(mychar, &newchar);
    
    printf("%s\n", newchar);
    printf("%s\n", mychar);

}
