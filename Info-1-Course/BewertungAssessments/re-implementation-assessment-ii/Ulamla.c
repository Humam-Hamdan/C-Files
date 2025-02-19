#include <stdio.h>
/* 
Liest eine Zahl n ein und führt mit dieser die „Ulam-Iteration“ durch:
    ist n gerade, so wird n durch n ∕ 2 ersetzt,
    ungerades n wird durch 3 · n + 1 ersetzt.
Wiederholung, bis der Wert 1 erreicht ist
*/
int main(void)
{
    int n;

    // gültiges n einlesen
    do
        {
            printf("Positive ganze Zahl eingeben: ");
            scanf("%d", &n);
            if (n <= 0)
            printf("Ungültige Eingabe.\n");
        }
    while (n <= 0);

    // Iteration

    int anzahl=0;

    while (n != 1)
        {
            anzahl= anzahl + 1; 
            printf("%d → ", n);
            if (n % 2 == 0)
                n = n / 2;
            else
                n = 3 * n + 1;
        }
    printf("%d\n", n);
    printf("Anzahl Schritte: %d\n", anzahl);
}