#include <stdio.h>
int main(void)
{
int x[] = { -2, 5 };
int* y;
printf(”x␣=␣(%d,␣%d)\n”, x[0], x[1]);
y = x;
// y zeigt auf dieselbe Speicheradresse wie x
printf(”y␣=␣(%d,␣%d)\n”, y[0], y[1]);
14
15
16
17
18
19
}
y[1] = 4;
printf(”y␣=␣(%d,␣%d)\n”, y[0], y[1]);
printf(”x␣=␣(%d,␣%d)\n”, x[0], x[1]);
