/****************************************************/
/* Programm zur Vorlesung Algorithmen und Datenstr. */
/* Andreas Frommer, 13.4.25                         */ 
/*                                                  */
/* Dialog zu einem NIM-Spiel zwschen Rechner und    */
/*   und einer Person                               */
/*                                                  */
/* Der Rechner macht immer den besten Zug           */
/*                                                  */
/* Dieses Programm bestimmt die besten Zuege im     */
/* NIM-Spiel gegen einen Gegner.                    */
/* Es wird angenommen, dass der Gegner ("Weiss")    */
/* zuerst zieht, dann der Computer ("Schwarz").     */
/*                                                  */
/* Regeln fuer NIM:                                 */
/*   - zu Beginn liegen h Hoelzchen auf einem       */
/*     Haufen (z.B. h = 21)                         */
/*   - Rechner und Gegner nehmen abwechselnd jeweils*/
/*     1 bis 3 Hoelzchen vom Haufen                 */
/*   - verloren hat, wer das letzte Hoelzchen       */
/*     nehmen muss                                  */
/*                                                  */
/* Algorithmisches Prinzip: Exhaustive search       */
/****************************************************/

#include <stdio.h>
#include "nimzug_exhaustive.h" 
                 //deklariert die Funktion bester_zug 
                 //vereinbart MAX_ZUG

int zug_einlesen(int h){ /* liest naechsten erlaubten 
                             Zug (des Gegners) ein  */ 
   int zug;
   
   printf("Wieviele Hoelzchen nimmst Du?\n");
   scanf("%d",&zug);
   
   while ( (zug > 3) || (zug < 0) || (zug > h) )  
   {
      printf("Nicht erlaubt. Bitte neu eingeben\n");
      scanf("%d",&zug);
   }
   return zug;
}

/* ------------------------------------------------ */

/* Hauptprogramm */

int main( void )
{
   int anf;                  /* Wer darf anfangen?  */  
   int h ;                      /* Anzahl Hoelzchen */
   int zug_rechner, zug_gegner;  
                      /* gerade durchgefuehrter Zug */

   printf( "Anzahl der Hoelzchen zu Beginn : " ) ;
   scanf( "%d", &h ) ;  
   
   printf("Wer darf anfangen?\n");
   printf("0: Mensch (Du)\n");
   printf("1: Rechner\n");
   scanf("%d", &anf);
   
   if (!anf) {
      zug_gegner = zug_einlesen(h); 
      h = h-zug_gegner;
   }
      
   while (h > 0) {
      printf("Es sind noch %d Hoelzchen uebrig\n",h);
      zug_rechner = bester_zug(h);
      printf("Ich nehme %d Hoelzchen, ", zug_rechner);
      printf("bleiben %d\n", h-zug_rechner);
      h = h -zug_rechner;
      if ( h == 0) 
         printf("Ich habe verloren\n");
      else {
         zug_gegner = zug_einlesen(h);
         h = h - zug_gegner;
         if (h == 0) 
            printf("Du hast verloren\n");
      }
   }
   return 0 ;
}
