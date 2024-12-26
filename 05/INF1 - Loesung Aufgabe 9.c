/************************************************/
/* Humam Hamdan                                 */
/* Gruppe: Do.12                                */
/* Leiter: Florian Möschler                     */
/* Uebungsblatt:  5  , Aufgabe: 9               */
/* Datum:  28 Nov 2024                          */
/* Status: After Claude, help from GPT and done.*/
/************************************************/


/*  
for loop
    n= 0
    i= n+1
    berechne mit i
    gebe n und berechnung aus
    if ist erfuellt
        abbruch
        ausgabe

    normalwert mit sqrt ausgeben.


Problem in for loop. to investigate.

welp, came to the idea that it was a while, but not a do while, will try again 2moro    

code from claude:
    double a_n = 1.0;   // a₀ = 1 (initial value)
    double a_next;      // a_{n+1} (next value)
    int iteration = 0;
    
    do {
        a_next = (1.0/a_n) + (a_n/2.0);  // Formula: a_{n+1} = 1/a_n + a_n/2
        printf("Iteration %d: %.15lf\n", iteration++, a_n);
        
        if(fabs(a_next - a_n) < 1e-15)   // Check if difference is small enough
            break;
            
        a_n = a_next;   // Update a_n for next iteration
        
    } 
    while(1);
    
    printf("\nFinal approximation: %.15lf\n", a_next);
    printf("Actual sqrt(2): %.15lf\n", sqrt(2));
    
*/


/*
    Code For Sqrt(2)
    double a = 1.0;
    double a_nex= 0.5 * (a + 2 / a);

    while ( ( fabs(a_nex - a) ) >= (10.0e-15) )
    {
        a=a_nex;
        a_nex = 0.5 * ( a + 2/a  );

    }
        printf("\nsqrt(2) = %.15lf", a_nex);
        printf("\nActual value %.15lf", sqrt(2));
*/

#include <stdio.h>
#include <math.h>

int main(void) 
{
    printf("Welcome! this is a sqrt calculator.");
    double x;
    printf("Input a natural number (point zero): ");
    scanf("%lf",&x);

    double a = 1.0;
    double a_nex= 0.5 * ( x/a +  a);
    int y = (int)x;
    double ac_val=sqrt(y);

    while ( ( fabs(a_nex - a) ) >= (10.0e-15) )
    {
        a=a_nex;
        a_nex = 0.5 * ( x/a + a );
    }
        printf("\nsqrt(%.0lf) = %.15lf",x, a_nex);
        printf("\nActual value for sqrt(%.0lf) is = %.15lf", ac_val,a_nex);

    return 0;
}