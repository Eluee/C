#include<stdio.h>
#include<stdlib.h>
#include<time.h>


enum item{
	r, c, p
};

int main(void) {
	srand(time(NULL));
	enum item user, com;
	printf("����(0) ����(1) ��(2)�� �Է��ϼ���: ");
	scanf("%d", &user);
	com = rand()%3; 
	if(user + 1 == com ) printf("�¸��߽��ϴ�.");
	else if( user + 1 == 3 && com == 0) printf("�¸��߽��ϴ�.");
	else if(user == com) printf("�����ϴ�.");
	else printf("�����ϴ�."); 
	return 0;
}


