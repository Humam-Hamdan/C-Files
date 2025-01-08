
#include <stdio.h>
#include <string.h>  // for strcpy

typedef struct {
    char prod[20];
    int anzahl;
} Vorrat;

void vorrat_anlegen1(Vorrat *vorrat, char* art, int menge) {
    strcpy(vorrat->prod, art);
    vorrat->anzahl = menge;
}

void vorrat_anlegen2(Vorrat vorrat, char* art, int menge) {
    strcpy(vorrat.prod, art);
    vorrat.anzahl = menge;
}

// does nothig, coz no ptr

int main() {
    Vorrat vorrat;
    strcpy(vorrat.prod, "Kaviar");
    vorrat.anzahl = 5;
    printf("Wir haben %d %s\n", vorrat.anzahl, vorrat.prod);

    vorrat_anlegen1(&vorrat, "Wodka", 20);
    printf("Wir haben %d %s\n", vorrat.anzahl, vorrat.prod);

    vorrat_anlegen2(vorrat, "Reis", 3);
    printf("Wir haben %d %s\n", vorrat.anzahl, vorrat.prod);

    return 0;
}
