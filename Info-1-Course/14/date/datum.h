
// Datentyp Datum und Funktionen, Header-Datei
// Autor:   Holger Arndt, Andreas Frommer
// Version: 26.01.2022

#ifndef _DATUM_H
#define _DATUM_H

#include <stdbool.h>

// Struktur für Datums-Variablen
typedef struct
{
  int tag;
  int monat;
  int jahr;
} Datum;

extern const int stdJahr;    // Standardwert (bei Fehleingaben, 1970 in datum.c)
extern const int tageProMonat[12];  // Länge der einzelnen Monate (Februar = 28)

// Schaltjahr-Test
bool istSchaltjahr(int jahr);

// prüfe Datum auf Gültigkeit
void datumPruefen(Datum* d);

// erzeugt ein neues Datum und gibt es zurück
Datum datumNeu(int t, int m, int j);

// setzt alle Komponenten von d auf neue Werte
void datumSetze(Datum* d, int t, int m, int j);

// erhöht Datum um einen Tag
void datumNaechsterTag(Datum* d);

// Umwandlung in Zeichenkette, gibt Zeiger auf statischen Puffer zurück
const char* datumAlsString(const Datum* d);

// einlesen eines Datums
Datum datumLese(void);

#endif
