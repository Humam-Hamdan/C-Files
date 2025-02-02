// Author: Lukas van Gemmeren
// Datum: 22.03.2024
// HINWEIS: Normalerweise werden .c-Dateien NICHT explizit eingebunden, sondern sollten in einen Header (.h) und eine .c-Datei aufgeteilt werden.
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Variablen, identisch fuer alle Backends
enum {N_COLORS = 16};
int colorMap[N_COLORS];
int ROWS, COLS;
int PIXEL_BREITE = 1;
int PIXEL_HOEHE = 1;
int **pixMap;

// Variablen/Funktionen, die nur fuer das CONSOLE-Backend verwendet werden.
static char* escape = "\x1b[";

void erase_line(int n){printf("%s%d%c", escape, n, 'K');}
void move_cursor_to(int row, int col){printf("%s%d;%d%c", escape, row, col, 'H');}
void background_color(int n){printf("%s%dm", escape, n);}
void reset_colour_attributes(){printf("%s0m", escape);}
void hide_cursor(){printf("%s?25l", escape);}
void show_cursor(){printf("%s?25h", escape);}
void clear_screen(int n){
    reset_colour_attributes();
    printf("%s%d%c", escape, n, 'J');
    move_cursor_to(1,1);
}

// Die folgenden Funktionen sind fuer alle Backends identisch.
void setze_pixel_breite(int b){
    PIXEL_BREITE = b;
}
void setze_pixel_hoehe(int h){
    PIXEL_HOEHE = h;
}
int schlafe(double s){
    clock_t t1, t2;
    t1 = clock();
    t2 = clock();
    int c = 0;
    float t = t2 - t1;
    while(t/CLOCKS_PER_SEC < s){
        t2 = clock();
        t = t2 - t1;
        c++;
    }
    return c;
}
char warte_auf_taste(){
    printf(">> ");
    char input[100];
    fgets(input, 100, stdin);
    return input[0];
}
void faerbe_pixel(int row, int col, int color_index){
    if(row >= 0 && row < ROWS && col >= 0 && col < COLS){
        pixMap[ROWS - 1 - row][col] = color_index;
    }
}
void loesche_bild(){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            pixMap[i][j] = 0;
        }
    }
}

// Die folgenden Funktionen koennen unterschiedlich 
// fuer einzelne Backends sein.
void initialisiere(int rows, int columns){
    // Dieser Teil ist nur fuer das CONSOLE-Backend wichtig
    clear_screen(2);
    hide_cursor();

    //Dieser Teil ist fuer alle Backends identisch.
    ROWS = rows;
    COLS = columns;
    pixMap = malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++){
        pixMap[i] = malloc(columns * sizeof(int));
        for(int j = 0; j < columns; j++){
            pixMap[i][j] = 0;
        }
    }

    //Initialisierung der ColorMap
    colorMap[0] = 40;
    colorMap[1] = 107;
    colorMap[2] = 101;
    colorMap[3] = 41;
    colorMap[4] = 102;
    colorMap[5] = 42;
    colorMap[6] = 104;
    colorMap[7] = 44;
    colorMap[8] = 103;
    colorMap[9] = 43;
    colorMap[10] = 105;
    colorMap[11] = 45;
    colorMap[12] = 106;
    colorMap[13] = 46;
    colorMap[14] = 47;
    colorMap[15] = 100;
}
void zeige_bild(){
    move_cursor_to(1, 1);
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            int color_index = pixMap[i][j] % N_COLORS;
            background_color(colorMap[color_index]);
            for(int ii = 0; ii < PIXEL_HOEHE; ii++){
                move_cursor_to((i+1)*PIXEL_HOEHE + ii, (j+1)*PIXEL_BREITE);
                for(int jj = 0; jj < PIXEL_BREITE; jj++){
                    printf(" ");
                }
            }
        }
    }
    reset_colour_attributes();
    move_cursor_to((ROWS+1) * PIXEL_HOEHE, 1);
    erase_line(2);
}
void beenden(){
    //Diese Funktionen werden nur fuer das CONSOLE-Backend benoetigt
    show_cursor();
    move_cursor_to(ROWS+1, 0);
    reset_colour_attributes();

    //Dieser Teil ist fuer alle Backends identisch.
    for(int i = 0; i < ROWS; i++){
        free(pixMap[i]);
    }
    free(pixMap);
}

