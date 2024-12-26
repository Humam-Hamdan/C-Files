#include <stdio.h>

int main(){
    char zeile[80];
    char c1,c2;

    printf("Zeichen Eingeben: ");
    fgets(zeile,80,stdin);
    c1=zeile[0];

    printf(" '%c' gelesen\n",c1);

    printf("Zeichen Eingeben: ");
    fgets(zeile,80,stdin);
    c2=zeile[0];

    printf(" '%c' gelesen\n",c2);

}
