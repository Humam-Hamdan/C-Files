#include <stdio.h>

double max(double a, double b)
{
    double maxi;

    printf("Max: a = %f, b = %f\n", a, b);

    if (a>b)
        maxi=a;
    else
        maxi=b;

    return maxi;
}

int main(void)
{
    double zahl;
    printf("Gebe die Zahl: ");
    scanf("%lf", &zahl);

    printf("Betrag von %lf = %lf\n", zahl, max(zahl, -zahl));

}