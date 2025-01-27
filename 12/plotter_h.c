
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// enum {raster = 60};
int halbe_hoehe = 30;

typedef double (*Func) (double);

double f1(double x) {
    return sin(5*x)*exp(-0.5*x);
}

double f2(double x) {
    return x;
}

double f3(double x) {
    return tan(x);
}

double f4(double x) {
    return atan(x);
}


double maximum(Func funktion, double a, double b, int raster) {
    double m = 0;
    double x, y;
    for (int i = 0; i <= raster; i++) {
        x = a + ((double)i) * (b - a) / raster;
        y = fabs(funktion(x));
        m = (y > m) ? y : m;
    }
    return m;
}


int main(void) {
    int i, j, y;
    double x, f;
    double PI = 4 * atan(1);
    double a = -10;
    double b = 10;
    double m;
    int raster;
    double scal;
    Func funktion;

    printf("Raster Eingeben: ");
    scanf("%i", &raster);

    double *fwerte;

    fwerte = calloc(raster+1, sizeof(double));
    if(fwerte == NULL)
        printf("calloc Error");

    funktion = f4;
    m = maximum(funktion, a, b, raster);
    scal = halbe_hoehe / m;
    
    for(int i=0; i<=raster; i++){
        x = a + ( (double) i )*(b-a)/raster;
        fwerte[i] = funktion(x);
    }

    for(j=halbe_hoehe; j>=-halbe_hoehe; j--){
        for(i=0; i<= raster; i++){
            f = fwerte[i]; //funktion(x);
            y = round(scal*f);
            if(y==j)
                if(j!=0)
                    printf("*");
                else
                    printf("0");
            else
                if(j==0)
                    printf("-");
                else
                    printf(" ");

        }
        printf("\n");
    }
    // free();

}
