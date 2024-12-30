/*
Author: Leon Wengenroth
Mail: leon.wengenroth-hk@uni-wuppertal.de
Thema: Erstellen, Lesen und Manipulieren einer einfach verketten Liste
*/

#ifndef LIST
#define LIST

#include <stdlib.h>
#include <stdio.h>

//INTEGER

//Datenstrukturen
struct Element_int{ //Dieses Element wird in der Liste gespeichert
    int data; //Datum des Elements
    struct Element_int* next; //Zeiger auf das nächste Element
};

struct List_int{ //Dies ist eine einfach verkette Liste mit den Elementen 0 bis n-1, wobei n das Ende symbolisiert
    int n; //Anzahl der in der Liste enthaltene Elemente
    struct Element_int* start;
};

//Funktionen
struct List_int* LIST_int_create(struct List_int* s); //Erstelle die Liste

struct List_int* LIST_int_push(struct List_int* s, const unsigned pos, const int data);   //Packe das Datum data vor die Position (=> pos==n => Datum am Ende einfügen)
        
int LIST_int_get(struct List_int* s, const unsigned pos); //Rückgabe des pos. Element aus der Liste

int LIST_int_pop(struct List_int* s, const unsigned pos); //Diese Funktion löscht das Element an Position pos und gibt den gelöschten Wert zurück

unsigned LIST_int_clear(struct List_int* s); //Lösche alle enthaltenen Elemente der Liste; Rückgabe ist die Anzahl der gelöschten Elementen

struct List_int* LIST_int_delete(struct List_int* s); //Lösche die komplette Liste


//DOUBLE

//Datenstrukturen
struct Element_doub{ //Dieses Element wird in der Liste gespeichert
    double data; //Datum des Elements
    struct Element_doub* next; //Zeiger auf das nächste Element
};

struct List_doub{ //Dies ist eine einfach verkette Liste mit den Elementen 0 bis n-1, wobei n das Ende symbolisiert
    int n; //Anzahl der in der Liste enthaltene Elemente
    struct Element_doub* start;
};

//Funktionen
struct List_doub* LIST_doub_create(struct List_doub* s); //Erstelle die Liste


struct List_doub* LIST_doub_push(struct List_doub* s, const unsigned pos, const double data);  //Packe das Datum data vor die Position (=> pos==n => Datum am Ende einfügen)

double LIST_doub_get(struct List_doub* s, const unsigned pos); //Rückgabe des pos. Element aus der Liste


double LIST_doub_pop(struct List_doub* s, const unsigned pos); //Diese Funktion löscht das Element an Position pos und gibt den gelöschten Wert zurück

unsigned LIST_doub_clear(struct List_doub* s); //Lösche alle enthaltenen Elemente der Liste; Rückgabe ist die Anzahl der gelöschten Elementen

struct List_doub* LIST_doub_delete(struct List_doub* s); //Lösche die komplette Liste

#endif