/**************************************/
/* Humam Hamdan                       */
/* Gruppe: Do.12                      */
/* Leiter: Florian Möschler           */
/* Uebungsblatt:11                      */
/* Aufgabe:    22                       */
/* Datum:     15jan                        */
/**************************************/

/*
 * Determine Number of Participants
 * Print a Line and expect the length of the number as input
 * save input
 * set passing grade
 * function which gives the name & number & grade of those who passed
*/

#include <stdio.h>

typedef struct Note{
    char Nachname[30];
    int MatrikelNum;
    int Note;
}Note;

void RedaWrite(Note *n){
    scanf("%s %i %f", n->Nachname, &n->MatrikelNum, &n->Note);
}

void Passed(Note *n, int pass_grade, int examinees){
    for(int i=0; i<examinees; i++){
        if(n[i].Note >= pass_grade){
            printf("%s passed with %f, the MatNum is %i\n", n[i].Nachname,n[i].Note,n[i].MatrikelNum);
        }
    }
}

int main(){

    int examinees;
    printf("how many examinees?\n");
    scanf("%i", &examinees);
    Note note[examinees];

    printf("Name Matrikelnummer Note\n");
    for(int i=0; i< examinees; i++){
        RedaWrite(&note[i]);
    }

    int pass_grade;
    printf("what is the passing grade?\n");
    scanf("%i", &pass_grade);

    Passed(note, pass_grade, examinees);
}
