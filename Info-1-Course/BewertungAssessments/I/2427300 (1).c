/************************************************/
/* Assessment I (08.11.2024)                    */
/* auto-generated .c file from text box input   */
/*                                              */
/* Humam Hamdan, 2427300                        */
/************************************************/

#include <stdio.h>

// Berechnung der Brutto mit Eingabe von Steuer und 

int main(void)
{
    // Eingaben
    float betrag, end_betrag, steuer;//+2P

    // Betrag Eingeben und Lesen
    printf("Bitte geben Sie einen Nettopreis ein: ");
    scanf("%f", &betrag);//+1P

    // Steuer Eingeben und Lesen
    printf("Bitte geben Sie einen Steuersatz ein: ");//+1P
    scanf("%f", &steuer);//+1P

    // Zwischenrechnung
    end_betrag = betrag*(1+ (steuer / 100));//+1P

    // Ausgabe
    printf("Der Bruttopreis beträgt %.2f Euro\n", end_betrag);//+1P
    
}//+3P

// 10/10P ~FM