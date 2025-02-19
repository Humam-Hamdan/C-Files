#include <stdio.h>
#include <stdbool.h>
/* Wiederholtes Einlesen eines Wertes,
bis dieser in einem bestimmten Bereich liegt */
int main(void)
{
    int zahl;

    while (true)    // potenzielle Endlosschleife
    {
        printf("Zahl von 0 bis 10 eingeben: ");
        scanf("%d", &zahl);
        bool BreakCondition = (zahl >=0) && (zahl <= 10);
        if (BreakCondition)    // OK
            break;

        printf("Eingabe ungültig; wiederholen\n");
    }
    printf("Ihre Eingabe war: %d\n", zahl);
}
