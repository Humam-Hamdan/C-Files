 // Plotter vertikal
 // a) Vorgehensweise ganz grob ( f steht für die zu plottende Funktion )
 // durchlaufe Zeilen i 
 //     bestimme zugehörigen x-Wert
 //     durchlaufe Spalten j der Zeile i
 //         bestimme zugehörigen y-Wert aus f(x)
 //         drucke das richtige Zeichen
 //     gehe zum Anfang der nächsten Zeile 
 
 // b) Verfeinerung
 // lege Raster raster für x und Skalierungsfaktor scal für y fest
 // für i=0 bis raster  // durchlaufe Zeilen
 //     x = i*pi/raster
 //     für j = -scal bis scal // denn für die Funktion aus der Aufgabe haben die Funktionswerte alle Betrag <= 1
 //         y = f(x)*scal, gerundet auf ganze Zahl   
 //         drucke das  richtige Zeichen  (A)
 //     drucke Zeilenvorschub
 
 // c) Verfeinerung für (A)
 // falls y = j 
 //    falls j ungleich 0
 //       drucke *
 //    sonst 
 //       drucke 0
 // sonst
 //    falls j = 0
 //       drucke |
 //    sonst
 //       drucke Leerzeichen

 // Andreas Frommer, 17.11.2021
 
#include <stdio.h>
#include <math.h>

int main(void) {
    
int raster = 30;
int scal = 20;
int i,j,y;
double x, f;
double PI = 4*atan(1);


for (i=0; i<=raster; i=i+1) {
    x = (PI*i)/raster;
    for (j=-scal; j <=scal; j=j+1) {
        f = -sin(5*x)*exp(-0.5*x);
        y = round(scal*f);
        if (y==j) 
            if (j!=0) 
                printf("*");
            else
                printf("0");
        else
            if (j ==0)
                printf("|");
            else
                printf(" ");
                
    }
    printf("\n");
}    
}
