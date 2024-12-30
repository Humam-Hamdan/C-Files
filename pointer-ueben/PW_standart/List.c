/*
Author: Leon Wengenroth
Mail: leon.wengenroth-hk@uni-wuppertal.de
Thema: Erstellen, Lesen und Manipulieren einer einfach verketten Liste
*/

#include <stdlib.h>
#include <stdio.h>
#include "List.h"

//INTEGER

//Funktionen
struct List_int* LIST_int_create(struct List_int* s){ //Erstelle die Liste    
    s = (struct List_int*) malloc(sizeof(struct List_int));
    s->start = NULL;
    s->n = 0;
    return s;
}

struct List_int* LIST_int_push(struct List_int* s, const unsigned pos, const int data){   //Packe das Datum data vor die Position (=> pos==n => Datum am Ende einfügen)
        
    if(pos > s->n){ //Falls das Ziel außerhalb liegt
        perror("!!!Function LIST_int_push: pos too high!!!\n");
        exit(EXIT_FAILURE);
    }
         
    //Erzeuge neues Element
    struct Element_int* p_ele_new = (struct Element_int*) malloc(sizeof(struct Element_int));
        
    //Speichere Datum ab
    p_ele_new->data = data;
        
    //Gehe zur Position
    struct Element_int* p_ele_pos = s->start; //Zeigt nachher auf die Position pos
    struct Element_int* p_ele_tmp = NULL; //Zeigt immer hinter pos
    
    
    for(int i=0; i<pos; i++){
        p_ele_tmp = p_ele_pos;
        p_ele_pos = p_ele_pos->next;
    }
        
    //Packe das neue Element vor den Zeiger
    p_ele_new->next = p_ele_pos;

    if(pos==0) //Am Listenanfang muss anders verknüpft werden
        s->start = p_ele_new;
    else
        p_ele_tmp->next = p_ele_new;
    
    //Aktualisiere die Anzahl
    (s->n)++;
    
    
    return s;
}



int LIST_int_get(struct List_int* s, const unsigned pos){ //Rückgabe des pos. Element aus der Liste
    
    if(pos >= s->n){ //Falls das Ziel außerhalb liegt
        perror("!!!Function LIST_int_get: pos too high!!!\n");
        exit(EXIT_FAILURE);
    }
    
    //Erzeuge Zeiger zur gewünschten Position
    struct Element_int* p_ele_pos = s->start;
        
    for(int i=0; i<pos; i++)
        p_ele_pos = p_ele_pos->next;
    
    return p_ele_pos->data;
}



int LIST_int_pop(struct List_int* s, const unsigned pos){ //Diese Funktion löscht das Element an Position pos und gibt den gelöschten Wert zurück
    
    if(pos >= s->n){ //Falls das Ziel außerhalb liegt
        perror("!!!Function LIST_int_pop: pos too high!!!\n");
        exit(EXIT_FAILURE);
    }
    
     //Erzeuge Zeiger zur gewünschten Position
    struct Element_int* p_ele_pos = s->start;
    struct Element_int* p_ele_tmp = NULL; //Zeigt vor pos
        
    for(int i=0; i<pos; i++){
        p_ele_tmp = p_ele_pos;
        p_ele_pos = p_ele_pos->next;
    }  
    
    //Speichere den Inhalt des zu löschenden Element ab
    int data = p_ele_pos->data;
    
    //Biege den Zeiger um
    if(pos == 0)
        s->start = p_ele_pos->next;
    else
        p_ele_tmp->next = p_ele_pos->next;
    
    //Lösche das Element
    free(p_ele_pos);
    
    //Passe Anzahl an
    (s->n)--;
    
    return data;
}


unsigned LIST_int_clear(struct List_int*s){ //Lösche alle enthaltenen Elemente der Liste; Rückgabe ist die Anzahl der gelöschten Elementen
    
    unsigned sol=0;
    struct Element_int* p_ele_tmp;
    
    while(s->start != NULL){
        //Biege Zeige auf das nächste Element
        p_ele_tmp = s->start;
        s->start = s->start->next;
        
        //Lösche Element, welches aus der Liste entfernt wurde
        free(p_ele_tmp);
        
        //Aktualisiere Anzahl
        sol++;
    }
    
    s->n = 0;
    return sol;
}


