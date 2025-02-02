#include <stdio.h>
#include <stdbool.h>
#include <string.h>

enum {N = 20+1};
enum {NS = 200+1};

int main(void){

    char old[N], new[N];
    char str[NS];

    printf("Old Eingeben: ");
    fgets(old, N, stdin);

    printf("New Eingeben: ");
    fgets(new, N, stdin);


    // When using fgets
    old[strlen(old)-1] = '\0';
    new[strlen(new)-1] = '\0';

    const int oldlen = strlen(old);

    printf("Text eingeben: ");
    fgets(str, NS, stdin);

    for(int ind=0; ind < strlen(str); ind++){

        bool found = true;

        // Find
        int i = 0;
        while(found && i < oldlen){
            if(str[ind+i] != old[i] || str[ind + i] == '\0'){
                found = false;
            }
            i++;
        }
        // Replace
        if(found){
            for(int i=0; i<oldlen; i++)
                str[ind + i] = new[i];
        }
    }

    printf("New string: %s\n", str);
}
