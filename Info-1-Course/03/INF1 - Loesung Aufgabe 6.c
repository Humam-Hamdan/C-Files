/**************************************/
/* Humam Hamdan                       */
/* Gruppe: Do.12                      */
/* Leiter: Florian Möschler           */
/* Uebungsblatt:  3  , Aufgabe: 6     */
/* Datum:   4 Nov 2024                */
/* Status:      Done                  */
/**************************************/

#include <stdio.h>

int main(void)
{
    int day_num, start_day;
	// Check Number of days
    {
        do {
            printf("Geben Sie die Anzahl der Tage ein: ");
            scanf("%d", &day_num);
        } while (day_num > 31 || day_num < 28);
    }

    // Check First Day 
	do
	{
    printf("Erster Wochentag (Mo:0, Di:1, Mi:2, Do:3, Fr:4, Sa:5, So:6): ");
    scanf("%d", &start_day);
	}
	while (start_day < 0 || start_day > 6);
	
    // Header
    printf("\n Mo Di Mi Do Fr Sa So \n");

    // Spacing
    for(int i = 0; i < start_day; i++) 
	{
        printf("   ");
    }

    // Day Numbers
    for(int i = 1; i <= day_num; i++) 
	{
        printf("%2d ", i);
        if ((i + start_day) % 7 == 0) 
		{
            printf("\n");
        }
    }
	
    // Extra line
    if ((day_num + start_day) % 7 != 0) {
        printf("\n");
    }
    
    return 0;
}