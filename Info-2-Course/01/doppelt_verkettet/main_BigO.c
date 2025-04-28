#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "l_datentyp.h"
#include "dcl.h"

int main(void) {
    Liste l;
    dcl_create(&l);

    int sum = 0;

    // Input phase
    while (1) {
        int input_num;
        printf("Zahl eingeben: ");
        if (scanf("%d", &input_num) != 1) {
            fprintf(stderr, "Ungültige Eingabe!\n");
            exit(EXIT_FAILURE);
        }

        if (input_num == 0) break;

        sum += input_num;

        // Insert at the tail of the list (no traversal needed)
        dcl_insert(input_num, &l);
    }

    printf("Summe der Zahlen: %d\n", sum);

    // Output in reverse order
    printf("Zahlen in umgekehrter Reihenfolge:\n");
    dcl_reset(&l);
    while (l.tail != NULL) {  // Traverse from the tail
        l_datentyp_ausgeben(l.tail->l_daten);
        l.tail = l.tail->l_prev;
    }
    printf("\n");

    // Output in original order
    printf("Zahlen in urspruenglicher Reihenfolge:\n");
    dcl_reset(&l);
    while (!dcl_out_of_list(l)) {
        l_datentyp_ausgeben(l.pos->l_daten);
        dcl_advance(&l);
    }
    printf("\n");

    return 0;
}
