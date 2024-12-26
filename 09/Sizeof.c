 // Programm zum Ausführen für Quiz-Aufgabe zur Größe von Feldern mit sizof
 // Andreas Frommer, 23.12.2020
 
#include <stdio.h>

enum {LAENGE=10};
typedef float Feld[LAENGE];

void druckt_was0(float f[]) {
    printf("In Funktion druckt_was0: \n"); 
    printf("   Größe von f: %d\n", sizeof(f));
    printf("   Wert von f: %p\n", f);
}

void druckt_was1(float f[LAENGE]) {
    printf("In Funktion druckt_was1: \n");
    printf("   Größe von f: %d\n", sizeof(f));
    printf("   Wert von f: %p\n", f);
}


void druckt_was2(Feld f) {
    printf("In Funktion druckt_was2: \n");
    printf("   Größe von f: %d\n", sizeof(f));
    printf("   Wert von f: %p\n", f);
}




int main(void) {

    Feld feld;
    char zeichen[6];
    char *pc = zeichen;
    float *pf = NULL;
    char c = 'a';
    
    printf("Größe eines floats: %d\n", sizeof(1.0f));
    printf("Größe eines char: %d\n", sizeof(c));
    printf("Größe von pc: %d\n", sizeof(pc));
    printf("Größe von pf: %d\n", sizeof(pf));
    printf("Größe von zeichen: %d\n", sizeof(zeichen));
    printf("Größe von feld: %d\n", sizeof(feld));
    
    druckt_was0(feld);
    druckt_was1(feld);
    druckt_was2(feld);
}

    
