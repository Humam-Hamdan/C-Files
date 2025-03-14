/************************************************/
/* Assessment II (06.12.2024)                   */
/* auto-generated .c file from text box input   */
/*                                              */
/* Humam Hamdan, 2427300                        */
/************************************************/

#include <stdio.h>

int ggT(int m, int n) { // Euklidischer Algorithmus
    int r;
    while (n != 0) {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

/* 
 * hier eine Funktion
 *    void kuerzen(  ,  )
 * implementieren
 */

void kuerzen( int *n , int *z){//+3P
    int t = ggT(*z, *n);//+1P
    *z = *z / t;
    *n = *n / t;
}//+1P

int main(void) {
    int z, n;

    printf("Zähler eingeben: ");
    scanf("%d", &z);

    printf("Nenner eingeben: ");
    scanf("%d", &n);

    kuerzen(&n,&z);//+2P
    
    printf("Nach dem Kürzen ist der Zähler %d, der Nenner %d.\n", z, n);
}
