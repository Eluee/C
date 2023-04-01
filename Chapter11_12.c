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
    printf("첫번째 허수값을입력하시오.(a, b):");
	scanf("%lf%lf", &a.natural, &a.complex);
    printf("두번째 허수 값을 입력하시오.(a, b):");
    scanf("%lf%lf", &b.natural, &b.complex);
    r = add_complex(a, b); 
    printf("%.1lf + %.1lfi", r.natural, r.complex);
    return 0;
}
