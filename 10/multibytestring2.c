#include <locale.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>  // für mblen, mbstowcs, wcstomb, MB_CUR_MAX
#include <wchar.h>  // für wcslen
int main(void){
    setlocale(LC_ALL, "");

    const char s[] = "Eĥoŝanĝo ĉiuĵaŭde";

    // Umwandlung char* → wchar_t*:
    unsigned int zeichenzahl = 0;
    const char* cp = s;
    unsigned int bytesNaechstesZeichen;
    while (*cp !=  '\0')    // erst Anzahl der Zeichen bestimmen
    {
        bytesNaechstesZeichen = mblen(cp, MB_CUR_MAX);
        zeichenzahl++;
        cp += bytesNaechstesZeichen;
    }
    wchar_t ws[zeichenzahl + 1];          // VLA für Ergebnis anlegen
    mbstowcs(ws, s, zeichenzahl + 1);    // eigentliche Umwandlung
    printf("char-Feld umgewandelt in wchar_t-Feld: %ls\n", ws);

    // Rückumwandlung wchar_t* → char*
    unsigned int mblaenge = 0;
    char dummy[MB_CUR_MAX];
    for (unsigned int i = 0; i < wcslen(ws); i++)    // Anzahl der Bytes bestimmen
        mblaenge += wctomb(dummy, ws[i]);
    char s2[mblaenge + 1];     // VLA für Ergebnis anlegen
    wcstombs(s2, ws, mblaenge + 1);    // eigentliche Umwandlung
    printf("zurück umgewandelt: %s\n", s2);
}
