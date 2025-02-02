// Vorlage zum Ergänzen für die 3. Aufgabe auf Blatt 10
// (Auswertung eines arithmetischen Ausdrucks ohne Klammerung)
// Andreas Frommer, 20.12.2024
//
//
//Pseudocode
// lies die Eingabe in einen String ein
// lies linken Operand vom String
// solange es noch weitere Operatoren gibt
//     lies Operator ein  (1)
//     lies rechten Operand ein (1)
//     berechne das Ergebnis; Ergebnis wird neuer linker Operand 
// (1): aus dem String wird beim aktuellen Index startend  mit %c der Operator, mit %d der Operand gelesen;
//      danach wird der der aktuelle Index bis zum nächsten Operator weitergerückt 


#include <stdio.h>
#include <ctype.h>
#include <string.h>

enum {N=100};

char ausdruck[N];


int main() {
    
    int akt_index = 0;
    int li_operand, re_operand;
    char operator;
    
    printf("Gib einen Ausdruck ein\n");
     
    fgets(ausdruck, N, stdin);
    

    
    sscanf(ausdruck, "%d", &li_operand); // erster (linker) Operand 
        printf("Das ist kein Ausdruck!\n");
    while ( isdigit(ausdruck[akt_index]) ) // jetzt noch den akt_index vorrücken auf Zeichen nach dem linken Operanden
        akt_index++;
    
   // jetzt muss der Rest des Ausdrucks abgearbeitet werden: Das gibt eine while-Schleife, innerhalb derer man
   //  - den nächste Operator liest (operator, ein char) 
   //  - den rechten Operanden liest (ein int)
   //  - die Operation mit linkem umd rechtem Operanden durchführt und dem linken Operanden zuweist.
   // Dazu ist ein switch    (operator) sicher günstig 
    
    while () {
        sscanf();
        switch () {
            case '+': 
                li_operand += re_operand;
                break;
            // usw 
           default: ;
        }
        // jetzt muss man akt_index noch weiterrücken auf den nächsten Operator (oder ans Ende von Ausdruck)
        // Eise Skizze dürfte hilfreich sein
    }
    printf("%s = %d\n",ausdruck,li_operand);
}
        
