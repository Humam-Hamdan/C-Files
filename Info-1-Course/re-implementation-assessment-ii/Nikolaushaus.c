#include <stdio.h>
#include "console_graphics.c"
#include "discrete_turtle.c"

int main(void)
{
    int zeilen = 20;
    int spalten = 20;
    int schritt = 4;
    setze_pixel_breite(2);

    turtle(zeilen, spalten, spalten/2 - spalten/4, zeilen/2 - spalten/4);

    //Haus
    gehe(2*schritt);
    drehe(O);
    gehe(2*schritt);
    drehe(NW);
    gehe(schritt);
    drehe(SW);
    gehe(schritt);
    drehe(SO);
    gehe(2*schritt);
    drehe(W);
    gehe(2*schritt);
    drehe(NO);
    gehe(2*schritt);
    drehe(S);
    gehe(2*schritt);

    beenden();
    return 0;
}
