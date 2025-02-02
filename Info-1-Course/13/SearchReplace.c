
// Pseudocode
// durchlaufe der Reihe nach alle Zeichen im Eingabefile
//    wenn an dem Zeichen ein Wort beginnt (1)
//         lies das ganz Wort in einen String ein (2)
//         falls der String das gesuchte Wort ist
//                gib die Zeichen des ersetzten Worts in das Ausgabefile
//         sonst
//                gib die Zeichen des Strings in das Ausgabefile
//    sonst (das Zeichen ist kein Buchstabe)
//         schreibe das Zeichen in das Ausgabefile 
//
// (1) das Zeichen ist ein Buchstabe, das Zeichen davor war keine
// (2) das Wort ist zu Ende vor dem nächsten Nicht-Buchstaben
// Andreas Frommer, 21.01.2025

#include <ctype.h>
#include <string.h>
#include <stdio.h>


int main(int narg, char* argv[]) {
    
    enum {N=40};   //maximale Länge der Wörter
    
    char alt[N], neu[N], tmp[N];
    FILE* ein = fopen(argv[1],"r"); 
    FILE *aus = fopen(argv[2],"w");
    
    strcpy(alt, argv[3]);
    strcpy(neu, argv[4]);
    
    int i;
    char davor = '\0';  // alles nur kein Buchstabe
    char c = fgetc(ein);
    
    while ( c != EOF) {
        if (!isalpha(davor) && isalpha(c)) { // ein neues Wort beginnt
            i = 0;
            do {
                tmp[i] = c;
                c = fgetc(ein);
                i++; 
            }
            while (isalpha(c));
            
            tmp[i] = '\0';
            
            if (strcmp(tmp,alt) == 0)  // neu nach aus schreiben
                fprintf(aus, "%s", neu);
            else  //tmp in aus schreiben
                fprintf(aus, "%s", tmp);
        }
        else {
            fputc(c,aus);
            davor = c;
            c = fgetc(ein);
        }
    }
    
    fclose(ein);
    fclose(aus);
}
