#include <stdio.h>
#include <stdbool.h>

bool isprime(int p)
{
    int t;
    bool dividerfound;

    dividerfound=false;

    for(t=2;t<p;t++)
    {
        if (p%t ==0)
            dividerfound=true;
    }

    return !dividerfound;
}

int main()
{
    int limit;

    printf("Obergrenze eingeben: ");
    scanf("%d", &limit);

    for(int p=3; p+2 <= limit; p +=2)
    {
        if( isprime(p) && isprime(p+2) )
            printf("%d und %d\n", p, p+2);
    }
}