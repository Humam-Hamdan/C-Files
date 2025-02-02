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
    printf("Gebe die Zeichen ein: ");//+1P
    scanf("%c",&wort);//unnötig
    int zahlKleinVokal=0;//+1P
    while(!'\n'){//+2P //Abbruch Bedingung falsch wort!='\n'
        char char_current;
        char_current = getchar(wort); //wort = getchar();
        if((char_current = 'i' || char_current = 'a' || char_current = 'e' || char_current = 'o' || char_current = 'u'))//+0,5P wort=='a' || ...
            zahlKleinVokal++;
    }
    printf("Zahl der Vokale");// Anzahl der Vokale in der Ausgabe fehlt
}//+1P
//5,5/10P