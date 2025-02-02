#include <stdio.h>

struct Punkt{
    double x, y;
};

#define PUNKT struct Punkt

int main(){
    PUNKT p = {2.0, 3.5}; // instead of struct Punkt...

    printf("Punkt: (%lf, %lf)", p.x, p.y);
}

// However, for pointer the same thing doees not work. 
// #define DBL_PT double*
//
// DBL_PT a, b;
// will be:
// double* a, b;
// so a is a pointer but b is a double.
