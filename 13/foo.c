#include <stdio.h>
#include <stdlib.h>

int foo(int n){
    if(n<2)
        return n;
    else
        return (foo(n-1)+foo(n-2));
}

int main(){

    int n;
    printf("n:= ");
    scanf("%d", &n);

    printf("foo(%d) = %d\n", n, foo(n));

    return 0;
}

// btw this is just fibonacci
