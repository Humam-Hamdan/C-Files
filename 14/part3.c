#include <stdio.h>

extern double a;
void printA(void);

int main(void){
    printA();
    printf("a in part 3 = %lf", a);
}
