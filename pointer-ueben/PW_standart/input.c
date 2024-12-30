/*
Author: Leon Wengenroth
Mail: leon.wengenroth-hk@uni-wuppertal.de
Thema: Funktionen, die für die Aufgabenstellung bei der Eingabe helfen
*/

#include "input.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

//NOCH ANPASSEN: !!!!!!!!!!!!!!!!!!!!!!!
    //Variabelndeklaration
    struct RAM_Table* tab, *tab_p;   
    //Verschiedene Eingaben des Benutzers
    int input_i, *input_p;
    char input_c;






void enter(void){ //Erzeuge eine Pause zum besseren Lesen des Textes, Weiter geht es beim Drücken von ENTER
        
    printf("------------------------ENTER DRÜCKEN ZUM FORTFAHREN------------------------\n");
    
    //Mache weiter bei der Eingabe von Enter + leere Puffer, falls unerwünschte Werte im Eingangspuffer stehen
    char c = getchar();
    if(c != '\n' && c != EOF) //Falls noch zusätzliche Zeichen eingegeben wurden, entferne diese aus dem Buffer
        while(getchar() != '\n');
    return;
}

bool next(void) //Fragt den Benutzer, ob der Abschnitt wiederholt werden soll => Antwort als Boolean zurückgeliefert
{
    do{
        printf("Möchten Sie die Aufgabe wiederholen (w) oder fortfahren (f)?  ");

        //Werte Eingabe des ersten Zeichens aus
        switch(getchar()){
            case 'w':
                while(getchar() != '\n');//Leere Buffer
                return true;
                break;
                
            case 'f':
                while(getchar() != '\n');//Leere Buffer
                return false;
                break;
            
            case EOF:
                return false;
            
            case '\n': //Leere Eingabe => Buffer leer
                break;
                
            default: //Bei allen anderen unbekannten Eingaben
                while(getchar() != '\n');//Leere Buffer
        }
         
    }while(1);
    
    return false;
}



int scan(const char * __restrict format, ...){ //Ist die Implementierung von scan, nur dass der Buffer nach jeder Eingabe immer leer ist 
    //Entnommen aus: https://github.com/ffainelli/uClibc/blob/master/libc/stdio/_scan.c
    //-> Autor / Hoster: Florian Fainelli (ffainelli)
    //-> Letztere Zugriff: 13.10.21

    va_list arg;
	int rv;

	va_start(arg, format);
	rv = vfscanf(stdin, format, arg);
    
    //Modifikaton
    char c;   
    if((c = getchar()) != '\n' && c != EOF) //EOF für den Fall, dass die Eingabe STRG+D ist
        while( (c = getchar()) != '\n' && c != EOF);
    //Modifikation ENDE
    
    
	va_end(arg);
    
	return rv;
}
  