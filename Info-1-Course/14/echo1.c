
#include <stdio.h>

int main(int argc, char** argv){
    int i;

#if LOGLEVEL > 0
    printF("<Start>");
#endif
    for(int i=1; i<argc; i++){
#if LOGLEVEL > 1  
        printf("argv[%d] = ", i);
#endif
        printf("%s", argv[i]);
    }
#if LOGLEVEL > 1
    printf("<Ende>");
#endif
    printf("\n");
}

// gcc -Wall -std=c2x
// gcc -DLOGLEVEL=1 ...
// ... -DLOGLEVEL=2
