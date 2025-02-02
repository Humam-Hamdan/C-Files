/**************************************/
/* Humam Hamdan                       */
/* Gruppe: Do.12                      */
/* Leiter: Florian Möschler           */
/* Uebungsblatt: 4   , Aufgabe:  9    */
/* Datum:     14 Nov 2024             */
/* Status:                            */
/**************************************/

/*
#include <stdio.h>

int main(void)
{
    int size, choice;

    printf("Größe eingeben: ");
    scanf("%d", &size);

    for(int i=1;i<size;i++)
    {
        printf("*");
        for(int j = (size-2); i<j ;i++)
        {
            printf(" ");

        }
        if(i==size)
            {
                printf("\n");
            }
    }


/*
    do
    {
        printf("\nchoice? (ja =1, nein =0): ");
        scanf("%d", &choice);
    }
    while(choice==1);
*/


#include <stdio.h>

int main()
{
    int size, choice = 1;

    while (choice == 1)
    {
        printf("Größe eingeben: ");
        scanf("%d", &size);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i == j || j == (size-1-i))
                {
                    printf("* ");
                }
		else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
        printf("Nochmal? (ja:1, nein:0): ");
        scanf("%d", &choice);
    }
    return 0;
}
