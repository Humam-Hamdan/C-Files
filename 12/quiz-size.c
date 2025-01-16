#include <stdio.h>
int main(){
    float f = 1.0f;
    char c = 'a';
    printf("%lu\n", sizeof(f));
    printf("%d\n", (int) sizeof(float));
    printf("%d\n", (int) sizeof(c));
    printf("%lu\n", sizeof(char));
    printf("Size of size_t: %zu bytes\n", sizeof(size_t));
}
