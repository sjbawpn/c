#include <stdio.h>
#include <stdlib.h>
struct a{
    void (*f)(int); 
    char * b;
} ;
void run_func(void (*f)(int), int a) {
    (*f)(a);
}

void print(int a){
    printf("%d\n",a);
}
int main(int argc, char *argv[]) {
    struct a b;
    //b = (struct a*) malloc( sizeof(struct a));
    b.f = print;
    b.b = "hello\n";
    printf(b.b);
    run_func(b.f, 10);
}
