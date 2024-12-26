#include <locale.h>
#include <stdio.h>

int main(){
    setlocale(LC_ALL,"");

    // Zeichenkette
    const char s[]="SteingÜáæß";

    printf("Zeichenkette: %s", s);

    printf("Sizeof s= %lu",sizeof(s));
}
