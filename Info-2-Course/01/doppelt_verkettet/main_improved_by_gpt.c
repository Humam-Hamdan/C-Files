
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "l_datentyp.h"  // für L_datentyp
#include "dcl.h"         // für Listenoperationen

int main(void)
{
    Liste l;
    dcl_create(&l);

    int sum = 0;

    // Eingabephase
    while (1) {
        int input_num;
        printf("Zahl eingeben: ");
        if (scanf("%d", &input_num) != 1) {
            fprintf(stderr, "Ungültige Eingabe!\n");
            exit(EXIT_FAILURE);
        }

        if (input_num == 0) break;

        sum += input_num;

        // Zum Listenende gehen, um dort einzufügen
        dcl_reset(&l);
        while (!dcl_out_of_list(l)) {
            dcl_advance(&l);
        }

        dcl_insert(input_num, &l);
    }

    printf("Summe der Zahlen: %d\n", sum);

    // Umgekehrte Reihenfolge ausgeben
    printf("Zahlen in umgekehrter Reihenfolge:\n");
    dcl_reset(&l);
    while (!dcl_out_of_list(l)) {
        dcl_advance(&l);
    }
    while (l.pos_vorg != NULL) {
        l_datentyp_ausgeben(l.pos_vorg->l_daten);
        l.pos = l.pos_vorg;
        l.pos_vorg = l.pos_vorg->l_prev;
    }
    printf("\n");

    // Ursprüngliche Reihenfolge ausgeben
    printf("Zahlen in ursprünglicher Reihenfolge:\n");
    dcl_reset(&l);
    while (!dcl_out_of_list(l)) {
        l_datentyp_ausgeben(l.pos->l_daten);
        dcl_advance(&l);
    }
    printf("\n");

    return 0;
}
