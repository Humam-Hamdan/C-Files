/*
Author: Leon Wengenroth
Mail: leon.wengenroth-hk@uni-wuppertal.de
Thema: Pointer
*/

#include <stdio.h>

#include "../RAM.h"
#include "chapters.h"
#include "../PW_standart/input.h"


//Kapitel 2
void kap2(void){  
    //Variabelndeklaration
    struct RAM_Table* tab, *tab_p;   
    //Verschiedene Eingaben des Benutzers
    int input_i;
    

    //Erstelle Matrizen
    tab = RAM_create(1, 4, false);
    tab_p = RAM_create(1, 3, true);
    
    //Fülle Matrizen
    tab->matrix[0][0] = 5;
    tab_p->matrix_pointer[0][0] = &(tab->matrix[0][0]);
    
    //Text
    printf("\n2. Statt Variabeln Adressen speichern\n*********************************************************\n");
    printf("Jedoch kann man in C in einer Speicherzelle \"S1\" nicht nur eine Variabel speichern, sondern auch wiederum eine Adresse \"A\". Mit dieser gespeicherten Adresse \"A\" kann man somit die zugehörige Speicherzelle \"S2\" mit der Adresse \"A\" ermitteln. Damit \"zeigt\" \"S1\" auf \"S2\" oder anders gesagt \"S1\" ist ein Pointer auf \"S2\".\nVeranschaulichen wir das mal an einem Beispiel:\n\n");
    
    //Beispiel mit Matrizen
    printf("Stellen wir uns vor, dass folgender \"normaler\" Speicherbereich gegeben ist:\n\n");
    RAM_print(tab);
    
    printf("Nun nehmen wir einen 2. leeren Speicherbereich und speichern die Adresse der ersten Zelle mit dem Inhalt \"5\" aus dem obrigen Speicherbereich in der ersten Zelle des neuen Speicherbereiches:\n\n");
    RAM_print(tab_p);
    
    printf("Somit haben wir im 2. Speicherbereich einen Pointer (mit der Adresse %p) erzeugt, der auf den 1. Speicherbereich zeigt, in dem die \"5\" gespeichert ist.\nWir können uns also den Inhalt der ersten Zelle des 2. Speicherbereiches (mit der Adresse %p) ansehen. Nehmen wir nun deren Inhalt (%p) können wir damit geziehlt die erste Zelle des 1. Speicherbereiches ermitteln (welche ja diese Adresse hat) und auf deren Inhalt (die \"5\") zugreifen.\n", &(tab_p->matrix_pointer[0][0]), &(tab_p->matrix_pointer[0][0]), tab_p->matrix_pointer[0][0]);
    
    printf("\nEin abstraktes Beispiel:\nSie können sich eine Variabel wie ein Haus vorstellen, in welchem man eine Zahl (Inhalt der Variabel) reinpacken kann. Das Haus hat auch eine Adresse (Speicheradresse). Nun wäre in diesem Beispiel ein Pointer ein Blatt auf dem die Adresse eines Hauses steht. Mit diesem Adressblatt kann man also das Haus finden und reinschauen, welche Zahl drinsteckt oder durch eine andere ersetzen.\n");
        
    //Lösche Matrizen
    tab=RAM_delete(tab);
    tab_p=RAM_delete(tab_p);
    
    enter();
    
    //3. Aufgabe: Gespeicherte Werte hinter den Pointern finden
    do{
        system("clear");
        printf("\n2. Statt Variabeln Adressen speichern\n*********************************************************\n");
        printf("\nAufgabe 2.1 \n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
        //Erstelle Tabellen
        tab = RAM_create(1, 10, false);
        tab_p = RAM_create(1, 10, true);
        
        //Generiere zufällige Positionen für die Lösung
        int pos = rand()%10, pos_p = rand() % 10;
        
        //Füllen Tabelleninhalt
        RAM_rand(tab);
        RAM_rand_area(tab_p, (unsigned long) &(tab->matrix[0][pos]) - 100, (unsigned long) &(tab->matrix[0][pos]));
        
        tab_p->matrix_pointer[0][pos_p] = &(tab->matrix[0][pos]);
        
        //Aufgabenstellung
        printf("Sei nun folgender Speicherbereich mit Pointern gegeben:\n\n");
        RAM_print(tab_p);
        
        printf("Welche Zahl steht in dem folgenden Speicherbereich, auf den der Pointer in der Adresse %p zeigt?\n[Tipp: Ermitteln sie zuerst die Speicheradresse, auf die der Pointer zeigt]\n[Hinweis: Bei den Adressen unterscheiden sich nur die letzten 2 bis 3 Ziffern]\n\n", &(tab_p->matrix_pointer[0][pos_p]));
        RAM_print(tab);
        
        //Antwort
        scan("%d", &input_i);
        if(input_i == tab->matrix[0][pos])
            printf("Die Antwort ist richtig.\n");
        else
            printf("Die Antwort ist falsch.\n");
        
        //Lösche Tabellen
        tab=RAM_delete(tab);
        tab_p=RAM_delete(tab_p);
    }while(next());
    
}