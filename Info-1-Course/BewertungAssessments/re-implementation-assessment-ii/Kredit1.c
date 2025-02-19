// Kreditberechnung
// Autor:   Bruno Lang, Holger Arndt
// Version: 28.07.2017
#include <stdio.h>

// Funktion monatszinsen(k, p) liefert
// die beim angegebenen (Jahres-)Zinssatz von p Prozent für
// den Kreditbetrag k monatlich zu zahlenden Zinsen zurück.
float monatszinsen(float k, float p)
{
  float zinsen;

  zinsen = k * (p / 100.0 / 12);

  return zinsen;
}

// Hauptfunktion: Liest die Daten des Kredits ein und gibt
// für die gesamte Laufzeit den Stand am Monatsende aus
int main(void)
{
  float kreditbetrag, zinssatz, rate;
  int laufzeit, monat;

  printf("Kreditbetrag (in Euro) eingeben: ");
  scanf("%f", &kreditbetrag);
  printf("Zinssatz (in Prozent) eingeben: ");
  scanf("%f", &zinssatz);
  printf("Laufzeit (in Monaten) eingeben: ");
  scanf("%d", &laufzeit);
  printf("Monatliche Rate (in Euro) eingeben: ");
  scanf("%f", &rate);

  monat = 1;
  while (monat <= laufzeit)
    {
      kreditbetrag = kreditbetrag + monatszinsen(kreditbetrag, zinssatz) - rate;
      printf("Kreditbetrag nach %2d Monaten: %.2f Euro\n", monat, kreditbetrag);
      monat = monat + 1;
    }
}
