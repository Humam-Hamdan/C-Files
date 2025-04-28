
#include <stdio.h>
#include <stdlib.h>
#include "l_datentyp.h"
#include "dcl.h"

// Initialize the list
void dcl_create(Liste *l) {
    l->anf = NULL;
    l->tail = NULL;  // Initialize tail as NULL
    l->pos = NULL;
    l->pos_vorg = NULL;
}

// Insert a new element at the end of the list
void dcl_insert(L_datentyp e, Liste *l) {
    // Allocate memory for a new node
    DCL_knoten *neu = (DCL_knoten *)malloc(sizeof(DCL_knoten));
    if (neu == NULL) {
        printf("Fehler: Kein Speicher mehr!\n");
        exit(EXIT_FAILURE);
    }

    // Set data and initialize pointers
    neu->l_daten = e;
    neu->l_next = NULL;
    neu->l_prev = l->tail;  // New node's previous pointer points to current tail

    if (l->tail != NULL) {
        l->tail->l_next = neu;  // Update current tail's next pointer to new node
    } else {
        l->anf = neu;  // If the list was empty, set both head and tail to the new node
    }

    l->tail = neu;  // Update the tail pointer to the new node
}

// Other functions remain the same...

