/**************************************/
/* Humam Hamdan                       */
/* Gruppe: Do.12                      */
/* Leiter: Florian Möschler           */
/* Uebungsblatt:8                      */
/* Aufgabe:  16                         */
/* Datum:    11 dez                         */
/**************************************/

/*
why this definition? it's just x^n everywhere!
it's fast power...
*/
/*
#include <stdio.h>
#include <stdbool.h>

float potenz_rek(float x, int n){
    bool n_zero = (n==0);
    bool n_even = (n%2 == 0);
    float half_pow = potenz_rek(x, (n/2));
    if(n_zero){
        x=1;
    }
    else if(n_even){
        x =  half_pow * half_pow;
    }
    else{
        x = x * half_pow * half_pow;
    }
    return x;
}


*/

#include <stdio.h>
#include <stdbool.h>

float potenz_rek(float x, int n, int* z) {
    (*z)++;

    bool n_neg = (n<0);
    if (n == 0) {
        return 1; 
        // Base case: x^0 = 1
    }

    bool n_even = (n % 2 == 0);
    if (n_neg) {
        return 1 / potenz_rek(x, -n, z); 
        // Handle negative powers
    }

    float half_pow = potenz_rek(x, n / 2, z);

    // B16 bei ungerade passt das zwar mit >>x * half_pow * half_pow<<
    // Das ist jedoch nicht schön gelöst mit dem Abschneiden ...

    if (n_even) {
        return half_pow * half_pow; 
        // x^(n/2) * x^(n/2) for even n
    } 
    else {
        return x * half_pow * half_pow; 
        // x * x^(n/2) * x^(n/2) for odd n
    }
}

int main() {
    float x;
    int n;
    int z=0;

    printf("Gebe Zahl: ");
    scanf("%f", &x);

    printf("Gebe Potenz: ");
    scanf("%i", &n);

    printf("x = %.2f, n = %i\n", x, n);
    printf("%.2f hoch %i ist: %.2f\n", x, n, potenz_rek(x, n, &z));
    printf("Calls = %i\n", z);

    return 0;
}

// With the appreciated help of GPT :)
