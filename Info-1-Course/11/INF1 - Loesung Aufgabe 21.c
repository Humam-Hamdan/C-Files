/**************************************/
/* Humam Hamdan                       */
/* Gruppe: Do.12                      */
/* Leiter: Florian Möschler           */
/* Uebungsblatt:11                      */
/* Aufgabe:   21                        */
/* Datum:     15Jan                        */
/**************************************/

/*
 * STRUCT with 1 int 2 floats.
 * Function to read & write
 * funktion to get the endresult
*/

#include <stdio.h>

typedef struct Werbung{
    int Anzahl;
    float P; // P für probability
    float Eur; // Euro
} Werbung;



void ReadWrite(Werbung *wer){
    printf("Zahl der Werbung? \nClick Wahrscheinlichkeit? \nwie viel Euro pro Click?\n");
    scanf("%d %f %f", &(wer->Anzahl), &(wer->P), &(wer->Eur));
}

float MulWerb(Werbung wer){
    return wer.Anzahl * wer.P * wer.Eur;
}

int main(){
    Werbung wer;
    ReadWrite(&wer);
    printf("Gewinn ist %.2f €\n" ,MulWerb(wer));
    return 0;
}
