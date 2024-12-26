#include <stdio.h>
// Beispiel für Abbruch des Schleifendurchlaufs
int main(void)
{
    int i, antwort;

    for (i = 1; i <= 5; i = i + 1)
    {
        printf("Weitere Angaben zu Nr. %d nötig? (1 = ja, 0 = nein): ", i);
        scanf("%d", &antwort);

        if (antwort != 1)
        continue;
    
        printf("Angaben zu Nr. %d: …\n", i);
        // weitere Ausgaben
    }
}
