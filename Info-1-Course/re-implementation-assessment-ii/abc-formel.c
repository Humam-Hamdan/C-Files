
/*
Funktion to give if there's solutions
Funktion to calculate solutions

*/

#include <stdio.h>
#include <math.h>

int solver(double a, double b, double c, double *root1, double *root2){
    int solutions;
    double determenant = (b*b -4*a*c);
    if(determenant > 0) {
        *root1= ((-b + sqrt(determenant)) / (2*a));
        *root2= ((-b - sqrt(determenant)) / (2*a));
        solutions=2;
    }
    else if (determenant == 0){
        *root1=*root2= ((-b)/(2*a));
        solutions=1;
    }
    else
        solutions=0;
    return solutions;
}

int main(void){
    double a,b,c, root1, root2;
    int solutions;
    printf("Gebe Zahl a: ");
    scanf("%lf",&a);
    printf("Gebe Zahl b: ");
    scanf("%lf",&b);
    printf("Gebe Zahl c: ");
    scanf("%lf",&c);
    if(a==0){
        printf("Die Gleicung ist ungültig\n");
        return 0;
        }
    solutions=solver(a,b,c,&root1,&root2);
    if(solutions>0){
        printf("Die Anzahl der Lösungen beträgt: %d\n", solutions);
        if(root1==root2)
            printf("Die Lösung beträgt: %.2lf\n", root1);
        else
            printf("Die Lösungen sind: \n  Erste Lösung: %.2lf \n  Zweite Lösung: %.2lf\n", root1,root2);

    }
    else
        printf("Es gibe keine Lösung\n");
}