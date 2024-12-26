
/* Aufgabe 2:a
das Programm ist eine Einfache Addier-Rechner in dem man drei Ganzen Zahlen reinstosst und kriegt dann die Summe.
*/


# include <stdio.h>

int main(void)
{
	// Def zahl: ganze zahl, ist auch produkt, mit anfangswert von 1 (denn multiplikation)
	int zahl;
	int produkt = 1;

	// Damit man kennt, was man tun soll
	printf("Geben Sie drei ganze Zahlen ein:\n");

	// i fuer das Loop
	int i=0;
	while(i<3)
	{
		// lesen von Eingaben und Multiplizieren:
		scanf("%d", &zahl);
		produkt = produkt * zahl;
		i = i + 1;
	}

	// Endresultat ausgeben
	printf("Produkt = %d \n", produkt);

	return 0;
}
