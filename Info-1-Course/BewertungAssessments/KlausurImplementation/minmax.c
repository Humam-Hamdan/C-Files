#include <stdio.h>

void minmax(int* a, int* b){
	int tmp;
	if( (*a)>(*b) ){
		tmp = (*a);
		(*a) = (*b);
		(*b) = tmp;
	}
}

int main(){

	int a,b;

	printf("Zwei Zahlen eingeben: ");
	scanf("%d %d", &a, &b);

	minmax(&a,&b);

	printf("Minimum = %d, Maximum = %d\n", a, b);
}
