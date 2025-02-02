
#include <stdio.h>
#include <math.h>

double sqrtx(double x){

    double a = 1.0;
    double a_nex= 0.5 * ( x/a +  a);

    while ( ( fabs(a_nex - a) ) >= (10.0e-15) ){
        a=a_nex;
        a_nex = 0.5 * ( x/a + a );
    }
    return a_nex;
}

int main(void){
    printf("Welcome! this is a sqrt calculator.");
    double x;
    printf("Input a natural number (point zero): ");
    scanf("%lf",&x);

    int y = (int)x;
    double ac_val=sqrt(y);
    double sqx=sqrtx(x);
    printf("\nsqrt(%.0lf) = %.15lf",x, sqx);
    printf("\nActual value for sqrt(%.0lf) is = %.15lf\n", x, ac_val);

    return 0;
}