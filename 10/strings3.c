// stdin bis zum Ende lesen und Zeilen zählen
// Autor:   Bruno Lang, Holger Arndt
// Version: 28.07.2017
#include <stdio.h>

int main(void)
{
  int c, zeilen = 0;

  while ((c = getchar()) != EOF)
    if (c == '\n')
      zeilen++;

  printf("Zeilenzahl: %d\n", zeilen);
}

