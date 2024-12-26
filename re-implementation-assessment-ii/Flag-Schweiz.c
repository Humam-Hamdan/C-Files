#include <stdio.h>

/* Gibt eine (grobe) Darstellung der Flagge der Schweiz in wählbarer Größe aus. */
int main(void)
{
	int n_max = 40;   	// maximale Größe der Flagge
	int n; 	// tatsächlich gewünschte Größe 
	// zulässigen Wert für die Größe n einlesen
	do
	{
	printf("Größe (≤ %d) eingeben: ", n_max);
	scanf("%d", &n);
	}
	while ((n <= 0) || (n > n_max));

	// zeilenweise über die Fläche der Flagge gehen
	for (int i = 1; i <= n; i = i + 1)
		{
			for (int j = 1; j <= n; j = j + 1)
			{
				// Punkte des Kreuzes mit „.“, andere Punkte mit „#“ darstellen
				if ( ( 
				(i > 0.2 * n) && (i <= 0.8 * n) &&
				(j > 0.4 * n) && (j <= 0.6 * n))
				// senkrechter Balken
				|| ( (j > 0.2 * n) && (j <= 0.8 * n) &&
				(i > 0.4 * n) && (i <= 0.6 * n) ) )
				// waagerechter Balken
				printf(". ");
				else
				printf("# ");
			}
		printf("\n");
	}
}