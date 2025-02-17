#include <stdio.h>

int main(void){
	// Hello World
	printf("Hellow World.\n");

	// initialization
	double a=1.5 * 42 * 42;
	int m;
	printf("a = %lf, m = %d\n", a,m);

	// printf
	int length_fixed =3, width_fixed =4;
	printf("length = %d, width = %d, area = %d\n", length_fixed,width_fixed, length_fixed * width_fixed);

	// Custom Values
	int length_custom, width_custom;
	printf("Input lenght and width\n");
	scanf("%i %i", &length_custom, &width_custom);
	printf("length = %i, width = %i, area = %i\n", length_custom, width_custom, length_custom * width_custom);

	// Arithmetic
	double x=7.5, y=2.5, z=2.0, t, u, v, w;
	t = x + y * z;
	u = 4 * (x-1) +y;
	v = x / y / z;
	w = x * -z;
	printf("t=%lf u=%lf v=%lf w=%lf\n", t, u, v, w);

	// Declare a Var outside of main, so can you use ist everywhere.
	// local vars need initialization. otherwise random -kinda-.


}
