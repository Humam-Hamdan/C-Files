#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char s2[20] = "InformatikI-Vorl";
    char s1[16];

    printf("Laenge s2 = %lu\n", strlen(s2));

    strncpy(s1,s2,16);
    printf("s1 = %s\n",s1);

    printf("Adress of s1 = %p\n", s1);
    printf("Adress of s2 = %p", s2);

}
