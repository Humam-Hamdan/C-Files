#include <stdio.h>


// Laenge Zeichenkette

long int lenght1(const char str[]){
    int k = 0;
    while(str[k] != '\0')
        k++;
    return k;
}


long int lenght2(const char* str){

    const char* p = str;

    while(*p != '\0')
        p++;
    return (p-str);
}

int main(){
    char c[3][7] = {"OK","Also","gut"}; // 3 Zeilen mit bis 7 Spalten | three rows with upto 7 columns

    for(int i=0; i<3; i++)
        printf("%ld %ld\n", lenght1(c[i]), lenght2(c[i]));
}

 /* c[i] ist ein Zeiger auf den Anfang der i-ten Zeile des Textfeldes c.
 Die aktuelle Länge einer solchen Zeile wird mittels ’\0’ festgestellt.
 Adressierung mittels &c[i][0] wäre äquivalent;
 c[i][0] wäre falsch, da dann Wertübergabe eines einzelnen Zeichens
 */

