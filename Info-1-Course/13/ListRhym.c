
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Beachte: NULL = nullptr

// maximale Länge eines Namens
constexpr int NAME_MAX = 20;

// Zeichenkette für Name eines Kindes
typedef char String[NAME_MAX];

// Kind im Kreis mit Zeiger auf nächstes Kind
typedef struct Knoten
{
    String name; // Name des Kindes
    struct Knoten* weiter; // nächstes Kind im Kreis
} Knoten;

/* erzeuge einen neuen Knoten und lege darin den Namen name und den
   „Weiter“-Zeiger w ab; liefere einen Zeiger auf den neuen Knoten zurück.
   Abbruch, wenn kein Speicherplatz verfügbar war. */

Knoten* zeigerAufNeuenKnoten(String name, Knoten* w)
{
    Knoten* neu = malloc(sizeof(Knoten)); // Speicher belegen
    if (neu == nullptr)
    {
        printf("### Programmabbruch, da Speicheranforderung in "
               "zeigerAufNeuenKnoten fehlschlug!\\n");
        exit(EXIT_FAILURE);
    }

    strcpy(neu->name, name);
    neu->weiter = w;

    return neu;
}


// gibt den über anfang erreichbaren Kreis aus
void kreisAusgeben(Knoten* anfang)
{
    Knoten* pos = anfang;
    int anzahl = 0; // Anzahl der Kinder

    printf("--- Kreis: ");
    if (anfang != nullptr) // wenn Kreis nicht leer
    {
        do // Knoten ausgeben, bis wieder der Anfang erreicht ist
        {
            printf("%s ", pos->name);
            anzahl++;
            pos = pos->weiter;
        } while (pos != anfang);
    }
    printf("[%d %s]\n", anzahl, anzahl != 1 ? "Kinder" : "Kind");
}

/* zählt, beginnend bei dem über anfang erreichbaren Kind, bis zum
   anzahlSilben-ten Kind und entfernt dieses aus dem Kreis;
   zurückgegeben wird ein Zeiger auf seinen Nachfolger */
Knoten* auszaehlen(Knoten* anfang, unsigned int anzahlSilben)
{
    Knoten* pos = anfang; // ausgezähltes Kind
    Knoten* vorg = anfang; // dessen Vorgänger
    assert(anfang != nullptr); // auszählen nicht mit leerem Kreis aufrufen

    printf("Auszählen: ");

    // anzahlSilben - 1 Kinder übergehen
    for (unsigned int i = 1; i < anzahlSilben; i++)
    {
        printf("%s ", pos->name);
        vorg = pos;
        pos = pos->weiter;
    }

    // pos zeigt auf das ausgezählte Kind, vorg auf seinen Vorgänger im Kreis;
    // wenn nur noch ein Kind im Kreis ist, dann gilt vorg == pos == anfang
    printf("+%s ausgezählt\n", pos->name);

    vorg->weiter = pos->weiter; // im Falle vorg == pos keine Auswirkung
    free(pos);
    if (vorg == pos) // Kreis wird leer
        return nullptr;
    else
        return vorg->weiter;
}


int main(void)
{
    String name;
    Knoten* anfang = nullptr;  // Zeiger auf erstes Kind im Kinderkreis
    Knoten* ende = nullptr;    // Zeiger auf zuletzt eingefügtes Kind
    unsigned int anzahlSilben; // des Abzählreimes

    // Schleife zum Einlesen und Einfügen der Namen
    do
    {
        printf("Name („fertig“ für Ende): ");
        fgets(name, NAME_MAX, stdin);

        // '\n' entfernen falls vorhanden
        if (name[strlen(name) - 1] == '\n')
            name[strlen(name) - 1] = '\0';

        if (strcmp(name, "fertig") != 0) // weiteres Kind aufnehmen
        {
            if (anfang == nullptr) // erstes Kind im Kreis
            {
                anfang = zeigerAufNeuenKnoten(name, nullptr);
                ende = anfang;
                ende->weiter = anfang;
            }
            else
            {
                // schon Kinder im Kreis; am Ende einfügen
                ende->weiter = zeigerAufNeuenKnoten(name, anfang);
                ende = ende->weiter;
            }
        }
    } while (strcmp(name, "fertig") != 0);
}
