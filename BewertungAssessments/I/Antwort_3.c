/************************************************/
/* Assessment I (08.11.2024)                    */
/* auto-generated .c file from text box input   */
/*                                              */
/* Humam Hamdan, 2427300                        */
/************************************************/

#include <stdio.h>

// Berechnung, ob die Zahl gerade oder ungerade ist

int main(void)
{
    // Zahl
    int n;

    // Eingabe & Lesen der Zahl
    printf("Bitte geben Sie eine Zahl ein: ");
    scanf("%d", &n);

    // Fallunterscheidung mit dem Rest der Division durch 2
    if(n%2 == 0)
        {
        printf("Die Zahl ist gerade.");
        }
    else
        {
        printf("Die Zahl ist ungerade.");
        }
}
