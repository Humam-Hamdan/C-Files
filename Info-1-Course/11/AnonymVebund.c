
#include <stdio.h>

// ein Term hat die Form „Zahl0 Operand Zahl1“, z.B. 2.3 + 3.5
typedef struct
{
    double zahl[2];
    char op;
} Term;

int main(void)
{
    // Namen ermöglichen Belegung der Komponenten in beliebiger Reihenfolge
    Term t = { .zahl[0] = 2.3, .op = '+', .zahl[1] = 3.5 };

    printf("%f %c %f\n", t.zahl[0], t.op, t.zahl[1]);

    // spätere Zuweisung mit „anonymen Strukturen“ und Cast möglich;
    // nicht vorgegebene Komponenten werden 0
    t = (Term){ .zahl[1] = 4.7, .op = '/' };

    printf("%f %c %f\n", t.zahl[0], t.op, t.zahl[1]);

    return 0;
}
