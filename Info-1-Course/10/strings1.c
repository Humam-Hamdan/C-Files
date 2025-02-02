#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    char str1[] = "Hello, World!";
    char str2[] = {'H','a','l','l','o','\0'};

    // Zeichenkette ausgeben
    printf("%s \n", str1);
    printf("Länge von str1 = %lu \n", strlen(str1));

    // str1 Gross
    for(unsigned int i=0; i<strlen(str1); i++){
        printf("%c", toupper(str1[i]));
    }
    printf("\n");

    // str2
    printf("%s\n", str2);
}
