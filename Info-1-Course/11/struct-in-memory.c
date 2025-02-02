#include <stdio.h>


#include <stdio.h>

struct Kompakt
{
    long int a;
    int b;
    short int c;
    char d;
    char e;
};

struct Verschwender
{
    char d;
    long int a;
    short int c;
    int b;
    char e;
};

int main(void)
{
    printf("sizeof(struct Kompakt) = %lu\n", sizeof(struct Kompakt));
    printf("sizeof(struct Verschwender) = %lu\n", sizeof(struct Verschwender));
}
