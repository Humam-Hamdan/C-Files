#include <stdio.h>
// Beispiel für continue und break
int main(void)
{
    int i;

    for (i = 1; i <= 10; i = i + 1)
    {
        if (i == 3)
            break;
            //continue;        // Sprung vor Zeile 19
        else if (i == 7)
            continue;
            //break;         // Sprung zu Zeile 20
        printf("i = %d\n", i);
    }
    printf("Fertig\n");
}
