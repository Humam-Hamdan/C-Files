#include <stdio.h>

int main(void)
{
    int i = 1, j = 2;

    const double d = 0.1;
    const int z = 10;
    printf("%f\n", z * d);
    printf("%i\n", z * (int) d);
    printf("%i\n", (int) (z * d));
    printf("%i\n", (int) (z * d + 0.5));
    printf("%i, ", i++ == --j);
    printf("i=%i, j=%i\n", i, j);
    printf("%i, ", ++j == i--);
    printf("i=%i, j=%i\n", i, j);
    printf("%i, ", i = i + ++j);
    printf("i=%i, j=%i\n", i, j);
    printf("%f\n", 1.0 / (int) ( (int) 7 * d + (double) 4 / j-- ) );
}
