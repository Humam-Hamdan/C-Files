#include <stdio.h>
#include <stdbool.h>


// input n and m. recursive function to calculate unique path from top left corner till bottom right one of a nxm grid


int grid_path(int n, int m){
    bool nisone = (n ==1);
    bool misone = (m ==1);

    if (nisone || misone)
        return 1;

    return grid_path(n,m-1)+grid_path(n-1,m);
}

int main(){
    int n=0,m=0;
    printf("Input n and m: ");
    scanf("%d %d",&n,&m);
    printf("\nThe Number of unique Paths in a %d by %d Grid is %d\n", n,m,grid_path(n,m));

    return 0;
}
