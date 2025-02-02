/************************************************/
/* Assessment II (06.12.2024)                   */
/* auto-generated .c file from text box input   */
/*                                              */
/* Humam Hamdan, 2427300                        */
/************************************************/

#include <stdio.h>

/*
int zaehler
Zeichen eingeesen
mit gechar die Zeichen nehmen
zu Vokale vergleichen

*/

int main(){
    char wort;
    printf("Gebe die Zeichen ein: ");
    scanf("%c",&wort);
    int zahlKleinVokal=0;
    while(!'\n'){
        char char_current;
        char_current = getchar(wort);
        if((char_current = 'i' || char_current = 'a' || char_current = 'e' || char_current = 'o' || char_current = 'u'))
            zahlKleinVokal++;
    }
    printf("Zahl der Vokale");
}