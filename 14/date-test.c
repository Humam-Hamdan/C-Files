
#include <stdio.h>
#include "date.h"

int main(void)
{
    printf("Bitte ein Datum eingeben: ");
    Datum d1 = datumLese();

    printf("Eingegebenes Datum: %s\n", datumAlsString(&d1));

    Datum d2 = d1;
    datumNaechsterTag(&d2);
    datumNaechsterTag(&d2);
    datumNaechsterTag(&d2);
    printf("Drei Tage später: %s\n", datumAlsString(&d2));

    int zaehler = 1;
    Datum dzaehler = datumNeu(1, 1, d1.jahr);
    while (!(d1.tag == dzaehler.tag && d1.monat == dzaehler.monat))
    {
        zaehler++;
        datumNaechsterTag(&dzaehler);
    }

    printf("Der %s ist der %i. Tag im Jahr.\n", datumAlsString(&d1), zaehler);
}
