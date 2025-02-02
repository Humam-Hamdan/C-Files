#include <stdbool.h>

#ifndef _DATUM_H
#define _DATUM_H

// Struktur für Datums-Variablen
typedef struct
{
    int tag;
    int monat;
    int jahr;
} Datum;

extern const int stdJahr; // Standardwert (bei Fehleingaben, 1970 in datum.c)
extern const int tageProMonat[12]; // Länge der einzelnen Monate (Februar = 28)

// Schaltjahr-Test
static inline bool istSchaltjahr(int jahr)
{ return (jahr % 4 == 0 && jahr % 100 != 0) || jahr % 400 == 0; }

// prüfe Datum auf Gültigkeit
void datumPruefen(Datum* d);

// erzeugt ein neues Datum und gibt es zurück
static inline Datum datumNeu(int t, int m, int j)
{
    Datum d = { t, m, j };
    datumPruefen(&d);
    return d;
}

// setzt alle Komponenten von d auf neue Werte
static inline void datumSetze(Datum* d, int t, int m, int j)
{
    *d = (Datum){ t, m, j };
    datumPruefen(d);
}

// erhöht Datum um einen Tag
void datumNaechsterTag(Datum* d);

// Umwandlung in Zeichenkette, gibt Zeiger auf statischen Puffer zurück
const char* datumAlsString(const Datum* d);

// einlesen eines Datums
Datum datumLese();

#endif
