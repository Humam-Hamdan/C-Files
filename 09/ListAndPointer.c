#include <stdio.h>
int main(void)
{
int f[] = { 10, 11, 12 }; // Feldlänge: 3
int* pf = f;
// Zeiger auf f
12
13
14
15
16
17
18
}
printf(”%d␣%d␣%d␣%d␣%d\n”,
f[1],
// Zugriff über Feld
*(pf + 1),
// Zugriff mit Zeiger
*(f + 1),
// Feldname als Zeiger
pf[1],
// Zeiger als Feldname
1[f]);
/* [] ist kommutativ, entspricht *(1 + f);
nicht verwenden, da verwirrend!
*/
