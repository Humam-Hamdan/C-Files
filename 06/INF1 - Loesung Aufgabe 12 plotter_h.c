/**************************************/
/* Humam Hamdan                       */
/* Gruppe: Do.12                      */
/* Leiter: Florian Möschler           */
/* Uebungsblatt:  6  , Aufgabe:  11   */
/* Datum:     27 Nov                  */
/* Status:       Done                 */
/**************************************/

/*
Set pi, x=0
till x=pi
    set function

    if value = 0 => 0
    value != 0 => *
    the x axis => -

    x+=pi/60

    - reverse plotter.c :)

*/


#include <stdio.h>
#include <math.h>

int main(void) {
    
    double raster = 60;
    int scal = 20;
    int i,j,y;
    double x, f;
    double PI = 4*atan(1);

    for (j= -scal; j <= scal; j++) 
    {
        for (i=0; i<=raster; i++) 
        {
            x = (PI*i)/raster;
            f = -sin(5*x)*exp(-0.5*x);

            if (round(scal * f)==j) 
            {
                if (j!=0) 
                    printf("*");
                else
                    printf("0");
            }
            else
            {
                if (j == 0)
                    printf("-");
                else
                    printf(" ");    
            }
        }
        printf("\n");
    }    
}

/*another solution - better:) from gpt

#include <stdio.h>
#include <math.h>

int main(void) {
    int raster = 30;
    int scal = 20;
    int i, j;
    double x, f;
    double PI = 4 * atan(1);

    for (j = -scal; j <= scal; j++) { // Loop for vertical scaling
        for (i = 0; i <= raster; i++) { // Loop for horizontal scaling
            x = (PI * i) / raster; // Calculate x based on i (inside the loop)
            f = -sin(5 * x) * exp(-0.5 * x); // Function value

            // Round x * scal and compare it to j
            if (round(scal * f) == j) { 
                if (j != 0)
                    printf("*");
                else
                    printf("0");
            } else {
                if (j == 0)
                    printf("-");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}


*/