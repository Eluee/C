#include<stdio.h>
#include<string.h>

struct user {
    char name[30];
    int  age;
};

int main(void) {
    struct user user[10];
    strcpy(user[0].name, "TEST");
    user[0].age = 24;

    printf("name : %s, age : %d\n", user[0].name, user[0].age);
    
    return 0;
}