/************************************************/
/* Assessment I (08.11.2024)                    */
/* auto-generated .c file from text box input   */
/*                                              */
/* Humam Hamdan, 2427300                        */
/************************************************/

#include <stdio.h>

// Berechnung, zur Bestimmung die kleinste Zahl mit dem wir alle vorherige Zahlen zum Quadrat addieren und das Ergebnis mindestens so groß als die eingegebene Zahl

int main(void)
{

    // Variablen
    int z,n,m;//+1P

    // Zahl Eingeben und Lesen
    printf("Bitte geben Sie eine Zahl z ein: ");//+1P
    scanf("%d",&z);

    // int m
    m = 0;//+1P

    // for SUM < z
    for(n=1; (m+(n*n)) < z; n++)//+3P
        {
            m = m + (n*n);//+1P
        }

    // Endergebnis eingeben
    printf("n = %d",n);//+1P
    
}//+2P
// 10/10P