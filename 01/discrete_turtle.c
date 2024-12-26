// Author: Lukas van Gemmeren
// Datum: 22.03.2024
// HINWEIS: Normalerweise werden .c-Dateien NICHT explizit eingebunden, sondern sollten in einen Header (.h) und eine .c-Datei aufgeteilt werden.
#include <stdbool.h>

typedef enum Richtung{
    N, NO, O, SO, S, SW, W, NW
} Richtung;


int pos_x, pos_y;
int direction_x, direction_y;
double timeout = 0.5;
int farbe = 1;
bool update = true;
bool stift_unten = true;
void stift_nach_oben(){
    stift_unten = false;
}
void stift_nach_unten(){
    stift_unten = true;
}
void wechsel_stift_position(){
    if(stift_unten){
        stift_unten = false;
    }else{
        stift_unten = true;
    }
}
void verwende_farbe(int f){
    farbe = f;
}
void setze_timeout(double t){
    timeout = t;
}
void zeige_nach_jedem_schritt(bool z){
    update = z;
}
void turtle(int rows, int cols, int start_x, int start_y){
    initialisiere(rows, cols);
    pos_x = start_x;
    pos_y = start_y;
    direction_x = 0;
    direction_y = 1;
    if(stift_unten)
        faerbe_pixel(pos_y, pos_x, 2);
    if(update){
        zeige_bild();
        schlafe(timeout);
    }

}
void gehe(int n){
    if(stift_unten)
        faerbe_pixel(pos_y, pos_x, 1);
    for(int i = 0; i < n; i++){
        pos_y = pos_y + direction_y;
        pos_x = pos_x + direction_x;
        if(stift_unten)
            faerbe_pixel(pos_y, pos_x, farbe);
    }
    if(stift_unten)
        faerbe_pixel(pos_y, pos_x, 2);
    if(update){
        zeige_bild();
        schlafe(timeout);
    }
}
void drehe(Richtung r){
    switch (r){
        case N: 
            direction_x = 0;
            direction_y = 1;
            break;
        case NO:
            direction_x = 1;
            direction_y = 1;
            break;
        case O:
            direction_x = 1;
            direction_y = 0;
            break;
        case SO:
            direction_x = 1;
            direction_y = -1;
            break;
        case S:
            direction_x = 0;
            direction_y = -1;
            break;
        case SW:
            direction_x = -1;
            direction_y = -1;
            break;
        case W:
            direction_x = -1;
            direction_y = 0;
            break;
        case NW:
            direction_x = -1;
            direction_y = 1;
            break;
        default:
            break;
    }
}