#include <stdio.h>

// „Anfänger-Variante“
int fac1(int n)
{
    int fac = 1;
    for (int i = 1; i <= n; i++)
    fac *= i;
    return fac;
}

// „eleganter“ – besser?
int fac2(int n)
{
    int fac = 1;
    for (int i = 1; i <= n; fac *= i++);
    return fac;
}

// rekursiv: 0! = 1, n! = n · (n − 1)! für n > 0
int fac3(int n)
{
    if (n == 0)
    // Abbruch der Rekursion: kein weiterer Aufruf
        return 1;
    else
        return n * fac3(n - 1);
}

// rekursiv und „kompakt“ – übersichtlich?
int fac4(int n)
{
    return n == 0 ? 1 : n * fac4(n - 1);
}

// Treiber für die Varianten
int main(void)
{
    for (int n = 0; n <= 10; n++)
        printf("%2d! = %8d = %8d = %8d = %8d\n", n, fac1(n), fac2(n), fac3(n), fac4(n));
}