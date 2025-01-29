/************************************************/
/* Assessment III (17.01.2025)                   */
/* auto-generated .c file from text box input   */
/*                                              */
/* Humam Hamdan, 2427300                        */
/************************************************/

/*
* scanf("%lf", &x[i]) nicht scanf("%lf", x[i]) 
* sowohl im arith_mittel als auch in std_abw musst du anstatt eines = ein += benutzen
*/

#include <stdio.h>
#include <math.h>


double arith_mittel(int n, double x[]){
        double a=0;
        for(int i=0; i<n; i++)
                a=x[i]; // a+= 
        double a_strich = 1/n * a;
        return a_strich;
}

double std_abw(int n, double x[]){
        double a = arith_mittel(n,x);
        double s_cache=0;
        for(int i=0; i<n; i++)
                s_cache = (x[i]-a)*(x[i]-a); // s_cache +=
        double s;
        s = sqrt(s_cache/(n-1));
        return s;
}

int main(){
        int n;
        printf("Gebe n :");
        scanf("%d",&n);
        double x[n];
        for(int i=0; i<n;i++){
                printf("Gib a_%d ein", i);
                scanf("%lf", x[i]); // & fehlt
        }
        printf("das arithmetische Mitel ist %lf", arith_mittel(n,x));    
        printf("die Standardabweichung ist %lf", std_abw(n,x));
}
