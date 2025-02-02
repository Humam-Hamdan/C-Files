
// berechnet Approximationen an den goldenen Schnitt als Quotient zweier
// benachbarter Fibonacci-Zahlen
// zu vervollständigendes Programm im Quiz zur Vorlesung
// Andreas Frommer, 29.11.2020

#include <stdio.h>

int main(void) 
{
    int f, f_alt, f_temp;   // den Typ von f und f_alt nicht ändern!
    int n, grenze;
    double quotient;

    printf("bis wohin?\n");
    scanf("%d", &grenze);

    n = 0;
    f_alt = 0;  // dient als f_{-1}, damit auch f_1 als f_0 + f_{-1} berechnet werden kann
    f = 1;   // = f_0

    for (n = 0; n <= grenze; n++) 
    {
        printf("%d-te Fibonacci-Zahl: %d\n",n,f);
        // jetzt hier die Ausgabe von f_alt / f ergänzen, berechnet als double
        printf("   %10.8f\n", (double) f_alt / f);
        // jetzt neues f berechnen und f_alt auf altes f setzen. Dazu wird das alte f zwischengespeichert.
        
        // Berechnung und Ausgabe des Quotienten
        if (n > 0) 
        {
            quotient = (double) f / f_alt;
            printf("   Quotient f_%d / f_%d = %10.8f\n", n, n-1, quotient);

            // Ab n = 21: Ausgabe des stabilen Wertes
            if (n == 21) 
            {
                printf("Ab n = 21 ist der Quotient (ungefähr der goldene Schnitt) konstant: %10.8f\n", quotient);
            }
        }
        
        f_temp = f;
        f = f + f_alt;  // neues f, das alte f ist jetzt überschrieben
        f_alt = f_temp; // neues f_alt ist altes f
    }
}

