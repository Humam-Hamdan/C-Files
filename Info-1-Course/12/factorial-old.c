
// Fakultät mit Funktion
// Autor:   Bruno Lang, Holger Arndt
// Version: 28.07.2017
#include <stdio.h>

// fakultaet() – Liefert die Fakultät der Zahl n,
//    n! = 1 · 2 · … · (n − 1) · n,
// zurück. Dabei ist 0! = 1.
int fakultaet(int n)
{
  int i;                     // durchläuft die Zahlen 1, …, n
  int produkt;                  // Produkt der Zahlen 1, …, i

  produkt = 1;

  i = 1;               // aufmultiplizieren in einer Schleife
  while (i <= n)
    {
      produkt = produkt * i;
      i = i + 1;
    }

  return produkt;
}

// Hauptfunktion – Liest eine Zahl ein und gibt ihre
// Fakultät aus
int main(void)
{
  int zahl, f;

  printf("Nichtnegative ganze Zahl eingeben: ");
  scanf("%d", &zahl);

  f = fakultaet(zahl);
  printf("Fakultät = %d\n", f);
}
