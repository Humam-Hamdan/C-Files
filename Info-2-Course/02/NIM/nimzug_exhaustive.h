/****************************************************/
/* Vorlesung Algorithmen und Datenstrukturen        */
/* Andreas Frommer, 2025/04/14/                     */
/*                                                  */
/* Dieses Header-File stellt die Berechnung des     */
/* besten Zugs (per exhaustive search) im NIM-Spiel */
/* bereit                                           */
/****************************************************/

#ifndef NIMZUG_EXHAUSTIVE_H
   #define NIMZUG_EXHAUSTIVE_H

   #include <stdbool.h>
   #include <stdio.h>

   #define MAX_ZUG 3  /* So viele Hoelzchen darf man*/
                     /*   maximal nehmen            */

   int bester_zug( int h ); 
   bool gewinnposition( int h, int z);
#endif
