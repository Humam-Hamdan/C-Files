#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int zahl;

    printf("Nichtnegative Zahl eingeben: ");
    scanf("%d", &zahl);

    if (zahl < 0)
        goto fehler;
    else
        goto ok;

    fehler:
        printf("Falsche Eingabe\n");
        exit(EXIT_FAILURE);
        
    ok:
        printf("Eingabe war in Ordnung\n");
}
