/*
Author: Leon Wengenroth
Mail: leon.wengenroth-hk@uni-wuppertal.de
Thema: Pointer
*/

#include <stdio.h>
#include "../RAM.h"
#include "chapters.h"
#include "../PW_standart/input.h"


//Kapitel 4
void kap3(void){
    //Variabelndeklaration
    struct RAM_Table* tab, *tab_p; 

    
    //Head
    printf("\n3. Pointer in C - Einführung\n*********************************************************\n"); 
    
    //Erstelle leere Speicherbereiche
    tab = RAM_create(1, 6, false);
    tab_p = RAM_create(1, 3, true);
    
    //Text
    printf("Sie haben kennengelernt, wie Pointer auf der Speicherebene funktionieren. Nun schauen wir uns an, wie man mit Pointern in C arbeitet (Falls sie mit den Speicheradressen nichts anfangen können: Keine Sorge es folgt noch eine andere Vorstellungsweise über Pointer):\n\n");
    printf("Wie Sie sehen, ist der Umgang mit Adressen sehr umständlich. Glücklicherweise übernimmt C die Adressenverwaltung, indem statt der Adresse eine Variabel verwendet wird.\n");
    printf("In C wird eine Variabel mit \"<Datentyp> <Name> [=<Initialwert>] ;\" erzeugt und optional schon mit einem Wert initialisiert. {Im Hausbeispiel: Ein Haus bauen und optional direkt mit einer Zahl füllen.}\n");
    
    //Beispiel
    printf("Dazu ein Beispiel:\nBetrachten wir folgenden Speicherbereich:\n\n");
    
    RAM_print(tab);
    
    printf("Wenn wir nun in C den Code\n\tint a = 20;\nauf diesem Speicherbereich ausführen und a wird auf der Adresse %p (erste Zelle) gespeichert. {a ist das Haus mit der Adresse %p, in dem die Zahl 20 wohnt.}:\n\n", &(tab->matrix[0][0]), &(tab->matrix[0][0]));
    
    tab->matrix[0][0] = 20;//C-Code-Ausführung simulieren
    
    RAM_print(tab); 
    enter();
    
    //Text
    printf("Pointer werden in C mit \"<Datentyp> *<Pointername> [= Initialisierung] ;\" erstellt. {Im Hausbeispiel: Ein leeres Adressblatt erzeugen.}\nWenn man nun dem Pointer auf eine andere Variable zeigen lassen möchte geht dies mit \"<Pointername> = &<Variablenname> ;\". {Im Hausbeispiel: Die Adresse eines bestimmten Haus auf den Adresszettel schreiben.}\nMit \" *<Pointername>\" bekommt man Zugriff auf den Speicherinhalt auf den der Pointer zeigt. {Im Hausbeispiel: Zur Adresse auf dem Adressblatt hingehen und in das Haus reinschauen, welche Zahl dort ist oder diese Zahl verändern.}\n\n");
    
    //Beispiel
    printf("Auch hierzu wollen wir wieder das vorherige Tabellenbeispiel nutzen. Dazu schauen wir uns den Speicherbereich der zukünftigen Pointer an:\n");
    RAM_print(tab_p);
    
    printf("Nun wollen wir einen Pointer \"p_a\" erzeugen, der auf die Variable a (aus dem vorherigen Beispiel) zeigt.\nDazu führen wir in C anschließend die folgenden Befehle aus:\n\tint *p_a; //Damit erstellen wir den Pointer, der aber noch auf nichts zeigt. {Leeres Blatt p_a}\n\tp_a = &a; //Nun zeigt p_a auf a. {Auf das Adressblatt p_a wird die Adresse zum Haus a geschrieben.}\nDamit sieht der Speicherbereich für den Pointer so aus:\n\n");
    
    tab_p->matrix_pointer[0][0] = &(tab->matrix[0][0]);//Simuliere C-Code
    
    RAM_print(tab_p);
    
    printf("Der Speicherbereich der Variabeln bleibt natürlich unverändert.\n");
    printf("Wenn wir nun mit dem Pointer den gespeicherten Wert in a (aktuell 20) um 77 erhöhen wollen, führen wir folgenden Code aus:\n\t*p_a = *p_a + 77;\n{Wir gehen zur Adresse auf dem Blatt p_a und addieren zu der dort wohnenden Zahl 77.}\nDann hat sich nur der Speicherbereich der Variabeln verändert:\n\n");
    
    tab->matrix[0][0] += 77;//Simuliere C-Code
    RAM_print(tab);
    
    tab=RAM_delete(tab);
    tab_p=RAM_delete(tab_p);
    enter();
    
    system("clear");
    printf("\n3. Pointer in C - Einführung\n*********************************************************\n"); 
    
    printf("Das schöne in C ist, dass C die Speicherverwaltung selber übernimmt, sodass wir Pointer wie folgt abstrahieren können:\nWir betrachten nicht mehr die Speicheradressen, sondern die Pointer als einen Pfeil p. Dieser Pfeil zeigt auf eine Variabel var:\n\tp ---> var\n\n");
    printf("Dazu ein Beispiel (ACHTUNG: Es handelt sich dabei NICHT um einen C-Code!):\nEs sind folgende Variabeln gegeben:\n\ta = 10, b = 20, c = 30\nund es soll ein Pointer p_a auf die Variable a und p_b auf b zeigen:\n\tp_a ----> a\n\tp_b ----> b\n");
    printf("Wenn wir nun diese Vorstellungsweise in C übertragen:\n\t-> \"(Datentyp)* (Pointername)\" erstellen wir einen Pfeil, der ins Nichts zeigt: p ---->\n\t\t=> Beispiel: int* p;\n\t-> \"(Pointername) = &(Variablenname)\" lässt den Pointer auf die gewünschte Variabel zeigen: p ----> var\n\t\t=> Beispiel: p = &var\n\t-> \"*(Pointername)\" erzeugt einen Zugriff auf die Variabel, auf der der Pointer zeigt.\n\t\t=> Beispiel: *p = 12 //Damit wird die Variabel, auf die p zeigt auf 12 gesetzt.\n");
    
    enter();
}