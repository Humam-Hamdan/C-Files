/*
Author: Leon Wengenroth
Mail: leon.wengenroth-hk@uni-wuppertal.de
Thema: Pointer
*/

#include <stdio.h>
#include "chapters.h"
#include "../PW_standart/input.h"


//Kapitel 5
void kap5(void){  
    //Verwendung von Pointern
    printf("\n5. Sonstige Informationen\n*********************************************************\n");
    printf("\n5.1. Verwendung von Pointern in C\n*********************************************************\n");
    printf("In C sind die wichtigen Verwendungen für Pointer in C:\n\t-> Veränderung von Parametern (als Pointer) in einer Funktion, ohne diese als Rückgabewert zurückzugeben\n\t-> Dynamisches Speichern\n\t-> Bei großen Datentypen (z.B. Arrays)\n");
    
    //Abschließende Bemerkung
    printf("\n5.2. Abschließende Bemerkung\n*********************************************************\n");
    printf("Vielleicht ist Ihnen aufgefallen, dass die Speicheradressen Buchstaben beeinhalteten. Dies liegt daran, dass die Adressen im Hexadezimalen Zahlensystem angezeigt wurden.\n");
    printf("Auch könnte Ihnen aufgefallen sein, dass die Speicheradressen nicht um 1 anstiegen, sondern um %ld oder um %ld. In eine Speicherzelle wird der Wert nicht dezimal abgespeichert, sondern als Binärzahl. So steht z.B. in einer Speicherzelle statt \"10\" die Binärzahl \"00000000000000000000000000001010\".\nDamit ist der Begriff der Speicherzelle, der hier genutzt wurde nicht ganz korrekt, da in einer \"Speicherzelle\" in unserem Fall für eine Zahl %ld Bytes gespeichert wurden, sodass pro \"Speicherzelle\" %ld physische Speicherzellen verwendet wurden.\n\n", sizeof(int), sizeof(int*), sizeof(int), sizeof(int)*8);
    enter();
}