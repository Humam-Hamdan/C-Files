#include <stdio.h>

int fibonacci(int n){
    int f1, f2;

    if ((n == 0) || (n == 1))
        return 1;
    else
    {
        printf("%d,", n); // nur für Quiz
        f1 = fibonacci(n - 1);
        f2 = fibonacci(n - 2);
        return f1 + f2;
    }
}

int main(void)
{
    int n;
    printf("Nummer der Fibonacci-Zahl: ");
    scanf("%d", &n);
    printf("\nDie %d-te Fibonacci-Zahl lautet %d.\n", n, fibonacci(n));
}