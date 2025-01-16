
// basic struct

struct List{
    // Dataypes
    struct *List rest;
};

// rest is ptr on next list

typedef struct List1{
    // Data
    struct *List1 rest;
} List1;

typedef List1* list;


// Pointer can be defined befor datatype.

typedef struct List2* list1;

typedef struct List2{
    // Data
    list1 rest;
} List2;


