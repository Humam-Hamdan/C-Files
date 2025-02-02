
#include <math.h>
#include <stdio.h>

const int MAX_PUNKTE = 1000; // Maximale Punktezahl

// Kartesische Koordinaten eines Punktes
typedef struct
{
    double x, y;
} KartKoord;

// Polarkoordinaten
typedef struct
{
    double r;   // Radius
    double phi; // Winkel
} PolarKoord;

// Punkt mit kartesischen oder Polarkoordinaten
typedef struct
{
    enum { KART, POLAR } koordArt;
    union
    {
        KartKoord kart;
        PolarKoord pol;
    } koord;
} Punkt;

// Umrechnung polar → kartesisch
KartKoord polar2kart(PolarKoord p)
{
    KartKoord erg;
    erg.x = p.r * cos(p.phi);
    erg.y = p.r * sin(p.phi);
    return erg;
}

// Vertauschen zweier Punkte
void vertausche(Punkt* p1, Punkt* p2)
{
    Punkt tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int main(void)
{
    Punkt punkte[MAX_PUNKTE]; // Punkteliste
    int anzahl = 0;

    // Punkte in Polarkoordinaten einlesen
    printf("Anzahl Punkte eingeben: ");
    scanf("%d", &anzahl);
    printf("Jeweils Radius und Winkel eingeben\n");
    for (int i = 0; i < anzahl; i++)
    {
        punkte[i].koordArt = POLAR;
        scanf("%lf %lf", &punkte[i].koord.pol.r, &punkte[i].koord.pol.phi);
    }

    // In kartesische Koordinaten umrechnen
    for (int i = 0; i < anzahl; i++)
    {
        punkte[i].koord.kart = polar2kart(punkte[i].koord.pol);
        punkte[i].koordArt = KART;
    }

    // Punkte mit „Sortieren durch Auswahl“ bzgl. x-Koordinate sortieren (Selection Sort)
    for (int i = 0; i < anzahl - 1; i++)
    {
        int posMin = i;  // Position des Punktes mit bisher kleinster x-Koordinate
        for (int j = i + 1; j < anzahl; j++)
        {
            if (punkte[j].koord.kart.x < punkte[posMin].koord.kart.x)
                posMin = j;
        }
        vertausche(&punkte[i], &punkte[posMin]);
    }

    // Sortierte Folge ausgeben
    printf("Kartesische Koordinaten der sortierten Folge:\n");
    for (int i = 0; i < anzahl; i++)
    {
        printf("(%f, %f)\n", punkte[i].koord.kart.x, punkte[i].koord.kart.y);
    }
    return 0;
}
