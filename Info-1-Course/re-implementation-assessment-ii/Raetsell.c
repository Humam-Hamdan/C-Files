#include <stdio.h>

int main(void)
{
    int x = 2, y = 1, z = 0;
    printf("x=%d y=%d z=%d\n", x, y, z);
    x *= 3;
    printf("x=%d y=%d z=%d\n", x, y, z);
    x = y == 4;
    printf("x=%d y=%d z=%d\n", x, y, z);
    z = x++ || ++y;
    printf("x=%d y=%d z=%d\n", x, y, z);
    z = x++ || ++y;
    printf("x=%d y=%d z=%d\n", x, y, z);
    y = !!y;
    printf("x=%d y=%d z=%d\n", x, y, z);
    --y || --z && --x;
    printf("x=%d y=%d z=%d\n", x, y, z);
}
