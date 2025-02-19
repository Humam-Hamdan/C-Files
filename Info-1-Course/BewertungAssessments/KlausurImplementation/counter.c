#include <stdio.h>

int main(){
	int counter=0, tmp=0;
	int z=0;
	while(counter<100){
		printf("Bitte Zahl Eingeben: ");
		scanf("%d", &tmp);
		counter+=tmp;
		tmp=0;
		z++;
	}
	printf("Sie haben %i Zahlen eingegeben, um 100 zu erreichen\n",z);
}
