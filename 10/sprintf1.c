#include <stdio.h>
#include <string.h>

int main(){
    double zahl = 1.0/3.0; 
    int breite, nachkomma;
    char format[34];

    printf("Feldbreite und Nachkomma ");
    scanf("%i %i", &breite, &nachkomma);

    sprintf(format, "1/3 = |%%%d.%df|", breite, nachkomma);
    printf("Formatstring = '%s' \n", format);
    printf(format,zahl);
    printf("\n");

}
