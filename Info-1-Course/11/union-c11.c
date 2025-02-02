
#include <stdio.h>
#include <string.h>

typedef struct
{
    enum { JAEGER, SAMMLER } typ;
    char name[20];
    union
    {
        struct // Jäger
        {
            unsigned int speerNr;
            double reichweite;
            float geschwindigkeit;
        };
        struct // Sammler
        {
            float maxLast;
            unsigned int erfahrung;
        };
    } daten;
} JaegerOderSammler;

int main(void)
{
    JaegerOderSammler mitarbeiter[200];

    mitarbeiter[5].typ = SAMMLER;
    strcpy(mitarbeiter[5].name, "Karl");
    mitarbeiter[5].daten.maxLast = 50.3f;
    mitarbeiter[5].daten.erfahrung = 23;

    return 0;
}
