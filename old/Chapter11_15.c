#include<stdio.h>
#include<string.h>

struct storage {
	char name[30];
	int price;
	int totalNumber;
	int totalPrice;
	
};



int main(void) {
	struct storage product[5];
	int i;
	char input[30];
	for ( i = 0; i < 5; i++) {
		printf("===============\n");
		printf("��ǰ�� �̸�:");
		scanf("%s", product[i].name);
		printf("��ǰ�� ����:");
		scanf("%d", &product[i].price);
		printf("��ǰ�� ����:");
		scanf("%d", &product[i].totalNumber);
		product[i].totalPrice = product[i].price * product[i].totalNumber; 
		printf("===============\n");
	}
	printf("�˻��� ��ǰ�̸��� �Է����ּ���:");
	scanf("%s",input);
	for(i = 0;i < 5; i++){
		if(strcmp(product[i].name, input) == 0) break;
	} 
	
	printf("========�˻��Ͻ� ��ǰ�Դϴ�.=======\n");
	printf("��ǰ�� �̸�: %s\n", product[i].name );
	printf("��ǰ�� ����: %d\n", product[i].price);
	printf("��ǰ�� ����: %d\n", product[i].totalNumber);
	printf("������: %d\n", product[i].totalPrice); 
	printf("===================================\n");
	
	return 0;
}


