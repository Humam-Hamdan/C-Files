#include <stdio.h>

int quersumme(int n, int b)
{
  int q = 0;

  while (n != 0)
  {
    q += (n % b);
    n = n / b;
  }

  return q;
}