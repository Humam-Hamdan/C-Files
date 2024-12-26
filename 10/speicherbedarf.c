#include <stdio.h>

int main(){
    char v1[] = {'Z','e','i','c','h', 'e', 'n', 'k', 'e', 't', 't','e','\0'};
    char v2[] = "Zeichenkette";
    char v3[20] = "Zeichenkette";
    char* v4 = "Zeichenkette";

    printf("v1= %s, size= %lu\n", v1,sizeof(v1));
    printf("v2= %s, size= %lu\n", v2,sizeof(v2));
    printf("v3= %s, size= %lu\n", v3,sizeof(v3));
    printf("v4= %s, size= %lu\n", v4,sizeof(v4));
}
