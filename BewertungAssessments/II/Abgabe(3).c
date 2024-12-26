/************************************************/
/* Assessment II (06.12.2024)                   */
/* auto-generated .c file from text box input   */
/*                                              */
/* Humam Hamdan, 2427300                        */
/************************************************/

#include <stdio.h>
#include <stdbool.h>

/*

teiler summe soll:
    echte teiler berechnen indem sie in division fueht
    summs um teiler erhohen
    und dann n erhohen

im main dann nur int printf scanf und abgabe

*/

int teilersumme(int n){
    int t=1;

    bool echTeiler = ((t<n) && (n/t ==0) && (t<1250));
    while(echTeiler){
        t++;
        printf("%i\n",t);
    }
    int summe=0;
    summe = summe +t;
    return summe;
}

int main(){
    int n;
    printf("Gebe die Oberegrenze ein; ");
    scanf("%i",&n);
    printf("die Befreundete zahlen bis zur Oberegrenze sind: (%i, %i)");

}