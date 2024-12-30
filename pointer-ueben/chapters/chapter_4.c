/*
Author: Leon Wengenroth
Mail: leon.wengenroth-hk@uni-wuppertal.de
Thema: Pointer
*/

#include <stdio.h>
#include <stdlib.h>

#include "../PW_standart/List.h"
#include "chapters.h"
#include "../PW_standart/input.h"
#include <time.h>


//Kapitel 4
void kap4(void){
    //Variabelndeklaration
    //Verschiedene Eingaben des Benutzers
    int input_i;
    char input_c;
    
    //Aufgabe 4.1   
    do{
        system("clear");
        printf("\n4. Pointer in C - Aufgaben\n*********************************************************\n");
        printf("\n\nAufgabe 4.1 \n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
        char lsg = 'a' + rand()%5;


        printf("Es sei folgender C-Code gegeben:\n\tint a, b, c, d, e;\n\tint *p_x = &%c\n\nAuf welche Variabel zeigt p_x:\n", lsg);

        //Eingabe der Lösung
        printf("\np_x ----> ");
        scan("%c", &input_c);

        if(input_c == lsg)
            printf("Die Antwort ist richtig.\n");
        else
            printf("Die Antwort ist falsch.\n");

    }while(next());
    
    
    //Aufgabe 4.2
    do{
        system("clear");
        printf("\n4. Pointer in C - Aufgaben\n*********************************************************\n");
        printf("\n\nAufgabe 4.2 \n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    
        //Erstellung der Aufgabe
        int var[3];
        char c = 'a' + rand() % 3;
        
        for(int i=0; i<3; i++)
            var[i] = 1 + rand()%50;
        
        //Ausgabe
        printf("Es sei folgender C-Code gegeben:\n\tint a = %d, b = %d, c = %d;\n\tint *p_x = &%c;\n\t*p_x = 2 * (*p_x);\n Welche Zahl steht nachher in %c?  ", var[0], var[1], var[2], c, c);
        scan("%d", &input_i);
        
        //Ergebnis
        if( input_i == 2 * var[(int) c - 'a'] )
            printf("Die Antwort ist richtig.\n");
        else
            printf("Die Antwort ist falsch.\n");
    }while(next());
    
    
    //4.3 Aufgabe: C-Code mit Pointern auswerten 
    do{
        system("clear");
        printf("\n4. Pointer in C - Aufgaben\n*********************************************************\n");
        printf("\nAufgabe 4.3 \n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
        printf("Hinweis: Diese Aufgabe besteht aus mehreren Teilaufgaben, die aufeinander aufbauen. Wenn eine Teilaufgabe falsch gelöst wurde, wird diese automatisch wiederholt. In den nachfolgenden Teilaufgaben sollen nur mit den korrekt gelösten Lösungen der bisherigen Teilaufgaben gearbeitet werden.\n");
        //Alle Teillösungen, die NUR für folgende Teilaufgaben wichtig sind und später in den jeweiligen Teilaufgaben generiert werden
        char asw_p_x, asw_p_y;
        int var[6]; //Representiert die Variabeln a, b, c, d, e, f
        //TEIL 1
        do{
            //Zufälliges Generieren der Lösungen
            asw_p_x = 'a' + rand()%6;
            asw_p_y = 'a' + rand()%6;
            if(asw_p_y == asw_p_x)//Sichere, dass die Pointer auf verschiedene Variabeln zeigen
                asw_p_y = asw_p_x + 1 > 'f' ? asw_p_x - 1 : asw_p_x + 1;
            
            //Aufgabenstellung 1
            printf("Im Folgenden ist ein Ausschnitt aus einem C-Programm gegeben:\n");
            printf("\tint a, b, c, d, e, f;\n\tint *p_x = &%c, *p_y = &%c;\n", asw_p_x, asw_p_y);
            printf("Auf welche Variabel zeigt der Pointer p_x?  ");
            
            //Antwort
            do{
                scan("%c", &input_c);
            }while(input_c == '\n' && input_c != EOF); //Vermeide das Einlesen von \n, die noch im Puffer stehen
            
            
            //Auswertung 1
            if((int) input_c == asw_p_x || input_c == EOF)
                printf("Die Antwort ist korrekt.\n");
            else{ //Falsche Antwort => Wiederholung
                printf("Die Antwort ist falsch.\n---------------------------\n");
                continue;
            }
            
             //Aufgabenstellung 2
            printf("Auf welche Variabel zeigt der Pointer p_y?  ");
            
            //Antwort
            do{
                scan("%c", &input_c);
            }while(input_c == '\n' && input_c != EOF); //Vermeide das Einlesen von \n, die noch im Puffer stehen
            
            //Auswertung2
            if((int) input_c == asw_p_y){
                printf("Die Antwort ist korrekt.\n");
                break; //Nächste Aufgabe
            }
                
            printf("Die Antwort ist falsch.\n");


        }while(input_c != EOF);
        
        //TEIL 2
        do{            
            //Zufälliges Belegen der Variabeln
            for(int i=0; i<6; i++)
                var[i] = rand() % 20;
            
            //Suche zufällige Variablen aus, auf die die Pointer zugreifen sollen
            int v1 = rand()%6, v2 = rand()%6; //Positionen der Variabeln im Variabeln-Pointer
            
            //Aufgabenstellung
            printf("--------------------------------------\nNun wird der Programmauschnitt fortgesetzt:\n");
            printf("\ta = %d;\n\tb = %d;\n\tc = %d;\n\td = %d;\n\te = %d;\n\tf = %d;\n\t*p_x = %c + %c;\n", var[0], var[1], var[2], var[3], var[4], var[5], (char) v1 + 'a', (char) v2 + 'a');
            printf("Was steht nun in der Variabel %c?  ", asw_p_x);
            
            //Berechne Lösung
            var[(int) (asw_p_x -'a')] = var[v1] + var[v2];
            
            //Antwort
            scan("%d", &input_i);
            
            //Auswertung
            if(input_i == var[(int) (asw_p_x -'a')]){
                printf("Die Antwort ist korrekt.\n");
                break; //Nächste Aufgabe
            }
                
            printf("Die Antwort ist falsch.\n");

        }while(input_i == EOF);
        
        
        //TEIL 3
        do{                                    
            //Aufgabenstellung
            printf("--------------------------------------\nDer C-Programmauschnitt endet mit:\n");
            printf("\tint *p_z = p_y;\n\t*p_y=0; \n\t*p_x=*p_z;\n");
            printf("Geben Sie nun den Inhalt aller Variabeln ein. Das Ergebnis folgt am Ende aller Eingaben:\n[Tipp: Überlegen Sie sich zuerst, was der Programmausschnitt im Speicher bewirkt und bedenken Sie die vorherigen Veränderungen am Speicher (p_x)]\n");
            
            //Berechne Lösung
            var[(int)(asw_p_x - 'a')] = 0;
            var[(int)(asw_p_y - 'a')] = 0;
            
            //Antwort
            bool asw = true, mistakes[6];
            
            for(int i=0; i<6; i++){
                printf("%c = ", (char)((int)'a'+i));
                scan("%d", &input_i);
            
                mistakes[i] = (input_i == var[i]);
                asw = asw & mistakes[i]; //Wenn asw immer noch richtig ist, bestimme, ob es auch dieses Ergebnis dieses Durchlaufes ist
            }
            
            //Auswertung
            if(asw){
                printf("Die Antwort ist korrekt.\n");
                break; //Nächste Aufgabe
            }
                
            printf("Die folgenden Antworte(n) sind falsch:\n");
            for(int i=0; i<6; i++)
                if(!mistakes[i])
                    printf("%c ", 'a'+ i);
            printf("\n");

        }while(input_i != EOF);
       
        
    }while(next());  
        
    return;
}