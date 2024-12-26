enum Ampelphasen { ROT, ROTGELB, GRUEN, GELB };
// ROT == 0, ROTGELB == 1, GRUEN == 2, GELB == 3
enum Konstanten { EINS = 1, ZWEI, DREI = 4, VIER };
// EINS == 1, ZWEI == 2, DREI == 4, VIER == 5
enum { N = 10 };
// belegt eine Konstante
enum Ampelphasen rechtsabbieger = GRUEN;
// Variable des Aufzählungstyps; beachte „enum“
if (rechtsabbieger == GELB)
printf(”Vorsicht!\n”);
