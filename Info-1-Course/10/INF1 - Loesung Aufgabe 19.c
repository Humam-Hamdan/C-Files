/**************************************/
/* Humam Hamdan                       */
/* Gruppe: Do.12                      */
/* Leiter: Florian Möschler           */
/* Uebungsblatt:  10                  */
/* Aufgabe:      19                   */
/* Datum:       3 jan                 */
/**************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool the_same(char new[], char old[]){

    return strcmp(new,old) == 0;
}

void replace(char new[], char old[], char whole[]){

    int len = strlen(old);  // Since old and new are assumed to be the same length
    char *pos = whole;

    while (*pos != '\0') {
        int match = 1;  // Reset match for each position

        // Check if old matches the current position
        for (int i = 0; i < len; i++) {
            if (pos[i] != old[i]) {
                match = 0;
                break;
            }
        }

        // If a match is found, replace old with new
        if (match) {
            // Copy `new` into position manually
            for (int i = 0; i < len; i++) {
                pos[i] = new[i];
            }

            pos += len;  // Move past the replaced segment
        } 
        else {
            pos++;  // Move forward if no match
        }
    }
    // mithilfe von gpt 
}

int main(){

    char old[20], new[20], whole[200];

    printf("Input NEW String: \n");
    scanf("%s", new);
    printf("Input OLD String: \n");
    scanf("%s", old);
    printf("Input Whole String: \n");
    scanf("%s", whole);

    replace(new,old,whole);

    printf("%s\n", whole);

    return 0;
}
