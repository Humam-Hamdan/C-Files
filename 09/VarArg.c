#include <stdarg.h>
#include <stdio.h>
double sum(int n, ...){
	va_list ap;
	double summe = 0.0;
	va_start(ap, n); // C23, davor: va_start(ap, n); (was (ap)

	while (n-- > 0)
		summe += va_arg(ap, double);

	va_end(ap);

	return summe;
}

int main(void)
{
	printf("%f\n", sum(0));
	printf("%f\n", sum(1, 2.0));
	printf("%f\n", sum(2, 2.0, 3.0));
	printf("%f\n", sum(3, 2.0, 3.0, 4.0));
	printf("%f\n", sum(4, 2.0, 3.0, 4.0, 5.0));
	printf("%f\n", sum(5, 2.0, 3.0, 4.0, 5.0, 6.0));
	printf("%f\n", sum(6, 2.0, 3.0, 4.0, 5.0, 6.0, 7));
}
