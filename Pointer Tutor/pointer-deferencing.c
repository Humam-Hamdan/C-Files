#include <stdio.h>

int main(){

int myValue = 50;
int *myPointer = &myValue;
printf("Value: %d, %p \n", myValue, (void*)myPointer);
*myPointer = 100;
printf("Value %d,%p\n", myValue, (void*)myPointer);
int **doublePointer = &myPointer;
printf("doublePointer Value: %p\n", (void*)doublePointer);
**doublePointer = 200;
printf("Value %d, %p,%p", myValue, (void*)myPointer,(void*)doublePointer);
}
