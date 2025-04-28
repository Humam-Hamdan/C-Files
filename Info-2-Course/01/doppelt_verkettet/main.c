/****************************************************/
/* Rahmenprogramm				  . */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "l_datentyp.h"          /* fuer L_datentyp */
#include "dcl.h"        /* fuer Listenoperationen */

/* ------------------------------------------------ */

/* Hauptprogramm zum Testen der Listenoperationen */

int main( void )
{
   Liste l;
   dcl_create( &l );
   
/***********************************************************/   

   bool app_on = true;
   int sum = 0;
   int counter = 0;
   while(app_on){
      int input_num;
      printf("Zahl eingeben: ");
      scanf("%d", &input_num);
      sum += input_num;
      counter += 1;
      if(!input_num == 0){
         dcl_insert(input_num, &l);
      }
      else{
         app_on = false;
         counter-= 1;
      }
   }
   printf("Summe der Zahlen: %d\n", sum);

   dcl_reset(&l);
   printf("Zahlen in umgekehrter Reiehenfolge: \n ");

   while(!(dcl_out_of_list(l))){
      dcl_advance(&l);
   }
   for(int i = counter; i > 0; i--){
      dcl_retract(&l);
      l_datentyp_ausgeben(l.pos->l_daten);
   }

   printf("\n");

   dcl_reset(&l);
   printf("Zahlen in ursprünglicher Reihenfolge: \n");
   for(int i = 0; i < counter; i++){
      l_datentyp_ausgeben(l.pos->l_daten);
      dcl_advance(&l);
   }

   printf("\n");


/***********************************************************/   

  return 0 ;
}
