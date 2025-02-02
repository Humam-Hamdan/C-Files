
/*
Q1: 
    int a = 4, b, c, d = 5;
    b = a++;
    c = ++a;
    d *= c;
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",c);
    printf("%d\n",d);
------
Q2:
  int a = 2;
  char c = 'x';
  int* pa = &a;
  char* pc;

  pc = &c;

  printf("*pa = %d\n",*pa);
  printf("a = %d\n",a);
  printf("pc = %p\n",pc);
  printf("Adresse von c = %p\n",&c);
  printf("*pc = %c\n",*pc);
---------------
Q3:
 const double PI = 4*atan(1);
 const int LEVEL1;
 const int LEVEL2 = 50;
 
 LEVEL1 = 35;
 LEVEL2 = LEVEL1+15;
-------------
Q4:


 const int LEVEL1 = 35, LEVEL2= 50;
 int* p2;
 
 p2 = &LEVEL2;
 *p2 += 150;
 printf("LEVEL2 = %d, LEVEL1^LEVEL2 = %d\n", LEVEL2, LEVEL1&LEVEL2);
-------
Q5:

int a = 3, b = 5;
int* p = &a;
int** pp = NULL;
 pp ist ein Zeiger auf einen Zeiger, der auf eine int-Variable zeigen muss;
pp enthält noch keine gültige Adresse

pp = &p;
/* pp zeigt jetzt auf den int-Zeiger p 
*pp = &b;
/* In dem Speicherbereich, auf den pp verweist (d.h. in der Zeigervariable p),
wird die Adresse von b gespeichert. p hat also jetzt den Wert
„Adresse von b“, d.h. p (und damit auch *pp) zeigt auf b

printf("%d\n", *p);
**pp = 17;
/* *pp ist ein Zeiger mit Wert „Adresse von b“, d.h. *pp zeigt auf b.
*(*pp) – oder kurz **pp – ist der Inhalt des Speicherbereichs, auf den
*pp zeigt, also der Inhalt von b

printf("%d\n", b);
-------------------------------------------------
Q6:
float potenz(float x, int k) {
    int i;
    float result = 1;
    for (i=1; i<=k; i++)
        result *= x;
    return result;
}

int main(void) {
    int i = 0, k = 3;
    float x = 4.0f, y = 0.2f;
   
    printf("%f\n", potenz(x,k));
    printf("%f\n", potenz(k,i));
    printf("%f\n", potenz(y,2));
    printf("%f\n", potenz(k,k));
}
-------------------------------------------------
Q7:

void teilen( double* a, double* b) {
    double c = *a + *b;
    *a = (int) c;
    *b = c-*a;
    return;
}

int main(void) {
    double a = 4.5, b = 0.75;
    printf("1. Ausgabe: a = %f, b = %f, a+b = %f\n", a,b, a+b);
    teilen(&a, &b);
    printf("2. Ausgabe: a = %f, b = %f, a+b = %f\n", a,b, a+b);
}




*/


#include <stdio.h>
#include <math.h>
#include <stddef.h>

int main()
{
    float x=2.718282;
    float y=3.141592;
    float *px = &y;
    float *py = px;
    *px = 1.618033;

    printf("%f\n%f\n%f\n%f\n", x, *px, y, *py);
}