/****************************************************/
/* Programm zur Vorlesung Algorithmen und Datenstr. */
/* Andreas Frommer, 13.4.00                         */
/* Aktualisiert: Bruno Lang, 2003/03/26,            */
/*    2004/04/16, 2005/04/20, 2020/03/26            */
/*    Andreas Frommer, 2025/04/13                   */
/*    (moeglichst nahe am Algorithmus der Vorlesung */
/*     es wird nur der naechste Zug ausgerechnet)   */
/*                                                  */
/* Dieses Programm bestimmt den besten Zug fuer den */
/* Rechner im  NIM-Spiel.                           */             
/*                                                  */
/* Regeln fuer NIM:                                 */
/*   - zu Beginn liegen h Hoelzchen auf einem       */
/*     Haufen (z.B. h = 21)                         */
/*   - Gegner und Rechner nehmen abwechselnd jeweils*/
/*     1 bis 3 Hoelzchen vom Haufen                 */
/*   - verloren hat, wer das letzte Hoelzchen       */
/*     nehmen muss                                  */
/*                                                  */
/* Algorithmisches Prinzip: Exhaustive search       */
/****************************************************/

#include "nimzug_exhaustive.h"
/* stellt Konstante           MAX_ZUG bereit        */

/* ------------------------------------------------ */

bool gewinnposition(int h, int z) {
   int z1;  // heisst z_tilde im Skript
   if (h == 0) 
      return true;   // Der Gegner hat verloren
   if (( h-z) == 0)  // Ich habe verloren
      return false;
   // jetzt ist h > z
   for (z1 =1; (z1 <= MAX_ZUG) && (z1 <= h); z1++) {
      if ( gewinnposition(h-z, z1) )  // Rekursion
         /* Der Gegner kann gewinnen, wenn er das  */
         /* richtige z1 waehlt                     */
         return false;
      
   }
   return true;  /* der Gegner verliert (wenn ich  */
                 /* alle weiteren Zuege richtig    */
                 /* waehle)                */
}   

int bester_zug(int h) {
   int z;
   for (z =1; (z <= MAX_ZUG) && (z <= h) ; z++)
      if  (gewinnposition(h,z))
         return z;  // Zug fuehrt zum Gewinn
   return 1;        // auf Fehler des Gegners hoffen
}

      


