/**************************************/
/* Humam Hamdan                       */
/* Gruppe: Do.12                      */
/* Leiter: Florian Möschler           */
/* Uebungsblatt:  4  , Aufgabe:7      */
/* Datum:    13 Nov :)                */
/* Status:  Done                      */
/**************************************/

/*
Pseudocode:
1. Lies die Anzahl der Zeilen n ein
2.  Zahl  = 1
3. Für jede Zeile i von 1 bis n:
   4. Für jede Zahl j von 1 bis i:
      5. Wenn nummer < 10, gib extra Leerzeichen aus
      6. Gib nummer aus, gefolgt von Leerzeichen
      7. Erhöhe nummer um 1
   8. Gib Zeilenumbruch aus
*/

#include <stdio.h>

int main()
{
    int n,i,j;

    printf("Geben Sie die Anzahl der Zeilen ein: ");
    scanf("%d", &n);

    int nummer = 1;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf("%2d ", nummer);
            nummer++;
        }
        printf("\n");
    }
    return 0;
}
