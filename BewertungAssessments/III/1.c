/************************************************/
/* Assessment III (17.01.2025)                   */
/* auto-generated .c file from text box input   */
/*                                              */
/* Humam Hamdan, 2427300                        */
/************************************************/

#include <stdio.h>

double potenz_rek(double x, int n, int* anzahl){
        anzahl++; // (*anzahl) ++;
        if(n==0){
                return 1;
        }
        if(n%2 ==0){
                return potenz_rek(x, n/2, anzahl) * potenz_rek(x, n/2,anzahl);   
        }
        else{
                return x * potenz_rek(x,n-1,anzahl);
        }
}


int main(void){
        int anzahl=1, n;
        double x;
        printf("Geben Sie eine Zahl x ein: ");
        scanf("%lf", &x);
        printf("Geben Sie eine natuerliche Potenz n ein: ");
        scanf("%d", &n);
        printf("%.1lf^%d = %.1lf mit %d Aufrufen", x,n, potenz_rek(x,n,&anzahl), anzahl);
}
