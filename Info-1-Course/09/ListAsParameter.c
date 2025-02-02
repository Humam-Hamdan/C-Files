#include <stdio.h>
constexpr int N = 10;
typedef double Vektor[N];
// setzt die Komponenten des Vektors v auf Null
void setzeNull(Vektor v)
// Änderungen im Feld v sind auch außerhalb der Funktion sichtbar
{
for (int i = 0; i < N; i++)
v[i] = 0.0;
}
// gibt den Vektor v aus
void drucke(const Vektor v)
// reines IN-Argument: keine Schreib-Zugriffe v[…] = … innerhalb der Funktion
{
printf(”(”);
for (int i = 0; i < N - 1; i++)
printf(”%g,␣”, v[i]);
printf(”%g)\n”, v[N - 1]);
}
int main(void)
{
Vektor x;

setzeNull(x);
x[1] = 1.3;
drucke(x);
}
