/*
Author: Leon Wengenroth
Mail: leon.wengenroth-hk@uni-wuppertal.de
Thema: Erstelle virtuellen Speicherbereich / RAM
*/

#ifndef BOOL_own
#define BOOL_own
enum BOOL{FALSE=0, TRUE=1};
#endif

#ifndef RAM
#define RAM

#include <stdio.h>
#include <stdlib.h>

struct RAM_Table
{
    int** matrix; //gespeicherte Werte im RAM, 2x2-Matrix => m Größe bestimmt die Ausgabe
    int m,n; //Größe der m x n-Matrix
    int*** matrix_pointer; //Alternativ kann diese Matrix genutzt werden. Dann sin dnicht mehr Zahlen, sondern Pointer in dieser m x n Matrix gespeichert. Es kann aber nur eine der Matrizen genutzt werden.
};

struct RAM_Table* RAM_create(const unsigned m, const unsigned n, enum BOOL pointer);//Erzeuge die RAM-Tabelle und initialisiere alle Werte + erzeuge dynamische matrix (Matrix mit Nullen direkt gefüllt) und gebe Zeiger auf RAM-Tabelle zurück. Eingabe ist die Größe der Matrix, sowie soll die Pointermatrix genutzt werden (pointer)

struct RAM_Table* RAM_rand(struct RAM_Table* tab); //Initialisiert die eingegebende mxn Matrix mit zufälligen Werten von 0 bis 99 und gibt diese wieder zurück

struct RAM_Table* RAM_rand_area(struct RAM_Table* tab, const unsigned long beg, const unsigned long end); //Initialisiert die eingegebende mxn Matrix mit zufälligen Werten von beg bis end und gibt diese wieder zurück

void RAM_print(struct RAM_Table* tab); //Diese Funktion gibt die RAM-Tabelle aus

struct RAM_Table* RAM_delete(struct RAM_Table* tab); //Lösche die Matrix

#endif
