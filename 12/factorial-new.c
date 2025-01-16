
// Fakultätsberechnung und Langzahlarithmetik mit Liste von Ziffern
// Autor:   Bruno Lang, Holger Arndt
// Version: 28.07.2017
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* Die Konstanten M_PI und M_E stehen bei gängigen Compilern in math.h,
   gehören aber nicht offiziell zum C-Standard.
   Daher zur Sicherheit die folgenden Definitionen                      */
#ifndef M_PI
const double M_PI = 3.14159265358979323846;
#endif
#ifndef M_E
const double M_E = 2.7182818284590452354;
#endif

// Basis für Langzahldarstellung
enum { BASIS = 10 };
// Oberschranke für n
enum { MAX_N = 150 };
// welche Werte n! werden ausgegeben?
enum { SCHRITT_N = 1 };

// Knoten enthält eine Ziffer der Zahl
typedef struct Knoten
{
  unsigned int ziffer;
  struct Knoten* rest;
} Knoten;

// natürliche Zahl = Liste von Ziffern
typedef Knoten* NatZahl;

// Ausgabe einer natürlichen Zahl, ziffernweise VON VORNE
void natAusgeben(NatZahl a)
{
  // wenn es noch Ziffern vor der letzten gibt, dann diese zuerst ausgeben (Rekursion!)
  if (a->rest != NULL)
    natAusgeben(a->rest);
  // letzte Ziffer ausgeben
  printf("%u", a->ziffer);
}

/* erzeuge einen neuen Knoten und lege darin die Ziffer z und den
   „Rest“zeiger r ab; liefere einen Zeiger auf den neuen Knoten zurück.
   Abbruch, wenn kein Speicherplatz verfügbar war.                      */
Knoten* zeigerAufNeueZiffer(unsigned int z, Knoten* r)
{
  Knoten* neu = malloc(sizeof(Knoten));                      // Speicher belegen
  if (neu == NULL)
    {
      printf("### Programmabbruch, da Speicheranforderung in zeigerAufNeueZiffer fehlschlug!\n");
      exit(EXIT_FAILURE);
    }
  neu->ziffer = z;
  neu->rest = r;

  return neu;
}

/* Multiplikation einer natürlichen Zahl a mit einer int-Zahl n
   (ziffernweise VON HINTEN)                                    */
void multipliziere(NatZahl a, unsigned long n)
{
  unsigned long tmp, uebertrag = 0;
  Knoten* aktZiffer = a;                              // Zeiger auf Ziffer von a
  Knoten* ersteZiffer;

  // ziffernweise mit n multiplizieren
  while (aktZiffer != NULL)
    {
      tmp = n * aktZiffer->ziffer + uebertrag;
      aktZiffer->ziffer = tmp % BASIS;
      uebertrag = tmp / BASIS;
      ersteZiffer = aktZiffer;
      aktZiffer = aktZiffer->rest; // ersteZiffer zeigt auf „eine Ziffer hinter aktZiffer“
    }
  // ersteZiffer zeigt nun auf die erste Ziffer in der bisherigen Liste a

  // Zahl verlängern: Übertrag abarbeiten
  while (uebertrag != 0)
    {
      // Platz für neue Ziffer schaffen und Ziffer eintragen
      ersteZiffer->rest = zeigerAufNeueZiffer(uebertrag % BASIS, NULL);
      uebertrag /= BASIS;
      ersteZiffer = ersteZiffer->rest;
    }
}

/* Fakultäten der Zahlen 1, …, MAX_N berechnen und jeden SCHRITT_N-ten Wert
   ausgeben                                                                 */
int main(void)
{
  // Platz für einziffrige Zahl schaffen
  NatZahl fak = zeigerAufNeueZiffer(1, NULL);

  for (unsigned long n = 1; n <= MAX_N; n++)
    {
      multipliziere(fak, n);
      if (n % SCHRITT_N == 0)
        {
          printf("%4lu! = ", n);
          natAusgeben(fak);
          putchar('\n');
          printf("     (Stirlingsche Formel: %e)\n",
                 pow(n / M_E, n) * sqrt(2 * M_PI * n));
        }
    }
}
