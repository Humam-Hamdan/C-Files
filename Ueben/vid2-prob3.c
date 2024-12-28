#include <stdio.h>
#include <stdbool.h>

int count_partition(int n, int m){
    bool niszero = (n==0);
    bool miszero = (m==0);
    bool nSmallerm = (n<0);
    if (niszero)
        return 1;
    else if (miszero || nSmallerm)
        return 0;
    else
        return count_partition((n-m),m)+count_partition(n,m-1);
}


int main(){
    int n,m;
    printf("Input n and m: ");
    scanf("%i %i", &n,&m);
    printf("The number of ways to partition %d objects using %i parts is %i\n", n,m,count_partition(n,m));

    return 0;
}
