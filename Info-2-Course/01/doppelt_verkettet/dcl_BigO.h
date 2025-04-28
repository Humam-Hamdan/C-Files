
#ifndef LISTE_H
   #define LISTE_H

   #include <stdbool.h>
   #include "l_datentyp.h"  // for L_datentyp

   // List node structure
   typedef struct dcl_knoten {
      L_datentyp l_daten;
      struct dcl_knoten *l_next;
      struct dcl_knoten *l_prev;
   } DCL_knoten;

   // List structure with tail pointer added
   typedef struct {
     DCL_knoten *anf;    // Head pointer
     DCL_knoten *tail;   // Tail pointer (new)
     DCL_knoten *pos;    // Current position
     DCL_knoten *pos_vorg; // Previous position
   } Liste;

   // Function declarations
   void dcl_create(Liste *l);
   void dcl_insert(L_datentyp e, Liste *l);
   void dcl_delete(Liste *l, L_datentyp *e);
   void dcl_reset(Liste *l);
   void dcl_advance(Liste *l);
   bool dcl_out_of_list(Liste l);
   void dcl_retract(Liste *l);

#endif
