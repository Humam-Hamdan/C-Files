// Osterformel von Gauss für das Datum des katholischen Ostern
// Autor:   Andreas Frommer
// Version: 26.01.2022
#include "datum.h"
 
 int jahr;
 
 Datum ostern(int jahr) {
     int h1, h2, m, n, a, b, c, d, e, o;
     Datum datum;
     h1 = jahr/100; h2 = jahr/400;
     m = 15 +h1-h2-(8*h1+13)/25;
     n = 4+h1-h2;
     a = jahr % 19;
     b = jahr % 4;
     c = jahr % 7;
     d = (19*a+m) % 30;
     e = (2*b+4*c+6*d+n) % 7;
     o = 22+d+e;
     if (o <= 31) datum = datumNeu(o,3,jahr);
     else datum = datumNeu(o-31,4,jahr);
     return datum;
 }

