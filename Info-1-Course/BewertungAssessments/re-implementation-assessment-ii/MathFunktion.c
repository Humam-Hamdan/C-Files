// Zu ergänzendes Programmfragment
// Gesucht ist die Summe s = |sin(1)| + |sin(2)| + ... + |sin(100)|
// Andreas Frommer, 22.11.2020

#include <stdio.h>
#include <math.h>

float s, z;
int i;

int main(void) 
{
    for (i=1; i<101;i++) 
    {
        s= s+ fabs(sin(i));
        printf("%d\n",i);
    }
    printf("Die gesuchte Summe hat den Wert %f\n", s);
}
