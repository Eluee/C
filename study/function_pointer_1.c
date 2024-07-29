#include<stdio.h>

int add(int a, int b){
    return a + b;
};

int min(int a, int b){
    return a - b;
};

int main(void) {
    int (*pfunction)(int, int);
    int x = 3, y = 10;

    pfunction = &add;
    printf("result add() : %d\n", pfunction(x, y));

    pfunction = &min;
    printf("result min() : %d\n", pfunction(x, y));
    
    return 0;
}