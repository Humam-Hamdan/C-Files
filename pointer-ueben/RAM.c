/*
Author: Leon Wengenroth
Mail: leon.wengenroth-hk@uni-wuppertal.de
Thema: Erstelle virtuellen Speicherbereich / RAM
*/

#include "RAM.h"


struct RAM_Table* RAM_create(const unsigned m, const unsigned n, enum BOOL pointer)//Erzeuge die RAM-Tabelle und initialisiere alle Werte + erzeuge dynamische matrix (Matrix mit Nullen direkt gefüllt) und gebe Zeiger auf RAM-Tabelle zurück. Eingabe ist die Größe der Matrix, sowie soll die Pointermatrix genutzt werden (pointer)
{
    //Lege RAM_Tabele an
    struct RAM_Table* tab = (struct RAM_Table*) malloc(sizeof(struct RAM_Table));
    
    if(pointer){ //Welche Matrixart soll angelegt werden
        //Lege Matrix mit gespeicherten Pointern an
        tab->matrix_pointer = (int***) malloc(m * sizeof(int**));

        for(int i=0; i<m; i++){
            tab->matrix_pointer[i]= (int**)malloc(n * sizeof(int*));
            for(int j=0; j<n; j++)
                tab->matrix_pointer[i][j] = NULL;
        }
        
        tab->matrix = NULL; //Kennzeichne die andere Matrix als nicht verwendet
    }else{
        //Lege normale Matrix an
        tab->matrix = (int**) malloc(m * sizeof(int*));

        for(int i=0; i<m; i++)
            tab->matrix[i]= (int*)calloc(n, sizeof(int));
        
        tab->matrix_pointer = NULL; //Kennzeichne die andere Matrix als nicht verwendet
    }
    
    //Initialisiere DIE Matrix-Größe
    tab->m = m;
    tab->n = n;
    
    return tab;
}

struct RAM_Table* RAM_rand(struct RAM_Table* tab) //Initialisiert die eingegebende mxn Matrix mit zufälligen Werten von 0 bis 99 und gibt diese wieder zurück
{
    if(tab->matrix != NULL){ //Matrix ohne Pointern
        for(int i=0; i<tab->m; i++)
            for(int j=0; j<tab->n; j++)
                tab->matrix[i][j] = rand()%100;
        
    }else{ //Matrix mit Pointern
        for(int i=0; i<tab->m; i++)
            for(int j=0; j<tab->n; j++)
                tab->matrix_pointer[i][j] = (int*) (rand()%(sizeof(int)*8));
    } 
    return tab;
}

struct RAM_Table* RAM_rand_area(struct RAM_Table* tab, const unsigned long beg, const unsigned long end) //Initialisiert die eingegebende mxn Matrix mit zufälligen Werten von beg bis end und gibt diese wieder zurück
{
    if(tab->matrix != NULL){ //Matrix ohne Pointern
        for(int i=0; i<tab->m; i++)
            for(int j=0; j<tab->n; j++)
                tab->matrix[i][j] = rand()%(end+1-beg) + beg;
        
    }else{ //Matrix mit Pointern
        for(int i=0; i<tab->m; i++)
            for(int j=0; j<tab->n; j++)
                tab->matrix_pointer[i][j] = (int*) (rand()%(end+1-beg) + beg);
    }
    return tab;
}


void RAM_print(struct RAM_Table* tab) //Diese Funktion gibt die RAM-Tabelle aus
{
    if(tab->matrix != NULL) //Bestimme welche Matrizenart ausgegeben wird
        //Matrix ohne Pointern
        for(int i=0; i<tab->m; i++) //Für jede Zeile
        {              
            //Ausgabe der Adressen
            printf("Adresse: ");
            for(int j=0; j<tab->n; j++)
                printf("|%14p", &(tab->matrix[i][j]));

            printf("|\n---------");

            //Ausgabe des Trenners 
            for(int j=0; j<tab->n; j++)
                printf("|--------------");
            printf("|\nInhalt:  ");

            for(int j=0; j<tab->n; j++)
                printf("|      %2d      ", tab->matrix[i][j]);

            printf("|\n\n");
        }
    else //Matrix mit Pointern
        for(int i=0; i<tab->m; i++) //Für jede Zeile
        {              
            //Ausgabe der Adressen
            printf("Adresse: ");
            for(int j=0; j<tab->n; j++)
                printf("|%14p", &(tab->matrix_pointer[i][j]));

            printf("|\n---------");

            //Ausgabe des Trenners 
            for(int j=0; j<tab->n; j++)
                printf("|--------------");
            printf("|\nInhalt:  ");

            for(int j=0; j<tab->n; j++)
                if(tab->matrix_pointer[i][j] == NULL) //Gebe Speicherzelen mit NULL leer aus
                    printf("|              ");
                else
                    printf("|%14p", tab->matrix_pointer[i][j]);

            printf("|\n\n");
        }
}

struct RAM_Table* RAM_delete(struct RAM_Table* tab) //Lösche die Matrix
{
    if(tab->matrix != NULL){ //Bestimme welche Matrizenart verwendet wurde
        //Lösche matrix
        for(int i=0; i < tab->m; i++)
            free( tab->matrix[i] );

        free(tab->matrix);
    }else{
        //Lösche matrix_pointer
        for(int i=0; i < tab->m; i++)
            free( tab->matrix_pointer[i] );

        free(tab->matrix_pointer);
    }
        
    //Lösche RAM_Tabelle
    free(tab);
    tab = NULL;
    return tab;
}



