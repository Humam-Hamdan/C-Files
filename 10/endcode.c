// Verschluesselung
// Autor: Bruno Lang, Holger Arndt
// Version: 28.07.2017

#include <stdio.h>
#include <string.h>

// verschluesselt einen einzelnen Buchstaben
int encode(int c){
    char orig[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char code[] = "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";

    /* Die Zeichenketten koennen um weitere Zeichen (Sonderzeichen, Ziffern, ...)
    ergaenzt werden. Jede andere ein-eindeutige Zuordnung der Zeichen fuehrt
    zu einer anderen Verschluesselung.  */

    int i = 0;
    // suche das Zeichen c in der Zeichenkette orig
    while ((c != orig[i]) && (orig[i] != '\0'))
        i++;

    // wenn gefunden, ersetze durch das entsprechende Zeichen in code
    return (c == orig[i]) ? code[i] : c;
    }
int main(void){
    int c;
    while ((c = getchar()) != EOF)    // lies das naechste Zeichen
        putchar(encode(c));          // schreibe das verschluesselte Zeichen
}