struct List_int* LIST_int_delete(struct List_int* s){ //Lösche die komplette Liste
    LIST_int_clear(s);
    free(s);
    return s;
}



//DOUBLE
struct List_doub* List_doub_create(struct List_doub* s){ //Erstelle die Liste    
    s = (struct List_doub*) malloc(sizeof(struct List_doub));
    s->start = NULL;
    s->n = 0;
    return s;
}

struct List_doub* LIST_doub_push(struct List_doub* s, const unsigned pos, const double data){   //Packe das Datum data vor die Position (=> pos==n => Datum am Ende einfügen)
        
    if(pos > s->n){ //Falls das Ziel außerhalb liegt
        perror("!!!Function LIST_doub_push: pos too high!!!\n");
        exit(EXIT_FAILURE);
    }
         
    //Erzeuge neues Element
    struct Element_doub* p_ele_new = (struct Element_doub*) malloc(sizeof(struct Element_doub));
        
    //Speichere Datum ab
    p_ele_new->data = data;
        
    //Gehe zur Position
    struct Element_doub* p_ele_pos = s->start; //Zeigt nachher auf die Position pos
    struct Element_doub* p_ele_tmp = NULL; //Zeigt immer hinter pos
    
    
    for(int i=0; i<pos; i++){
        p_ele_tmp = p_ele_pos;
        p_ele_pos = p_ele_pos->next;
    }
        
    //Packe das neue Element vor den Zeiger
    p_ele_new->next = p_ele_pos;

    if(pos==0) //Am Listenanfang muss anders verknüpft werden
        s->start = p_ele_new;
    else
        p_ele_tmp->next = p_ele_new;
    
    //Aktualisiere die Anzahl
    (s->n)++;
    
    
    return s;
}



double LIST_doub_get(struct List_doub* s, const unsigned pos){ //Rückgabe des pos. Element aus der Liste
    
    if(pos >= s->n){ //Falls das Ziel außerhalb liegt
        perror("!!!Function LIST_doub_get: pos too high!!!\n");
        exit(EXIT_FAILURE);
    }
    
    //Erzeuge Zeiger zur gewünschten Position
    struct Element_doub* p_ele_pos = s->start;
        
    for(int i=0; i<pos; i++)
        p_ele_pos = p_ele_pos->next;
    
    return p_ele_pos->data;
}



double LIST_doub_pop(struct List_doub* s, const unsigned pos){ //Diese Funktion löscht das Element an Position pos und gibt den gelöschten Wert zurück
    
    if(pos >= s->n){ //Falls das Ziel außerhalb liegt
        perror("!!!Function List_doub_pop: pos too high!!!\n");
        exit(EXIT_FAILURE);
    }
    
     //Erzeuge Zeiger zur gewünschten Position
    struct Element_doub* p_ele_pos = s->start;
    struct Element_doub* p_ele_tmp = NULL; //Zeigt vor pos
        
    for(int i=0; i<pos; i++){
        p_ele_tmp = p_ele_pos;
        p_ele_pos = p_ele_pos->next;
    }  
    
    //Speichere den Inhalt des zu löschenden Element ab
    double data = p_ele_pos->data;
    
    //Biege den Zeiger um
    if(pos == 0)
        s->start = p_ele_pos->next;
    else
        p_ele_tmp->next = p_ele_pos->next;
    
    //Lösche das Element
    free(p_ele_pos);
    
    //Passe Anzahl an
    (s->n)--;
    
    return data;
}


unsigned LIST_doub_clear(struct List_doub*s){ //Lösche alle enthaltenen Elemente der Liste; Rückgabe ist die Anzahl der gelöschten Elementen
    
    unsigned sol=0;
    struct Element_doub* p_ele_tmp;
    
    while(s->start != NULL){
        //Biege Zeige auf das nächste Element
        p_ele_tmp = s->start;
        s->start = s->start->next;
        
        //Lösche Element, welches aus der Liste entfernt wurde
        free(p_ele_tmp);
        
        //Aktualisiere Anzahl
        sol++;
    }
    
    s->n = 0;
    return sol;
}

struct List_doub* LIST_doub_delete(struct List_doub* s){ //Lösche die komplette Liste
    LIST_doub_clear(s);
    free(s);
    return s;
}