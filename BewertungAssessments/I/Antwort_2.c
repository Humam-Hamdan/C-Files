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
    float betrag, end_betrag, steuer;

    // Betrag Eingeben und Lesen
    printf("Bitte geben Sie einen Nettopreis ein: ");
    scanf("%f", &betrag);

    // Steuer Eingeben und Lesen
    printf("Bitte geben Sie einen Steuersatz ein: ");
    scanf("%f", &steuer);

    // Zwischenrechnung
    end_betrag = betrag*(1+ (steuer / 100));

    // Ausgabe
    printf("Der Bruttopreis beträgt %.2f Euro\n", end_betrag);
    
}
