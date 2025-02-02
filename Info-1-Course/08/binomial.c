#include <stdio.h>

// liefert den Binomialkoeffizienten „m aus n“ zurück
long binomkoeff(long m, long n){
    if (m == 0 || m == n)
    return 1;
    else
    return binomkoeff(m, n - 1) + binomkoeff(m - 1, n - 1);
}

int main(void){
    long m, n;

    do{
        printf("Eingabe der natürlichen Zahl n: ");
        scanf("%ld", &n);
    }
    while (n <= 0);
    do{
        printf("Eingabe m mit 0 ≤ m ≤ %ld: ", n);
        scanf("%ld", &m);
    }
    while (m > n || m < 0);
    printf("Der Binomialkoeffizient %ld aus %ld ist: %ld\n", m, n,
    binomkoeff(m, n));
}