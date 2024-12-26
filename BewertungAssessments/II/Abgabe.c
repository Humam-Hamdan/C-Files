/************************************************/
/* Assessment II (06.12.2024)                   */
/* auto-generated .c file from text box input   */
/*                                              */
/* Humam Hamdan, 2427300                        */
/************************************************/

#include <stdio.h>
#include <math.h>

int main(void){
    
    double a=1.0;
    double a_nex = ((1/a)+(a/2));
    do{
        printf("%lf, %lf\n",a_nex, a);
        a=a+1;
        a_nex = ((1/a)+(a/2));
    }
    while((fabs(a_nex - a) >= (10.0e-15) ));

    
    printf("sqrt(2) ist gleich: %lf\n", a_nex);
    double differenz = fabs(sqrt(2) - a_nex);
    printf("Differentz zwischen Verfahren und sqrt= %lf\n", differenz);
}