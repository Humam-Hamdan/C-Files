#include <stdio.h>
int main(){

char a[5] = {'a', 'b', 'c', 'd', 'e'};
int i;
char *p;

// vorwärts mit Index-Zugriff
for (i = 0; i <= 4; i++)
    printf(" %c", a[i]);

printf("\n");

// vorwärts mit Pointer
for (p = a; p <= &a[4]; p++)
    printf(" %c", *p);

printf("\n");

// vorwärts, Pointer mit „Offset“
for (p = a, i = 0; p + i <= &a[4]; p++, i++)
    printf(" %c", *(p + i));

printf("\n");

// rückwärts mit Pointer
for (p = &a[4]; p >= a; p--)
    printf(" %c", *p);

printf("\n");

// rückwärts mit negativem Index
for (p = &a[4], i = 0; i <= 4; i++)
    printf(" %c", p[-i]);

printf("\n");
}
