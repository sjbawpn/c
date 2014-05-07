#include <stdio.h>
#include "addition.h"

int sub(int a, int b) {
    int s = add(a, b);
    printf("Hello %d\n", s);
    return a - b;
}
