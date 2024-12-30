/*
Author: Leon Wengenroth
Mail: leon.wengenroth-hk@uni-wuppertal.de
Thema: Pointer
*/

#include <stdio.h>

#include "../RAM.h"
#include "chapters.h"
#include "../PW_standart/input.h"


//Kapitel 1
void kap1(void){  
    //Variabelndeklaration
    struct RAM_Table* tab;   
    //Verschiedene Eingaben des Benutzers
    int input_i, *input_p;   
    
    //Abspeichern von Variabeln
    tab = RAM_create(1, 4, false);
    
    printf("1. Abspeichern von Variabeln\n*********************************************************\n");
    printf("Vereinfacht besteht ein Rechner aus sehr vielen Speicherzellen, welche hintereinander liegen. Jede Speicherzelle besitzt dabei eine eigene Adresse und man kann eine Zahl oder einen Buchstaben in eine Speicherzelle speichern.\nGezeigt ist nun ein Abschnitt aus dem Speicher mit 4 Speicherzellen:\n\n");

    RAM_print(tab);
        
    enter(); //Mit Enter fortfahren
    
    printf("Nun könnte man beispielsweise in die erste Speicherzelle mit der Adresse %p eine \"5\" abspeichern.\n\n", &(tab->matrix[0][0]));
    tab->matrix[0][0] = 5;
    RAM_print(tab);
       
    enter(); //Mit Enter fortfahren
    
    //1.Aufgabe: Verstehen, wie Variabeln im RAM abgespeichert werden
    tab = RAM_delete(tab);
    tab = RAM_create(1, 10, false);
    
    do{
        system("clear");
        printf("1. Abspeichern von Variabeln\n*********************************************************\n");
        printf("Aufgabe 1.1 \n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        
        int pos = rand() % tab->n; //Position der Variable var in der 1xn-Matrix
                
        RAM_rand(tab);  

        printf("\n");
        RAM_print(tab);
        
        //Aufgabenstellung
        printf("Angenommen der Inhalt der Variable \"var\" würde in die Speicherzelle mit der Speicheradresse %p abgespeichert sein. Welchen Wert hat aktuell var?\n[Hinweis: Bei den Adressen unterscheiden sich nur die letzten 2 bis 3 Ziffern]\n", &(tab->matrix[0][pos]));
        scan("%d", &input_i);
        
        //Gebe aus, ob die Antwort korrekt war:
        if(input_i == tab->matrix[0][pos])
            printf("\nDie Antwort ist richtig.\n");
        else
            printf("\nDie Antwort ist falsch. Die richtige Antwort wäre %d.\n", tab->matrix[0][pos]);
        
    }while(next());
    
    tab=RAM_delete(tab);
    
    
     //2. Aufgabe: Rechenaufgaben mit dem Speicher
    do{
        system("clear");
        printf("1. Abspeichern von Variabeln\n*********************************************************\n");
        printf("Aufgabe 1.2 \n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("Nun wird es etwas kniffliger:\n");
        
        int a = rand()%49 + 1 , b=rand()%49 + 1 , c = a + b; //zufällige Werte dürfen nicht gleich Null sein, sonst c=a oder C=b möglich => Zufällige Werte aus der 1.Zeile, die = c sind, nicht mehr so eliminierbar
        int pos_a = rand()%9 , pos_b = rand()%9, pos_c = rand() % 10; //Zufällige Positionen der Variabeln a und b im RAM tab in der Zeile 0 der Matrix und c in Zeile 1
        if(pos_b == pos_a) //Vermeide den Fall, dass a und b die gleichen Positionen haben => vorher Spalte 9 konnte vorher nicht belegt werden
            pos_b = 9;
        
        //Erstelle für jeden Durchlauf einen neuen RAM auf tab
        tab = RAM_create(2, 10, false);
        RAM_rand_area(tab, c - 10, c + 10);
        
        //Eliminiere in der matrix
        for(int i=0; i < tab->n; i++){
            //Sichere, dass a und b nicht schon in der matrix steht
            if(tab->matrix[0][i] == a || tab->matrix[0][i] == b)
                tab->matrix[0][i]++;
            
            //Sichere, dass nicht schon c in der Matrix steht 
            if(tab->matrix[0][i] == c)  
                tab->matrix[0][i]++;
            
            if(tab->matrix[1][i] == c)  
                tab->matrix[1][i]++;

        }
        
        //Speichere die Lösung in die matrix
        tab->matrix[0][pos_a] = a;
        tab->matrix[0][pos_b] = b;
        tab->matrix[1][pos_c] = c;
        
        //Aufgabenstellung        
        printf("Angenommen die Variablen \"a\" und \"b\" sind auf dem folgenden Speicherausschnitt gespeichert. Dabei hat a die Speicheradresse %p und b die Speicheradresse %p.\nNun wird im C-Programm die Operation \"c = a + b;\" ausgeführt.\nWelche Speicheradresse hat die Variable c?\nBitte geben Sie die vollständige Speicheradresse an.\n[Tipp: Im Terminal können Sie mit STRG + EINFG kopieren und mit SHIFT + EINFG einfügen] \n[Hinweis: Bei den Adressen unterscheiden sich nur die letzten 3 bis 4 Ziffern]\n\n", &(tab->matrix[0][pos_a]), &(tab->matrix[0][pos_b]));
        
        RAM_print(tab);
        
        //Gebe das Ergebnis aus
        scan("%p", &input_p);
        if(input_p == &(tab->matrix[1][pos_c]))
            printf("Die Antwort ist richtig.\n");
        else
            printf("Die Antwort ist falsch.\n");
            
        tab=RAM_delete(tab);
    }while(next());
    
}