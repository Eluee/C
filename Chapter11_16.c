#include<stdio.h>
#include<stdlib.h>
#include<time.h>


enum item{
	r, c, p
};

int main(void) {
	srand(time(NULL));
	enum item user, com;
	printf("가위(0) 바위(1) 보(2)를 입력하세요: ");
	scanf("%d", &user);
	com = rand()%3; 
	if(user + 1 == com ) printf("승리했습니다.");
	else if( user + 1 == 3 && com == 0) printf("승리했습니다.");
	else if(user == com) printf("비겼습니다.");
	else printf("졌습니다."); 
	return 0;
}


