/**************************************/
/* Humam Hamdan                       */
/* Gruppe: Do.12                      */
/* Leiter: Florian Möschler           */
/* Uebungsblatt:    , Aufgabe:        */
/* Datum:   5 Dez                     */
/* Status:                            */
/**************************************/


/*
Funktion to give if there's solutions
Funktion to calculate solutions

*/

#include <stdio.h>
#include <math.h>


int isThereSolution(double a, double b, double c){
    int solutions;
    if((b*b -4*a*c)>0)
        solutions=2;
    else if((b*b -4*a*c)==0)
        solutions=1;
    else
        solutions=0;
    return solutions;
}

void quad(double a, double b, double c, double *root1, double *root2){
    int solutions=isThereSolution(a,b,c);
    if(solutions>=0) {
        *root1= (-b + sqrt((b*b -4*a*c))) / (2*a);
        *root2= (-b - sqrt((b*b -4*a*c))) / (2*a);
    }
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
    solutions=isThereSolution(a,b,c);
    if(solutions>0){
        printf("Die Anzahl der Lösungen beträgt: %d\n", solutions);
        quad(a,b,c, &root1, &root2);
        if(root1==root2)
            printf("Die Lösung beträgt: %.2lf\n", root1);
        else
            printf("Die Lösungen sind: \n  Erste Lösung: %.2lf \n  Zweite Lösung: %.2lf\n", root1,root2);

    }
    else
        printf("Es gibe keine Lösung\n");
}