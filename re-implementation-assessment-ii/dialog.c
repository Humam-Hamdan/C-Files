
#include <stdio.h>

int main(void){
	int erste, zweite, dritte;
	// Erste Frage - Eingabe - Switch
	printf("Bist du schon mal Schwebebahn gefahren? (0 für ja und 1 für nein) \n");
	scanf("%d", &erste);
	switch (erste){
		case 0:
			printf("Bist du schon mal herausgesprungen? (0 für ja und 1 für nein)\n");
			scanf("%d", &zweite);
			switch(zweite){
				case 0:
					printf("Bist du ein Elefant? (0 für ja, 1 für weiß nicht und 2 für nein)\n");
					scanf("%d", &dritte);
					switch(dritte){
						case 0:
							printf("Hallo Tuff!");
							break;
						case 1:
							printf("Dann schau in den Spiegel!");
							break;
						case 2:
							printf("Hoffentlich hast du dich nicht verletzt!");
							break;
					}
					break;
				case 1:
					printf("Gut so!\n");
					break;
				}
			break;
		case 1:
			printf("Dann probiere es mal!");
			break;
		}


	return 0;
}

