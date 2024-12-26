#include <stdio.h>

int maximum(int f[], int laenge) {
    int m = f[0];
    for (int i=1; i<laenge; i++) 
        m = (m < f[i]) ? f[i] : m;
    return m;
}



int main() {
    enum {N=20};
    const int max_sterne = 60;
    int anzahl=0, i;
    int balken[N+1] = {};
    int max;
    
    while ( scanf("%d",&i) != EOF  ){
        balken[i]++;
        anzahl++;
    }
    
    max = maximum(balken,N+1); 
    
    for (int j=0; j<= N; j++) {
        printf("%2d: %10d ", j, balken[j]);
        for (int k = 1; k <= (max_sterne*balken[j])/max; k++) {
            printf("*");
        }
        printf("\n");
    } 
    
}

