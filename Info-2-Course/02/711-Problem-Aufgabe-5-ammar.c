#include <stdio.h>

int main(void) {
    int a, b, c, d;
    for (a = 1; a <= 708; a++) {
        for (b = 1; b <= 709 - a; b++) {
            for (c = 1; c <= 710 - a - b; c++) {
                d = 711 - (a + b + c);
                if (a * b * c * d == 711000000) {
                    printf("%d %d %d %d\n", a, b, c, d);
                }
            }
        }
    }
    return 0;
}
