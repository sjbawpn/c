#include <stdio.h>


int main(int argc, char* argv[]) {
    int sum = 1;
    int i = 0;
    int m = 10;
    for (i = 0; i < 6; i++) {
        sum = (sum * 9) + m;
        m = m * 10;
        printf("%d\n", sum);
    }

    printf("%d\n", sum);
    
}
