#include <stdio.h>

void tu_was_mit_feld(int feld[], int laenge) {
    int temp;
    for (int i= 0; i<= laenge/2; i++) {
        temp = feld[i];
        feld[i] = feld[laenge-1-i];
        feld[laenge-1-i] = temp;
    }
}

int main(void) {
   enum {LAENGE = 5};
   int feld[LAENGE];
   for (int i=0; i< LAENGE; i++)
       feld[i] = 2*i+1;
   printf("Zeile 1: %p\n",feld);
   printf("Zeile 2: ");
   for (int i=0; i < LAENGE; i++)
       printf("%d ", feld[i]);
   printf("\n");
   
   tu_was_mit_feld(feld, LAENGE);
   
   printf("Zeile 3: %p\n",feld);
   printf("Zeile 4: ");
   for (int i=0; i < LAENGE; i++)
       printf("%d ",  feld[i]);
}
