
/*
F = A land neg B ) imp (C lor neg D)) equiv ( D land neg C ) imp B lor neg A )
A
B
C
D
E = A land neg B
G = C lor neg D
H = D land neg C
I = B lor neg A 
K = E imp G
L = H imp I
F = K == L

--- PS Code

Set a,b,c,d & counter
till counter =16:
    // coz otherwise firs value of f=0 but should be 1.
    set rest operations
    print(...)

    d+=1
    if d%2 ==0
        c+=1
        if c%2 ==0
            b+=1
            if b%2==0
            a+=1
*/

#include <stdio.h>

int main(void)
{
    printf("| A | B | C | D || E | G | H | I | K | L | F | \n+---+---+---+---++---+---+---+---+---+---+---+");
    int a =0, b=0, c=0, d=0;
    int e=0,f=0,g=0,h=0,i=0,k=0,l=0;
    for(int counter=0; counter<16; counter++)
    {
    e= a && !b;
    g= c || !d;
    h= d && !c;
    i= b || !a;
    k= !e || g;
    l= !h || i;
    f= k==l;
    printf("\n| %i | %i | %i | %i || %i | %i | %i | %i | %i | %i | %i |\n", a,b,c,d,e,g,h,i,k,l,f);    
        d++;
        if (d%2 ==0)
        {
            d=0;
            c++;
            if(c%2 ==0)
            {
                c=0;
                b++;
                if(b%2 ==0)
                {
                    b=0;
                    a++;
                }    
            }
        }
    }
}

/*
Loseung

int a,b,c,d,e,f,g,h,i,k,l;
for(int z=0; z<16; z++)
{
    a=z/8%2;
    b=z/4%2;
    c=z/2%2;
    d=z%2;

    e=a&&!b;
    g=c||!d;
    h=d&&!c;
    i=b||!a;
    k=!e||g;
    l=!h||i;
    f=k==l;

    alle printfs
}

*/
