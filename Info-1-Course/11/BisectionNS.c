
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Func ist ein Zeiger auf eine Funktion mit double-Ergebnis und einem double-Argument */
typedef double (*Func)(double);  

/* Funktion mit Nullstelle in [1; 2] */
double f1(double x)
{
    return sin(x) - x + 1;
}

/* Andere Funktion */
double f2(double x)
{
    return x * x - 2.0;
}

double f3(double x){
    return exp(x)- (x*x*x);
}

/* bestimmt mittels Bisektion eine Nullstelle der Funktion f im Intervall [a; b] 
   mit einer Genauigkeit < eps.
   Voraussetzung: f(a) und f(b) haben unterschiedliches Vorzeichen */
double nullstelle(Func f, double a, double b, double eps)
{
    double c;

    while (b - a >= 2.0 * eps) 
    {
        c = a + 0.5 * (b - a);  // Intervallmittelpunkt
        if (f(c) == 0.0)         // Nullstelle gefunden
            return c;
        else if (f(a) * f(c) < 0.0)  // in linker Hälfte weitersuchen
            b = c;
        else                        // rechts weitersuchen
            a = c;
    }

    // Ergebnis: Mitte des letzten Intervalls
    return a + 0.5 * (b - a);
}

int main(int argc, char* argv[])
{
    double a = 1.0;        // Untergrenze des Intervalls
    double b = 2.0;        // Obergrenze des Intervalls
    double eps = 1.0e-12;  // Genauigkeitsschranke
    double nst;            // Näherung für Nullstelle

    if (strcmp(argv[1], "f1") == 0)
        nst = nullstelle(f1, a, b, eps);
    else if (strcmp(argv[1], "f2") == 0)
        nst = nullstelle(f2, a, b, eps);
    else if (strcmp(argv[1], "cos") == 0)
        nst = nullstelle(cos, a, b, eps);
    else if (strcmp(argv[1], "f3") == 0)
        nst = nullstelle(f3, a, b, eps);
    else
    {
        printf("Unbekannte Funktion!\n");
        exit(EXIT_FAILURE);  // Fehlerabbruch
    }

    printf("Eine Nullstelle von %s in [%.6f; %.6f] ist näherungsweise %.14f\n",
           argv[1], a, b, nst);

    return 0;
}
