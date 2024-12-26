
#include <stdio.h>

int main(void)
{
    printf("| A | B | C | D || E | G | H | I | K | L | F | \n+---+---+---+---++---+---+---+---+---+---+---+\n");
    int a =0, b=0, c=0, d=0;
    int e=0,f=0,g=0,h=0,i=0,k=0,l=0;
    for(int counter=1; counter<=16; counter++)
    // or counter=0 till <16
    {
    e= (!b || !d || !a)&&d;
    g= (!b || !a)&&d;
    // h= d && !c;
    // i= b || !a;
    // k= !e || g;
    // l= !h || i;
    f= e==g;
    printf("| %i | %i | %i | %i || %i | %i | %i | %i | %i | %i | %i |\n", a,b,c,d,e,g,h,i,k,l,f);    
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
    if (f == 1)
        printf("\nF is True\n");
}

