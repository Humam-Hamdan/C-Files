#include <stdio.h>
// Berechnung der Fibonacci-Zahlen
int main(void)
{
int n;
// Nummer der letzten zu berechnenden Fibonacci-Zahl f[n]
do
{
printf(”Nummer␣der␣letzten␣zu␣berechnenden␣Fibonacci-Zahl␣(2␣..␣46):␣”);
scanf(”%d”, &n);
}
while ((n < 2) || (n > 46));
int f[n + 1];
/* VLA mit n + 1 int-Komponenten zum Speichern der Zahlen
f[0], …, f[n]
*/
f[0] = 0;
f[1] = 1;
for (int i = 2; i <= n; i++)
f[i] = f[i - 1] + f[i - 2];

for (int i = 0; i <= n; i++)
printf(”f[%2d]␣=␣%8d\n”, i, f[i]);
}
