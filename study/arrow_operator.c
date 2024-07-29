#include<stdio.h>
#include<string.h>

typedef struct {
    char name[30];
    int  age;
}User;

void printInfo(User *puser) { 
    printf("name : %s\n", puser->name);
    printf("age : %d\n", puser->age);
    
}

int main(void) {
    User user;
    strcpy(user.name, "JSH");
    user.age = 24;

    printInfo(&user);

    return 0;
}