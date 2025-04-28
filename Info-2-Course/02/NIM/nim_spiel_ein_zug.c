/*****************************************************/
/* Programm zur Vorlesung Algorithmen und Datenstr.  */
/* Andreas Frommer, 13.4.25                          */
/* Fuehrt einen Zug des NIM-Spiels (fuer den Rechner)*/
/* aus                                               */
/*****************************************************/

#include <stdio.h>
#include <stdbool.h>
#include "nimzug_exhaustive.h"
/* stellt Konstante MAX_ZUG  und                    */
/* Funktionen bester_zug, gewinnposition bereit     */


/* Hauptprogramm */

int main( void )
{
   /* Der Rechner ist am Zug und fuehrt den
                       bestmoeglichsten Zug aus     */
   
   int h ; /* Anzahl der noch vorhandenen Hoelzchen */
   int zug ;          /* gerade durchgefuehrter Zug */

   printf( "Anzahl Hoelzchen eingeben: " ) ;
   scanf( "%d", &h ) ;
   
   zug = bester_zug(h);
   
   printf("Ich nehme %d Hoelzchen\n",zug);
   
   // optional, arroganter Rechner
   if ( gewinnposition(h,zug) )
      printf("Uebrigens: Ich gewinne\n");
      
   return 0 ;
}
