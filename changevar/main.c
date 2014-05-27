#include <stdio.h>
//#include "header.h"

//void printcc(const char
struct mystruct {
    int size;
    const char* mychar;
};
const char* str[] = {"Hello","world"};
int main(int argc, char* argv) {
    struct mystruct stru;
    //stru.mychar = "Hello" "world";
    //stru.mychar = "Hello:" "world";
    printf("%i\n", stru.mychar == NULL);
    //seti(3);
    //printi();
    //size_t i = sizeof(str);
    //printf("%lu", i);
}
