constexpr int DIM = 3 ;
int i;
double x[DIM];
// Koordinaten des Punktes
for (i = 0; i < DIM; i++)
{
printf(”Koordinate␣%d␣eingeben:␣”, i);
scanf(”%lf”, &x[i]); // &x[i]: Adresse der Feldkomponente x[i]
}
printf(”Punkt:␣(%f”, x[0]);
for (i = 1; i < DIM; i++)
printf(”,␣%f”, x[i]);
printf(”)\n”);
