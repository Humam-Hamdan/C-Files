/**************************************/
/* Humam Hamdan                       */
/* Gruppe: Do.12                      */
/* Leiter: Florian Möschler           */
/* Uebungsblatt:  7  , Aufgabe:   13  */
/* Datum:      5 Dez                  */
/* Status:   Done                     */
/**************************************/

#include <stdio.h>

int main(){

    int z, ziffer, b, summe=0, vorzeichen=1;
    printf("Gebe eine Zahl: ");
    scanf("%d",&z);
    printf("Gebe die Base: ");
    scanf("%d",&b);
    while(z>0){
        ziffer = z%b;
        summe= summe+(vorzeichen*ziffer);
        z= z/b;
        vorzeichen= -vorzeichen;
    }
    printf("die alternierende Quersumme für Zahl %d zur Base %d ist: %d\n", z ,b ,summe);
}