// Beispiel zu structs und Funktionen, Kartesische und Polarkoordinaten
// Autor:   Bruno Lang, Holger Arndt
// Version: 28.07.2017
#include <math.h>
#include <stdio.h>

// Kartesische Koordinaten eines Punktes
typedef struct
{
  double x, y;
} KartKoord;

// Polarkoordinaten
typedef struct
{
  double r;           // Radius
  double phi;         // Winkel
} PolarKoord;

// Umrechnung polar → kartesisch
KartKoord polar2kart(PolarKoord *p)
{
  KartKoord erg;

  erg.x = (*p).r * cos((*p).phi);
  erg.y = (*p).r * sin((*p).phi);

  return erg;
}

int main(void)
{
  PolarKoord pol = { 2.0, 4.0 * atan(1.0) / 3.0 };
  // 4 arctan(1) ∕ 3  =  π ∕ 3  =  60°
  KartKoord kart;

  kart = polar2kart(&pol);
  printf("x = %f, y = %f\n", kart.x, kart.y); // Ausgabe: x = 1.000000, y = 1.732051
}
