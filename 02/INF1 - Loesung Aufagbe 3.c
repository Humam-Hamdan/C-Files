/**************************************/
/* Humam Hamdan                       */
/* Gruppe: Do.12                      */
/* Leiter: Florian Möschler           */
/* Uebungsblatt: 2  , Aufgabe: 3      */
/* Datum: 24 - Okt - 2024             */
/* Status: geschafft                  */
/**************************************/

# include <stdio.h>

// Aufgabe 3, Ein Brutto Rechner:

float netto, brutto, acsteuer, steuer;

int main(void)
{
	printf("Bitte geben Sie einen Nettopreis in Euro ein: ");
	scanf("%f", &netto);
	printf("Bitte geben Sie einen Steuersatz ein: ");
	scanf("%f", &steuer);

	acsteuer = (100+steuer)/100;
	brutto = netto * acsteuer;

	printf("Der Bruttopreis beträgt %.2f Euro", brutto);

	return 0;
}

