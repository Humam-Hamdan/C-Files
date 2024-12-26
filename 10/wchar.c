#include <locale.h> // set local
#include <stddef.h> // wchar_t
#include <stdio.h> // stdin
#include <wchar.h> // wprintf, wcslen
#include <wctype.h> // towupper

int main(){
    // Sprachumgebung
    setlocale(LC_ALL, "");

    // ein Zeichen
    wchar_t wc = L'ä';

    // Zeichenkette
    wchar_t ws[] = L"éßëćẃáä·ævbñ";

    // wprintf
    wprintf(L"Zeichen: %lc, Zeichenkette %ls\n", wc,ws);

    // grosse wchar_t
    wprintf(L"Groese Zeichen = %lu Bytes", sizeof(wchar_t));

    // Laenge und Speicherverbrauch
    wprintf(L"Anzahl zeichen in ws = %u\n",wcslen(ws));
    wprintf(L"Bytes = %lu\n",sizeof(ws));

    // Gross machen
    wprintf(L"String Gross: ");
    for(unsigned int i=0; i<wcslen(ws); i++)
        wprintf(L"%lc", towupper(ws[i]));
    putwchar(L'\n');

    // lesen einer Zeile
    wchar_t ws2[100];
    wprintf(L"String eingeben: ");
    fgetws(ws2,100,stdin);
    wprintf(L"eingegeben: %ls", ws2);

}
