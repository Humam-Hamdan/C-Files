#include <stdio.h>
#include <stdbool.h>
// Berechnung der Fakultät n! = 1 · 2 · … · (n − 1) · n
// einer einzugebenden Zahl n

int fak_my_ver(int n){
    int fakultet = 1;
    for (int i = 1; i <= n; fakultet *=i++);
    return fakultet;
}

void is_positiv(bool *fak, int *fakultet){
    if (*fakultet<0)
        *fak=false;
    else
        *fak=true;
}

int main(void)
{
    int n;
    printf("n eingeben: "); 
    scanf("%d", &n);
    bool valid = false;
    int fakulatet = fak_my_ver(n);
    is_positiv(&valid, &fakulatet);
    if(!valid) 
        printf("%d! ist nicht in diesem Programm positiv\n", n);
    else 
        printf("%d! = %d\n", n, fakulatet);
}
