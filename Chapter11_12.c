#include <stdio.h>

struct value
{
    double natural, complex;
};

struct value add_complex(struct value a, struct value b)
{
    struct value result = {a.natural + b.natural, a.complex + b.complex};
    return result;
};

int main(void)
{
    struct value a, b, r;
    int test;
    printf("ù��° ��������Է��Ͻÿ�.(a, b):");
	scanf("%lf%lf", &a.natural, &a.complex);
    printf("�ι�° ��� ���� �Է��Ͻÿ�.(a, b):");
    scanf("%lf%lf", &b.natural, &b.complex);
    r = add_complex(a, b); 
    printf("%.1lf + %.1lfi", r.natural, r.complex);
    return 0;
}
