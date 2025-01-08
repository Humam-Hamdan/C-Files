#include <stdio.h>

int main(int argc, char* argv[]){
    // Anzahl Args
    printf("argc = %d\n", argc);

    // Arg Ausgabe
    for(int i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);

    // Nullptr
    printf("argv[%d] = %p\n", argc,argv[argc]);
}
