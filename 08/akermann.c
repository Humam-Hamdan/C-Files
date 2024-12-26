#include <stdio.h>

// Ackermann-Funktion
long A(long m, long n)
{
    if (m == 0)
    return n + 1;
    else if (n == 0)
    return A(m - 1, 1);
    else
    return A(m - 1, A(m, n - 1));
}

int main(void)
{
    int m, n;

    printf("m, n eingeben: ");
    scanf("%d %d", &m, &n);

    printf("A(%d,%d) = %ld\n", m, n, A(m, n));
    // automatische Casts der Argumente m, n: int → long
}