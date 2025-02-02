#include <stdio.h>
#include <strings.h>

typedef struct {
    unsigned short day;
    char month[4];
    unsigned short year;
} Date;

Date today = {8, "Jan", 2025};

typedef enum {Borrow, Extension} Borrowstate;

typedef struct {
    char usernr[13];
    char booksig[15];
    Borrowstate state;
    Date borrowdate;
    Date returndate;
} Borrowpaper;

Borrowpaper Huma = {
    "UniWuppertal",
    "6543 asdfh",
    Extension,
    today,
    {18, "Jan", 2025}
};

Borrowpaper goethe;

goethe.state = Borrow;
strcpy(goethe.usernr, "UniWeup");
goethe.borrowdate.day = 12;

// If it will not be changed, call with a pointer
Borrowpaper karl, *pkarl;
pkarl = &karl;
(*pkarl).state = Borrow;
pkarl->state = Borrow;

