/*
Author: Leon Wengenroth
Mail: leon.wengenroth-hk@uni-wuppertal.de
Thema: Funktionen, die für die Aufgabenstellung bei der Eingabe helfen
*/
#ifndef INPUT
#define INPUT

#include <stdbool.h>

void enter(void); //Erzeuge eine Pause zum besseren Lesen des Textes, Weiter geht es beim Drücken von ENTER
        
bool next(void); //Fragt den Benutzer, ob der Abschnitt wiederholt werden soll => Antwort als Boolean zurückgeliefert

int scan(const char * __restrict format, ...); //Ist die Implementierung von scan, nur dass der Buffer nach jeder Eingabe immer leer ist 

#endif