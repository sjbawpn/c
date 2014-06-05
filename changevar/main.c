#include <stdio.h>
#include <string.h>
//#include "header.h"

//void printcc(const char
struct mystruct {
    int size;
    char* mychar;
    const int n;
};
const char* str[] = {"Hello","world"};
int main(int argc, char* argv) {
    struct mystruct stru;
    const i = 1;
    //i = 2;
    stru.mychar = "Hello:world:my:world:this:is:good";
    char str[255];
    strcpy(str, stru.mychar);
    //stru.mychar = "Hello:" "world";
    //stru.n = 1;
    //char* pchs;
    //pchs = strstr(c, ":");
  //  *pchs = '\0';
    
    printf("%s\n", str );
    //printf("%i\n", stru.mychar == NULL);

    //seti(3);
    //printi();
    //size_t i = sizeof(str);
    //printf("%lu", i);
    //char str[] ="- This, a sample string.";
    char * pch;
    printf ("Splitting string \"%s\" into tokens:\n",str);
    pch = strtok (str,":");
    while (pch != NULL)
    {
        printf ("%s\n",pch);
        pch = strtok (NULL, ":");
    }
    printf ("Splitting string \"%s\" into tokens:\n",str);
  return 0;

}
