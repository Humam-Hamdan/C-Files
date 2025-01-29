/* 
* In dem if hätte ein 
* strncmp(&whole[i], old, strlen(old)) == 0 
* stehen müssen. 
* Plus noch einer for die dann Character tauscht. 
*
* vor das fgets ein dummy scanf, damit das '\n' aus der Eingabe geholt wird.
*/

/************************************************/
/* Assessment III (17.01.2025)                   */
/* auto-generated .c file from text box input   */
/*                                              */
/* Humam Hamdan, 2427300                        */
/************************************************/

#include <stdio.h>
#include <string.h>

void search_replace(char old[], char new[], char whole[]){
        int len = strlen(new);

        for(int i=0; i<200; i=i+len){
                if(whole[i]==old[i]){
                        whole[i]=new[i];
                }
        }

}

// irgendwas stimmt hier nicht

int main(void){

        char old[20], new[20], whole[200];
        printf("old eingeben: ");
        scanf("%s", old);
        printf("new eingeben: ");
        scanf("%s", new);
        printf("alte Zeile eingeben: ");
        fgets(whole, 200, stdin);
        search_replace(old,new,whole);
        printf("\nneue Zeile ist: %s", whole);

}
