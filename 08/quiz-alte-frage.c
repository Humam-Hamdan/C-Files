#include <stdio.h>

int g(int a, int b)
{
    if(a < b)
        return 1;
    else
    {
        printf("a=%i, b=%i\n", a, b);
        return g(a-2, b) + 1;
    }
}

int main(void)
{
    printf("g: %i\n", g(12, 5));
}
