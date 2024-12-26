/************************************************/
/* Assessment II (06.12.2024)                   */
/* auto-generated .c file from text box input   */
/*                                              */
/* Humam Hamdan, 2427300                        */
/************************************************/

#include <stdio.h>
#include <math.h>//+1P

int main(void){
    
    double a=1.0;
    double a_nex = ((1/a)+(a/2));//+0,5P: Es fehlt die Zählvariable n
    do{
        printf("%lf, %lf\n",a_nex, a);//%.14lf und es sollte nur a_n+1 ausgegeben werden
        a=a+1;//mit a=a_nex funktioniert es
        a_nex = ((1/a)+(a/2));
    }
    while((fabs(a_nex - a) >= (10.0e-15) ));//+2P: 10^-15=1e-15 //+1P

    
    printf("sqrt(2) ist gleich: %lf\n", a_nex);
    double differenz = fabs(sqrt(2) - a_nex);//+1P
    printf("Differentz zwischen Verfahren und sqrt= %lf\n", differenz);//+1P
}//+2P
//8,5/11