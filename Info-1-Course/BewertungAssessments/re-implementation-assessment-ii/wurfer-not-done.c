
/*
we need a random function

break condition = 100+ point

only one at a time plays

variable for round-wins which resets each round

if random => 3 then
case 1,2 
1= ends round and adds points
2= re-random and continue

else
var-wins = 0 and the round is ended

computer: if var-wins <= 8 or if var-wins+points <= 100

---
a do while the main condition and from there we work ig? till 2moro anyways.

make a pseudocode step by step, how it works aso.
*/


// Würfelspiel, Vorlage
// Version: 07.11.24

#include <stdbool.h> // seit C23 nicht mehr nötig; gcc auf JuyterHub ist noch zu alt
#include <stddef.h> // für NULL (wird auch in stdio.h definiert)
#include <stdio.h>
#include <stdlib.h> // für srand(), rand()
#include <time.h> //für time()

int main(void)
{
  srand(time(NULL)); // Initialisierung des Zufallszahlengenerators
  int punkteM = 0, punkteC = 0; // aktueller Punktestand beider Spieler
  int gewuerfelt;


  bool zugMensch = true; // als erstes ist der menschliche Spieler am Zug

  // ...

  gewuerfelt = rand() % 6 + 1; // Zufallszahl zwischen 1 und 6

  // ...

  zugMensch = !zugMensch; // Wechsel des Spielers, ! steht für Negation (vertauscht true und false)

  // ...

  if (punkteM > punkteC)
    printf("Sie haben gewonnen.\n");
  else if (punkteC > punkteM)
    printf("Der Computer hat gewonnen.\n");
  else
    printf("Das Spiel endete unentschieden.\n");
}
