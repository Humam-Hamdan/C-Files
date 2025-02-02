// Autohändler (größeres Beispiel zu Strukturen und Listen)
// Autor:   Bruno Lang, Holger Arndt
// Version: 28.07.2017
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Typ des Vertrags
typedef enum { GEBRAUCHT, NEU, LEASING } Vertragstyp;

// für jedes Fahrzeug notwendige Daten
typedef struct
{
  char hersteller[20];                                         // Herstellername
  char modell[30];                                          // Modellbezeichnung
  char ausstattung[100];                                         // Beschreibung
  unsigned int leistung;                                                // in kW
} DatenAllgemein;

// zusätzliche Daten für Gebrauchtwagen
typedef struct
{
  unsigned long kilometer;
  unsigned int erstzulassung;                                        // nur Jahr
  unsigned long preis;                                         // nur ganze Euro
} DatenGebraucht;

// … für Neuwagen
typedef struct
{
  unsigned long preis;                                         // nur ganze Euro
  double max_rabatt;                                               // in Prozent
} DatenNeu;

// … und für Leasing-Verträge
typedef struct
{
  unsigned long anzahlung;
  unsigned int monatsrate;                                         // ganze Euro
  unsigned int laufzeit;                                           // in Monaten
  unsigned long restwert;
} DatenLeasing;

// komplette Daten für alle Vertragstypen
typedef struct
{
  DatenAllgemein dat_allg;                                   // gemeinsame Daten
  Vertragstyp vertrag;
  union                                   // spezielle Daten je nach Vertragstyp
  {
    DatenGebraucht dat_gebr;
    DatenNeu dat_neu;
    DatenLeasing dat_leas;
  } dat_spez;
} DatenKomplett;

// Knoten in der Liste
typedef struct Knoten
{
  DatenKomplett dat;                                      // Daten des Fahrzeugs
  struct Knoten* rest;
} Knoten;

// Liste von Fahrzeugen
typedef Knoten* Liste;

// gibt die Daten eines Fahrzeugs aus
void daten_ausgeben(DatenKomplett d)
{
  // bei jedem Vertragstyp vorhandene Daten
  printf("%s %s\n", d.dat_allg.hersteller, d.dat_allg.modell);
  printf("%u kW, %s\n", d.dat_allg.leistung, d.dat_allg.ausstattung);

  // Vertrags-spezifische Daten
  switch (d.vertrag)
    {
      case GEBRAUCHT:
        printf("gebraucht, %lu km, Erstzul. %u\n",
               d.dat_spez.dat_gebr.kilometer,
               d.dat_spez.dat_gebr.erstzulassung);
        printf("%lu Euro\n", d.dat_spez.dat_gebr.preis);
        break;
      case NEU:
        printf("neu\n");
        printf("%lu Euro bei max. %.2f%% Rabatt\n", d.dat_spez.dat_neu.preis,
               d.dat_spez.dat_neu.max_rabatt);
        break;
      case LEASING:
        printf("Leasing\n");
        printf("Anzahlung %lu, Restwert %lu\n", d.dat_spez.dat_leas.anzahlung,
               d.dat_spez.dat_leas.restwert);
        printf("bei %u Monatsraten zu je %u Euro\n",
               d.dat_spez.dat_leas.laufzeit, d.dat_spez.dat_leas.monatsrate);
        break;
      default:
        printf("### Fehler im Vertragstyp");
    }
  putchar('\n');
}

/* erzeuge einen neuen Knoten und lege darin den Datensatz d und den
   „Rest“zeiger r ab; liefere einen Zeiger auf den neuen Knoten zurück.
   Abbruch, wenn kein Speicherplatz verfügbar war.                      */
Knoten* zeigerAufNeuenKnoten(DatenKomplett d, Knoten* r)
{
  Knoten* neu = malloc(sizeof(Knoten));                      // Speicher belegen
  if (neu == NULL)
  {
    printf("### Programmabbruch, da Speicheranforderung in zeigerAufNeueZiffer fehlschlug!\n");
    exit(EXIT_FAILURE);
  }

  neu->dat = d;                      // Daten eintragen und „Rest“liste anhängen
  neu->rest = r;

  return neu;
}

// gibt die Daten aller in der Liste l eingetragenen Fahrzeuge aus
void liste_ausgeben(Liste l)
{
  while (l != NULL)
    {
      daten_ausgeben(l->dat);
      l = l->rest;
    }
}

int main(void)
{
  // DatenAllgemein-Objekt mit Initialisierung
  DatenAllgemein da1 = { "Ford", "Mondeo Kombi", "Klima, Navigation", 66 };
  // … bzw. ohne Initialisierung
  DatenAllgemein da2;

  // DatenGebraucht-Objekt mit Initialisierung
  DatenGebraucht dg = { 55000, 1999, 4500 };
  // DatenNeu-Objekt ohne Initialisierung
  DatenNeu dn;

  // komplette Datensätze
  DatenKomplett d1, d2, d3;

  // Liste von Fahrzeugen
  Liste list = NULL;

  // explizite Belegung der Objekte da2 und dn
  strcpy(da2.hersteller, "VW");
  strcpy(da2.modell, "Golf 5 TDI");
  strcpy(da2.ausstattung, "Klima, Kindersitz");
  da2.leistung = 75;

  dn.preis = 23000;
  dn.max_rabatt = 4.5;

  // Belegung von d1 und d2 durch Kopieren der Teil-Strukturen
  d1.dat_allg = da1;
  d1.vertrag = GEBRAUCHT;
  d1.dat_spez.dat_gebr = dg;

  d2.dat_allg = da2;
  d2.vertrag = NEU;
  d2.dat_spez.dat_neu = dn;

  // Belegung von da3 komponentenweise
  strcpy(d3.dat_allg.hersteller, "Mercedes");
  strcpy(d3.dat_allg.modell, "SLK");
  strcpy(d3.dat_allg.ausstattung, "komplett");
  d3.dat_allg.leistung = 230;
  d3.vertrag = LEASING;
  d3.dat_spez.dat_leas.anzahlung = 15000;
  d3.dat_spez.dat_leas.monatsrate = 300;
  d3.dat_spez.dat_leas.laufzeit = 36;
  d3.dat_spez.dat_leas.restwert = 20000;

  // die drei Fahrzeuge in eine Liste eintragen
  list = zeigerAufNeuenKnoten(d1, list);
  list = zeigerAufNeuenKnoten(d2, list);
  list = zeigerAufNeuenKnoten(d3, list);

  // d3 nochmals eintragen und einige der Daten darin ändern
  list = zeigerAufNeuenKnoten(d3, list);
  strcpy(list->dat.dat_allg.modell, "E 230");
  strcpy(list->dat.dat_allg.ausstattung, "Sport");
  list->dat.dat_allg.leistung = 210;
  list->dat.vertrag = NEU;
  list->dat.dat_spez.dat_neu.preis = 45000;
  list->dat.dat_spez.dat_neu.max_rabatt = 4.75;
 
  d3.vertrag=GEBRAUCHT;
  // Inhalt der Fahrzeugliste ausgeben
  liste_ausgeben(list);
}
