#include <stdio.h>
#include <string.h>

int main(void) {
    char s1[30] = "Aber gerne doch!";
    char s2[] = "sehr sehr";
    char* s3;

    printf("Länge von s1: %lu\n",strlen(s1));

    printf("Länge von s2: %lu\n", strlen(s2));

    strncpy(s1,s2,5);
    printf("%s\n", s1);

    s3 = s1+5;
    printf("%s\n",s3);

    printf("%s\n",s2);
}
