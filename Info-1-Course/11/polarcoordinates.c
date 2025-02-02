#include <math.h>
#include <stdio.h>

typedef struct {
    double x,y;
} Cartesian;

typedef struct {
    double r, phi;
} Polar;

Cartesian polar2cart(Polar p){
    Cartesian erg;

    erg.x = p.r * cos(p.phi);
    erg.y = p.r * sin(p.phi);

    return erg;
}

int main(void){
    Polar pol={2.0, 4.0*atan(1.0)/3.0};
    // 4 arctan(1)/3 = pi/3 = 60 deg
    Cartesian cart;

    cart = polar2cart(pol);
    printf("x = %lf, y = %lf\n", cart.x, cart.y);

}
