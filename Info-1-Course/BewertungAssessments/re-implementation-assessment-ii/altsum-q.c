
#include <stdio.h>

int altdsumm(int z, int b){
    int ziffer, summe=0, vorzeichen=1;
    while(z>0){
        ziffer = z%b;
        summe= summe+(vorzeichen*ziffer);
        z= z/b;
        vorzeichen= -vorzeichen;
    }
    return summe;
}

int main(){

    int z,b;
    printf("Gebe eine Zahl: ");
    scanf("%d",&z);
    printf("Gebe die Base: ");
    scanf("%d",&b);
    int summe=(altdsumm(z,b));
    printf("die alternierende Quersumme für Zahl %d zur Base %d ist: %d\n", z ,b ,summe);
}