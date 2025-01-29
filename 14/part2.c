#include <stdio.h>

extern double a;

void printA(void){
    printf("a in part 2 = %lf", a);
    a =7.0;
}
