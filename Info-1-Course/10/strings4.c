// stdin bis zum Ende lesen und laengste Zeile ausgeben
// Autor:   Bruno Lang, Holger Arndt
// Version: 16.04.2018
#include <stddef.h>
#include <stdio.h>
#include <string.h>

enum { MAX_LINE = 1000 };      // maximale Zeilenlaenge

// Das ist die laengste Zeile in diesem Programm; sie sollte ausgegeben werden

int main(void)
{
  char aktZeile[MAX_LINE];          // aktuell eingelesene Zeile
  char maxZeile[MAX_LINE];          // laengste bisher betrachtete Zeile
  unsigned long int maxLaenge = 0;  // bisherige Maximallaenge

  while (fgets(aktZeile, MAX_LINE, stdin) != NULL)
    // bei Datei-Ende liefert fgets() einen NULL-Zeiger
    if (strlen(aktZeile) > maxLaenge)
      {
        // neue laengste Zeile gefunden
        maxLaenge = strlen(aktZeile);
        strcpy(maxZeile, aktZeile);
      }

  if (maxLaenge > 0)                // es wurde mindestens eine Zeile gelesen
    printf("%s", maxZeile);
}

