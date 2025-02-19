// #include <stdbool.h> // seit C23 nicht mehr nötig
#include <stdio.h>
// Liste von Primzahlen
int main(void)
{
    int anzahlGesucht;       // Wie viele Primzahlen sind zu bestimmen?
    int anzahlGefunden;      // Wie viele wurden bereits gefunden?
    int p;                   // „Kandidat“ für nächste Primzahl
    int t;                   // möglicher Teiler von p
    bool teilerGefunden;     // Wurde ein Teiler von p gefunden?

    printf("Anzahl der zu bestimmenden Primzahlen: ");
    scanf("%d", &anzahlGesucht);

    if (anzahlGesucht > 0)
    {
        anzahlGefunden = 0;
        // teste mögliche Primzahlen
        p = 2;
        do
        {
            teilerGefunden = false;
            for (t = 2; t < p; t = t + 1)
                if (p % t == 0)
                   teilerGefunden = true;
            // wenn teilerGefunden hier noch false ist, hat p keinen echten Teiler
            // und ist daher prim
            if (teilerGefunden == false)
            {
                anzahlGefunden = anzahlGefunden + 1;
                printf("%d.␣Primzahl␣=␣%d\n", anzahlGefunden, p);
            }
            p = p + 1;
        }
        while (anzahlGefunden < anzahlGesucht);
    }
    else
    printf("Nichts zu tun!\n");
}
