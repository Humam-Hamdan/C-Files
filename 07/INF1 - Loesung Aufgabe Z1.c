/**************************************/
/* Humam Hamdan                       */
/* Gruppe: Do.12                      */
/* Leiter: Florian Möschler           */
/* Uebungsblatt: 7   , Aufgabe: Z1    */
/* Datum:     4 Dez                   */
/* Status:  not working never will be */
/**************************************/

#include <stdio.h>

int main(void){

int a = 7, b = a;
char *pc, c='9';
int ***pppi, **ppi, *pi;

// pi = 100;
// printf("%d,%d,%s,%d,%p,%p,%ls", a,b,pc,c,pppi,ppi,pi);

*pi= b+4;
printf("%d,%d,%s,%d,%p,%p,%p", a,b,pc,c,pppi,ppi,pi);

//pppi = &ppi;
//printf("%d,%d,%s,%d,%p,%p,%ls", a,b,pc,c,pppi,ppi,pi);

//**pppi = &b;
//printf("%d,%d,%s,%d,%p,%p,%ls", a,b,pc,c,pppi,ppi,pi);

//***pppi = &b - 103;
//printf("%d,%d,%s,%d,%p,%p,%ls", a,b,pc,c,pppi,ppi,pi);

//a = **ppi + 2*b;
//printf("%d,%d,%s,%d,%p,%p,%ls", a,b,pc,c,pppi,ppi,pi);

}