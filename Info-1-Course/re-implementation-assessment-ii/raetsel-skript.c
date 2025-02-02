#include <stdio.h>

int main(void)
{
	int zahl;

	printf("Zahl Eingeben: ");
	scanf("%d", &zahl);

	if (zahl > 4);
		printf("groesser als 4\n");
		// not guarded lol
		if (zahl < 10)
			printf("aber kleiner als 10\n");
	else
		printf("kleiner gleich 4\n");
}
