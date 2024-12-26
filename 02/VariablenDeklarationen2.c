// Beispiele zu Variablen-Deklarationen und Verdeckung in Blöcken
// Autor:   Bruno Lang, Holger Arndt
// Version: 28.07.2017
#include <stdio.h>

int a = 3, b = 3;               // globale Variablen

int main(void)
{
  int a = 7;                    // verdeckt globales a
  printf("Zeile 11: a = %d, b = %d\n", a, b);

  {
    int a = 11, b = 11;         // verdeckt globales b und a aus Zeile 10
    printf("Zeile 15: a = %d, b = %d\n", a, b);
  }

  // a und b aus Zeile 14 sind nicht mehr gültig;
  // a aus Zeile 10 und globales b sichtbar
  printf("Zeile 20: a = %d, b = %d\n", a, b);

  {
    int b = 21;                 // verdeckt globales b
    printf("Zeile 24: a = %d, b = %d\n", a, b);
    {
      int b = 42219;            // verdeckt globales b und b aus Zeile 23
      printf("Zeile 27: a = %d, b = %d\n", a, b);
      int a = 42097;            // verdeckt globales a und a aus Zeile 10 (C99!)
      printf("Zeile 29: a = %d, b = %d\n", a, b);
    }
  }
}
