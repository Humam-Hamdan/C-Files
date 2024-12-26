#include <stdio.h>
// Berechnung der Fibonacci-Zahlen
int main(void)
{
constexpr int N = 10; // C23; davor: enum { N = 10 };
int i;
// „skalare“ Variable
int f[N + 1];
/* Feld mit N + 1 int-Komponenten zum Speichern der
Fibonacci-Zahlen f[0], …, f[N]
*/
f[0] = 0;
f[1] = 1;

for (i = 2; i <= N; i++)
	f[i] = f[i - 1] + f[i - 2];
for (i = 0; i <= N; i++)
	printf(”f[%2d]␣=␣%10d\n”, i, f[i]);

}
