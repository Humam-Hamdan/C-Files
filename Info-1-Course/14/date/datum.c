
// Datentyp Datum und Funktionen, Implementierung
// Autor:   Andreas Frommer, Holger Arndt
// Version: 26.01.2022

#include <stdio.h>
#include "datum.h"

const int stdJahr = 1970;

const int tageProMonat[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


// Schaltjahr-Test
bool istSchaltjahr(int jahr)
{ return (jahr % 4 == 0 && jahr % 100 != 0) || jahr % 400 == 0; }

// prüfe Datum auf Gültigkeit
void datumPruefen(Datum* d);

// erzeugt ein neues Datum und gibt es zurück
Datum datumNeu(int t, int m, int j)
{
  Datum d = { t, m, j };
  datumPruefen(&d);
  return d;
}

// setzt alle Komponenten von d auf neue Werte
void datumSetze(Datum* d, int t, int m, int j)
{
  *d = (Datum){ t, m, j };
  datumPruefen(d);
}


void datumPruefen(Datum* d)
{
  if (d->jahr < 1 || d->jahr >= 10000 || d->monat < 1 || d->monat > 12
      || d->tag < 1 || (d->tag > tageProMonat[d->monat - 1]
          && !(d->tag == 29 && d->monat == 2 && istSchaltjahr(d->jahr))))
    {
      fprintf(stderr, "Ungültiges Datum korrigiert: %i.%i.%i\n", d->tag,
              d->monat, d->jahr);
      d->tag = d->monat = 1;
      d->jahr = stdJahr;
    }
}

void datumNaechsterTag(Datum* d)
{
  d->tag++;
  if (d->tag > tageProMonat[d->monat - 1]
      && !(d->tag == 29 && d->monat == 2 && istSchaltjahr(d->jahr)))
    {
      d->tag = 1;
      if (++d->monat == 13)
        {
          d->monat = 1;
          d->jahr++;
        }
    }
}

const char* datumAlsString(const Datum* d)
{
  /* statisches Feld, bleibt nach Ende der Funktion bestehen, so dass ein
     Zeiger darauf zurückgegeben werden kann                              */
  static char datStrPuffer[11];
  sprintf(datStrPuffer, "%02i.%02i.%4i", d->tag, d->monat, d->jahr);
  return datStrPuffer;
}

Datum datumLese(void)
{
  int t, m, j;
  scanf("%d.%d.%d", &t, &m, &j);
  return datumNeu(t, m, j);
}
