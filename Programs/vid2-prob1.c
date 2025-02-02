#include <stdio.h>

// Recrusion Sum till n. the formula is n+(n-1).

int sum_rec(int n){
    if (n==0)
        return 0;

    return n + sum_rec(n-1);
}

int main(){
    int n;
    printf("Input the number: ");
    scanf("%i",&n);
    printf("The Sum of 0 to %i is equal to %i\n", n, sum_rec(n));
}
