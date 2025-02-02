#include <stdio.h>
// Berechnung der Fakultät n! = 1 · 2 · … · (n − 1) · n
// einer einzugebenden Zahl n
int main(void)
{
    int n, i, fakultaet;
    printf("n eingeben: "); 
    scanf("%d", &n);
    fakultaet = 1;
    for (i = 1; i <= n; i = i + 1)
    {
        fakultaet = fakultaet * i;   
    }
    if (fakultaet <0) printf("%d! ist nicht in diesem Programm positiv\n", n);
    else printf("%d! = %d\n", n, fakultaet);
}
