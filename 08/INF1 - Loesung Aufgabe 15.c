/**************************************/
/* Humam Hamdan                       */
/* Gruppe: Do.12                      */
/* Leiter: Florian Möschler           */
/* Uebungsblatt:     8                 */
/* Aufgabe:       15                    */
/* Datum:     22 Dez                        */
/**************************************/

/*
funk char x
    y = char(x)
    printf(y)

int main
    char = x
    printf
    scanf
    BreakCondition = \n
    while !BreakCondition{
        char(x)
    }

}
*/

#include <stdio.h> 
#include <stdbool.h>

void reverseInput() {

    int ch = getchar(); 
    bool BreakCondition = (ch != '\n');

    if (BreakCondition) {
        reverseInput(); 
        printf("%c",ch);
        // recursion before pritnf sothat the last char is printed first, otherwise the printf before recursion 
    }
}

int main() {

    printf("Geben Sie einen Satz ein: ");
    reverseInput(); 
    printf("\n");

    return 0;
}
