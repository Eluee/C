#include<stdio.h>

int main(void) {
    int a = 10;
    int b = 3;
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a + b = %f\n", (double)a / b);
    printf("a + b = %d\n", a % b);

    return 0;
}