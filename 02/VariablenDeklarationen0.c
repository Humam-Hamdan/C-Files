// Beispiele zu Variablen-Deklarationen
// Autor:   Bruno Lang, Holger Arndt
// Version: 28.07.2017
#include <stdio.h>

int main(void)
{
  double a = 1.5 * 42 * 42;  // mit Anfangswert: a == 2646.0
  int m;                     // nicht initialisiert: m == ?

  printf("a = %f\n", a);     // Ausgabe 2646.000000
  printf("m = %d\n", m);     // zufälliger Wert!
}
