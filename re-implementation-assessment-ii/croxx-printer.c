
#include <stdio.h>

int main(){

    int size, choice = 1;

    while (choice == 1){
        printf("Größe eingeben: ");
        scanf("%d", &size);

        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                if (i == j || j == (size-1-i))
                    printf("* ");
		        else
                    printf("  ");
            }
            printf("\n");
        }
        printf("Nochmal? (ja:1, nein:0): ");
        scanf("%d", &choice);
    }
    return 0;
}
