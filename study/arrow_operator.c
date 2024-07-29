#include<stdio.h>
#include<string.h>

typedef struct {
    char name[30];
    int  age;
}User;

void dereference_access(User *puser) { //call by reference
    printf("name : %s\n", (*puser).name);
    printf("age : %d\n", (*puser).age);
    
}

void arrow_operator(User *puser) { //call by reference
    printf("name : %s\n", puser->name);
    printf("age : %d\n", puser->age);
    
}

void dot_operator(User user) { //call by value
    printf("name : %s\n", user.name);
    printf("age : %d\n", user.age);
    
}

int main(void) {
    User user;
    strcpy(user.name, "JSH");
    user.age = 24;

    dereference_access(&user);
    arrow_operator(&user);
    dot_operator(user);

    return 0;
}