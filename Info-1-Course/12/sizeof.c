#include <stdio.h>

int main(){

    int num;
    char c;
    char* pc = "abcde";
    char string[80] = "defg";

    typedef struct tp{
        int x;
        char c;
        int y;

    } code;

    printf("num = %2lu\n", sizeof(num));
    printf("c = %2lu\n", sizeof(c));
    printf("pc = %2lu\n", sizeof(pc));
    printf("*c = %2lu\n", sizeof(*pc));
    printf("string = %2lu\n", sizeof(string));
    printf("struct tp = %2lu\n", sizeof(struct tp));
    printf("code = %2lu\n", sizeof(code));

    return 0;
}
