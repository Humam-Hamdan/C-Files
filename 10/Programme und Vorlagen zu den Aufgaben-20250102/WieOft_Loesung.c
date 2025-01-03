// Zaehlen, wie oft Buchstaben in einem Text vorkommen  
// Andreas Frommer, 19.12.2024
// nach Vorlesung noch "geglättet"
// Pseudocode: 
// Verwende ein Feld von Zählern
// Lese das nächste Zeichen
//     falls das Zeichen ein Buchstaben ist
//        erhöhe den Zähler, der zu diesem Zeichen gehört, um eins (1)
//     sonst 
//         erhöhe den Zähler für den "Rest" auf 
// bis das Ende der Eingabe erreicht ist
// (1) Alle Buchstaben werden nach "klein" konvertiert;
//     die Stelle des Zählers im Feld errechnen wir durch Durchlaufen des Alphabets
#include <stdio.h>
#include <ctype.h>


char alphabet[] = "abcdefghijklmnopqrstuvwxyz"; //hat 26 Zeichen + \0

int zaehlerposition( char c) {
     int i = 0;
    c = tolower(c);
    while (c != alphabet[i] && (alphabet[i] != '\0') )
        i++;
  // jetzt ist i die Position in alphabet, falls c ein Buchstabe ist, andernfalls ist i = LAENGE
  // printf("Zeichen %c, Nummer %d\n", c,i);
  return i;
}

int main() {
    
   enum {LAENGE = 26}; 

   int gesamt;
   char c;
   int zaehler[LAENGE+1];
  
   for (int i = 0; i<= LAENGE; i++)
      zaehler[i]  = 0;
  
   while ( (c = getchar()) != EOF) {
       // if (isalpha(c)) 
           zaehler[zaehlerposition(tolower(c))]++;
       // else  //kein Buchstaben
       //    zaehler[LAENGE]++;
       gesamt++;
   }
  
   for (int i=0; i<LAENGE; i++)
       printf("Der Buchstabe %c kommt %d mal vor, das sind %f%%\n", alphabet[i], zaehler[i],  (100.0*zaehler[i]) /  gesamt);
   printf("Andere Zeichen kommen %d mal vor, das sind %f%%\n", zaehler[LAENGE], (100.0*zaehler[LAENGE]) / gesamt);
    
}
