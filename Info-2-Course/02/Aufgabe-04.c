#include <stdio.h>

int quersumme(int n, int b){
  int q = 0;

  while (n != 0)
  {
    q += (n % b);
    n = n / b;
  }

  return q;
}

int main(void){
  int max = 1000000;
  for(int i = 1; i <= max; i++){
    int qs2 = quersumme(i, 2);
    int qs10 = quersumme(i, 10);
    if(qs2 == qs10){
      printf("%d erfüllt die Bedingung\n", i);
    }
  }
}
