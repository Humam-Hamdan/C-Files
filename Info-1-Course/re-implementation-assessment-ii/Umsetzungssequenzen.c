#include <stdio.h>

int main(void)
{
    int x;
    float y;
    
    x=-2; y=x;
    printf("%%d:  %d  %d \n", x, y);
    printf("%%f:  %f  %f \n", x, y);
    printf("%%u:  %u  %u \n", x, y);
    printf("%%c:  %c  %c \n", x, y);
    printf("\n");
    
    return 0;
}
