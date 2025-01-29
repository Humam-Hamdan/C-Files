#include <stdio.h>

int poly(int x){
    return 3 * x * x + 2 * x + 10;
}

static inline int polyi(int x){
    return 3 * x * x + 2 * x + 10;
}

#define POLY(x) ( 3 * (x) * (x) + 2 * (x) + 10 )

int main(){
    int a=2,b=2,c=2;

    printf("%d %d %d\n", poly(a+1), polyi(b+1), POLY(c+1));

    printf("%d %d %d\n", poly(++a), polyi(++b), POLY(++c));
}
