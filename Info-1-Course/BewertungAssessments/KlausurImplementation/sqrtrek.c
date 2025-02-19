#include <stdio.h>

enum { E = 10**-12};

double sqrtRek(double a, double x){
	if(a<=1)
		return 0;
	else{
		while((x*x)-a<E){
			sqrtRek(x, (0.5*(x + (a/x))));
		}
	}	
}
int main(){
	double a,b;
	printf("Gebe a,b");
	scanf("%lf %lf", &a, &b);
	sqrtRek(a,b);
}
