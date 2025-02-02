/**************************************/
/* Humam Hamdan                       */
/* Gruppe: Do.12                      */
/* Leiter: Florian Möschler           */
/* Uebungsblatt:10                    */
/* Aufgabe:20                         */
/* Datum: 5 Jan                       */
/**************************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char bstsalat[10][10] = {{'a', 'r', 'r', 'a', 'y', 'i', 'p', 'o', 'u', 't'},
                             {'r', 'l', 'm', 'p', 'y', 'u', 'o', 'b', 'u', 'n'},
                             {'s', 't', 'r', 'i', 'n', 'g', 'i', 'l', 'w', 'l'},
                             {'x', 'o', 'x', 'n', 't', 'o', 'n', 'a', 'h', 's'},
                             {'u', 'v', 'w', 't', 'o', 'l', 't', 's', 'i', 't'},
                             {'r', 'e', 't', 'u', 'r', 'n', 'e', 'u', 'l', 'w'},
                             {'b', 'z', 'a', 'z', 'y', 'e', 'r', 'm', 'e', 's'},
                             {'f', 'u', 'l','c', 'z', 'i', 'o', 'r', 't', 'u'},
                             {'o', 'a', 'm', 'k', 'd', 'o', 'u', 'b', 'l', 'e'},
                             {'r', 'f', 'u', 'w', 'z', 'x', 'd', 'd', 'x', 'y'}};

    char word[20];
    printf("Enter the word to search: ");
    scanf("%s", word);

    int len = strlen(word);
    int found = 0;

    // Search horizontally (left to right)
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col <= 10 - len; col++) {
            int match = 1;
            for (int k = 0; k < len; k++) {
                if (bstsalat[row][col + k] != word[k]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("Found '%s' horizontally from (%d,%d) to (%d,%d)\n", word, row, col, row, col + len - 1);
                found = 1;
            }
        }
    }

    // Search vertically (top to bottom)
    for (int col = 0; col < 10; col++) {
        for (int row = 0; row <= 10 - len; row++) {
            int match = 1;
            for (int k = 0; k < len; k++) {
                if (bstsalat[row + k][col] != word[k]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("Found '%s' vertically from (%d,%d) to (%d,%d)\n", word, row, col, row + len - 1, col);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("Word '%s' not found in the puzzle.\n", word);
    }

    return 0;
}
