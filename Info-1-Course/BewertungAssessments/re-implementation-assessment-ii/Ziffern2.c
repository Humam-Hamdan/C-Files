// bestimmt die Darstellung der Zahl k zur Basis b und gibt sie (in der richtigen Reihenfolge) aus.
// Idee: Erst die Wertigkeit b^stelle der vordersten Stelle bestimmen (A)
// Die Ziffer ergibt sich aus der integer Division mit b^stelle
// das Vorgehen wird mit dem Rest der integer Division und der Wertigkeit der nächsten 
// kleineren Stelle wiederholt solange bis 0 erreicht wird
// zu A: Wir bestimmen das kleinste n mit b^{n-1} <= k < b^n (denn dann hat k in Basis b die 
// Darstellung k = z_{n-1}z_{n-2}...z_0 mit z_{n-1} > 0.
//
// Andreas Frommer, 31.10.2024

#include <stdio.h>

int k, q, r;
int stelle, wert;
int b;    

int main() {
    
   printf("Zahl eingeben: \n");
   scanf("%d",&k);
   
   printf("Basis eingeben: \n");
   scanf("%d",&b);
   
    
  //zuerst wert der vordersten Stelle bestimmen
  stelle = 0; wert = 1; 
  while (k/wert > 0) { // k >= wert;
     wert = wert*b;   
     stelle = stelle+1;  // hier gilt: wert =b^stelle 
  }
  // jetzt ist k < wert = b^stelle aber k >= b^{stelle-1}
  // stelle ist also 1 zu weit gezählt
  
  stelle = stelle-1;
  wert = wert/b;
  
  printf("\nDie Darstelung von %d zur Basis %d ist ",k,b); 

  for (int i=stelle; i>=0; i=i-1)  {
     q = k/wert;
     printf("%X",q);   // %X liefert richtige Ziffern bis Basis 16 (A,B...,F) 
     k = k%wert;
     wert = wert/b;
  }
printf("\n");

}
