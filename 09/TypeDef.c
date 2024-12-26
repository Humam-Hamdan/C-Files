typedef enum { ROT, ROTGELB, GRUEN, GELB } Ampelphasen;
typedef int GanzeZahl;
typedef GanzeZahl* ZGanzeZahl;
/* Zeiger auf GanzeZahl, also int*
Wenn GanzeZahl auf long geändert wird,
passt sich ZGanzeZahl automatisch auf long* an */
// Funktion mit Ampelphasen-Ergebnis und -Argument
Ampelphasen naechstePhase(Ampelphasen jetzt)
{
switch (jetzt)
{
case ROT:
return ROTGELB;
case ROTGELB:
return GRUEN;
case GRUEN:
return GELB;
case GELB:
return ROT;
default:
printf(”Unbekannte␣Ampelphase!\n”);
return ROT;
}
}
int main(void)
{
GanzeZahl i, j;
Ampelphasen ampel;
ZGanzeZahl p1, p2; /* zwei Zeiger, im Gegensatz zu GanzeZahl* p1, p2;
(nur p1 Zeiger, p2 GanzeZahl)
*/
