#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { N = 100};

typedef struct Staat{
	char name[N];
	char hauptstadt[N];
	char cctld[5];
	char kurzName[5];
	int einwohner;
	double flaeche;
	struct Staat* Knote
} Staat; 

Staat germany, nauru;



double EinwohnerProQKM(Staat s){
	double x;
	x = (float)(s.einwohner)/s.flaeche;
	return x;
}

int main(){

	strncpy(germany.cctld, "de", 3);
	strncpy(germany.name, "Deutschland", 13);
	strncpy(germany.hauptstadt, "Berlin", 8);
	germany.einwohner= 84482267;
	germany.flaeche=357375.62;
	
	strncpy(nauru.name, "Nauru", 6);
	strncpy(nauru.hauptstadt, "Yaren", 6);
	nauru.flaeche=21;
	nauru.einwohner=10834;

	printf("einwohner pro flaeche in nauru ist = %lf\n", EinwohnerProQKM(nauru));
	Staat* anfang;
	anfang = calloc(198,sizeof(Staat));
	anfang = &nauru;
	free(anfang);
}
