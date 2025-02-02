// the game where you take a tower of circles and change the location

#include <stdio.h>

/* bewegt die obersten „anzahl“ Scheiben von „startStab“ nach „zielStab“,
wobei „hilfsStab“ als Zwischenspeicher benutzt wird */
void bewege(int anzahl, int startStab, int zielStab, int hilfsStab)
{
    if (anzahl > 0) // sonst fertig
    {
        bewege(anzahl - 1, startStab, hilfsStab, zielStab);
        printf(”Bewege␣oberste␣Scheibe␣von␣%d␣nach␣%d\n”, startStab, zielStab);
        bewege(anzahl - 1, hilfsStab, zielStab, startStab);
    }
}

// bewegt den Turm von Stab 1 nach Stab 2
int main(void)
{
    int anzahl;

    printf(”Anzahl␣der␣Scheiben␣auf␣Stab␣1:␣”);
    scanf(”%d”, &anzahl);

    bewege(anzahl, 1, 2, 3);
}