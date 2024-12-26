// Folge der Spiralzahlen: 1 3 5 9 13 19 25 33 41 .... (alle zwei Schritte vergrößert sich der Abstand (=das Inkrement) um 2)
// korrigierte Version im Vgl zur Vorlesung vom 21.11.2024
// Andreas Frommer, 21.11.2024
// Was war falsch? Man muss das Inkrement ändern, NACHDEM man die nächste Spiralzahl s ausgerechnet hat

#include <stdio.h>

int main() {
    int grenze;
    int s=1;
    int inkrement=2;
    int zaehler = 0;

    printf("Bis wohin? ");
    scanf("%d",&grenze);

    while (s <= grenze) {
        printf("Die %d-te Zahl ist %d\n", zaehler, s);
        zaehler++;
        s += inkrement;
        if (!(zaehler%2))
            inkrement += 2;
    }
}
