/*
Author: Leon Wengenroth
Mail: leon.wengenroth-hk@uni-wuppertal.de
Thema: Pointer
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "PW_standart/input.h"
#include "chapters/chapters.h"

    

int main(int argc, char* argv[]){
    
    //Variabelndeklaration
    int input_i; //Benutzereingabe
    bool exit = false;
    
    //Initialisiere den Zufälligkeitsgenerator
    srand((unsigned) time(0));
    
    while(!exit){ //Hauptmenü
        //Begrüssungstext
        system("clear"); //Leere Konsole vorher => Übersichtlicher
        printf("POINTER\n---------------------\n");
        printf("In diesem Programm machen Sie sich mit dem Programmierkonzept von \"Pointern\" näher vertraut.\n Dabei dienen interaktive Aufgaben zum besseren Verständnis der Erklärungen. In der Regel haben die Aufgaben beim Wiederholen andere Werte.\n\n"); 


        //Kapitelübersicht
        printf("KAPITELÜBERSICHT:\n-------------------------------------------------------------------------\n");
        printf("-> Kapitel 0: Einleitung\n");
        printf("-> Kapitel 1: Abspeichern von Variabeln\n");
        printf("-> Kapitel 2: Statt Variabeln Adressen speichern\n");
        printf("-> Kapitel 3: Pointer in C - Einführung\n");
        printf("-> Kapitel 4: Pointer in C - Aufgaben\n");
        printf("-> Kapitel 5: Sonstige Informationen\n");
        printf("Geben Sie bitte die Nummer des Kapitels an, mit dem sie starten wollen (Zum Beenden eine andere Zahl eingeben): ");

        //Eingabe
        input_i = -1;
        scan("%d", &input_i);

        switch(input_i){
            case 0:
                system("clear");
                kap0();
                break;

            case 1:
                system("clear");
                kap1();
                break;

            case 2:
                system("clear");
                kap2();
                break;

            case 3:
                system("clear");
                kap3();
                break;

            case 4:
                system("clear");
                kap4();
                break;

            case 5:
                system("clear");
                kap5();
                break;
            
            default:
                exit = true;
                printf("\n\n");
        }
    }
}


/*
Was noch zu tun ist:
-> Mehr Erklärungen und Beispiele ?
-> Mehr Kommentare?
-> Bessere Übersicht im Text => Mehr Abstand zwischen den Aufgaben und Kapiteln?
-> Loop bei Eingabe STRG + D oder den Pfeiltasten
-> Hausbeispiel aus kap4 in kap3 verschieben
*/