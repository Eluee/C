#include<stdio.h>

int main(void){
    int* ptmp   = NULL;
    int  target = 0;
    
    printf("Enter a number : ");
    scanf("%d", &target);

    ptmp = &target;

    printf("ptmp : %p\n", (void *)ptmp);
    printf("*ptmp : %d\n", *ptmp);
    printf("&ptmp : %p\n\n", &ptmp);

    printf("target: %d\n", target); 
    printf("target: %p\n", &target);
    
    return 0;
}