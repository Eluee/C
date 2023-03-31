#include <stdio.h>

struct student
{
    char name[9];
    union
    {
        char id[9];
        char RRN[16];
    };
};

int main(void)
{
    struct student st = {"정성화", "20190586"};
    printf("%s %s %s", st.name, st.id, st.RRN);
    return 0;
}
