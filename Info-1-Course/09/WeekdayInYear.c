// berechnet den Wochentag des seleben Datums im kommenden Jahr 
// Andreas Frommer, 21.12.2020

#include <stdio.h>
#include <stdbool.h>

typedef enum {MO,DI,MI,DO,FR,SA,SO} Wochentag;
typedef int Datum[3];

int tage_im_Jahr(int jahr) {
    if( (jahr%4==0 && jahr%100!=0) || jahr%400==0 )
        return 366;
    else
        return 365;
}

bool schaltjahr( int jahr) {
    return !(tage_im_Jahr(jahr)%2);
}

Wochentag um_eins_verschieben(Wochentag wtag) {
    switch (wtag) {
        case SO:
          return MO;
          break;
        case MO:
          return DI;
          break;
        case DI:
          return MI;
          break;
        case MI:
          return DO;
          break;
        case DO:
          return FR;
          break;
        case FR:
          return SA;
          break;
        case SA:
          return SO;
          break;
        default:
          printf("Wochentag nicht vorhanden!\n");
    }
}
          
Wochentag wochentag_im_naechsten_jahr(Datum datum, Wochentag wtag) {
    int tag = datum[0], monat = datum[1], jahr = datum[2];
    Wochentag wtag_neu;
    // der Wochentag verschiebt sich um eins im kommenden Jahr, außer das aktuelle Jahr ist ein Schaltjahr, und das Datum ist vor dem 29.2. oder das kommende Jahr ist ein Schaltjahr und das Datum ist nach dem 28.2. - dann verschiebt er sich um 2
    wtag_neu = um_eins_verschieben(wtag);
    if ( (schaltjahr(jahr) && monat <= 2 && tag < 29) || (schaltjahr(jahr+1) && monat >=3) )
        wtag_neu = um_eins_verschieben(wtag_neu);
    return wtag_neu;
}
    
    
/* OG
int main(void) {
    // Teil 1: wtag und datum in den beiden folgenden Zeilen initialisieren auf Mittwoch, den 25.12.2024
    Datum datum;
    Wochentag wtag;
    // Teil 2: die nächsten beiden Zeilen so abändern, dass statt des Wochentags im nächsten Jahr der Wochentag des Datums in einem in der Zukuft liegenden Jahr (z.B. 2071) ausgegeben wird. Dieses Jahr soll zuerst eingelesen werden. Um den Wochentag zu bestimmen, verwendet man am besten eine for-Schleife
    wtag = wochentag_im_naechsten_jahr(datum, wtag);
    printf("Der %d. %d. %d ist ein %d\n", datum[0], datum[1], datum[2]+1, wtag);
    // Die Ausgabe könnte man zudem noch so verbessern, dass der Wochentag als "MO", "DI" etc. statt als Zahl 0,1, ausgegeben wird
}
*/
/* FRAGE 1
int main(void) {
    // Teil 1: Initialisiere Datum und Wochentag
    Datum datum = {25, 12, 2024}; // 25. Dezember 2024
    Wochentag wtag = MI; // Mittwoch

    // Teil 2: Ziel-Jahr von Benutzer einlesen
    int ziel_jahr;
    printf("Bitte geben Sie das Ziel-Jahr ein: ");
    scanf("%d", &ziel_jahr);

    // Wochentag für das Ziel-Jahr berechnen
    for (int aktuelles_jahr = datum[2] + 1; aktuelles_jahr <= ziel_Jahr; aktuelles_Jahr++) {
        // Aktuelle Jahresinformationen aktualisieren
        datum[2] = aktuelles_Jahr;
        
        // Wochentag für das aktuelle Jahr berechnen
        wtag = wochentag_im_naechsten_Jahr(datum, wtag);
    }

    // Ausgabe mit Wochentag-Namen
    char *wochentag_Namen[] = {"MO", "DI", "MI", "DO", "FR", "SA", "SO"};
    printf("Der %d. %d. %d ist ein %s\n", 
           datum[0], datum[1], datum[2], wochentag_Namen[wtag]);

    return 0;
}
*/
int main(void) {
    // Initialisiere Datum und Wochentag für den Ausgangspunkt
    Datum datum = {31, 12, 2024}; // 31. Dezember 2024
    Wochentag wtag = DI; // Dienstag

    // Ziel-Jahr
    int ziel_Jahr = 3333;

    // Wochentag für das Ziel-Jahr berechnen
    for (int aktuelles_jahr = datum[2] + 1; aktuelles_jahr <= ziel_Jahr; aktuelles_jahr++) {
        // Aktuelle Jahresinformationen aktualisieren
        datum[2] = aktuelles_jahr;
        
        // Wochentag für das aktuelle Jahr berechnen
        wtag = wochentag_im_naechsten_jahr(datum, wtag);
    }

    // Ausgabe mit Wochentag-Namen
    char *wochentag_Namen[] = {"MO", "DI", "MI", "DO", "FR", "SA", "SO"};
    printf("Der 31.12.%d ist ein %s\n", ziel_Jahr, wochentag_Namen[wtag]);

    return 0;
}