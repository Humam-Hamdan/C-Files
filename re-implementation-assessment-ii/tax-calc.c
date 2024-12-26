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

float tax_calc(float original, float tax){
	float acsteuer = (100+tax)/100;
	float brutto = original * acsteuer;
	return brutto;
}

int main(void)
{
	printf("Bitte geben Sie einen Nettopreis in Euro ein: ");
	scanf("%f", &netto);
	printf("Bitte geben Sie einen Steuersatz ein: ");
	scanf("%f", &steuer);

	float brutto=tax_calc(netto,steuer);
	
	printf("Der Bruttopreis beträgt %.2f Euro", brutto);

	return 0;
}

