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
		printf("상품의 이름:");
		scanf("%s", product[i].name);
		printf("상품의 가격:");
		scanf("%d", &product[i].price);
		printf("상품의 개수:");
		scanf("%d", &product[i].totalNumber);
		product[i].totalPrice = product[i].price * product[i].totalNumber; 
		printf("===============\n");
	}
	printf("검색할 상품이름을 입력해주세요:");
	scanf("%s",input);
	for(i = 0;i < 5; i++){
		if(strcmp(product[i].name, input) == 0) break;
	} 
	
	printf("========검색하신 상품입니다.=======\n");
	printf("상품의 이름: %s\n", product[i].name );
	printf("상품의 가격: %d\n", product[i].price);
	printf("상품의 개수: %d\n", product[i].totalNumber);
	printf("총재고액: %d\n", product[i].totalPrice); 
	printf("===================================\n");
	
	return 0;
}


