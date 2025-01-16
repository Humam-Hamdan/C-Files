
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum {NAMLAENGE = 10};

typedef struct Person {
    char name[NAMLAENGE];
    struct Person *mutter;
    struct Person *vater;
} Person;


int main(void) {
    
    Person *p1, *pm, *pv, *anfang;
    
    p1 = malloc(sizeof(Person));
    strcpy(p1->name,"Kira"); 
    p1->mutter = NULL; 
    p1->vater = NULL;
    anfang = p1;
    
    pv = malloc(sizeof(Person));
    strcpy(pv->name,"Kilian"); 
    pv->mutter = NULL; 
    pv->vater = NULL;
    
    pm = malloc(sizeof(Person));
    strcpy(pm->name,"Kim");     
    pm->mutter = NULL; 
    pm->vater = NULL;
    
    p1->mutter = pm;
    p1->vater = pv;
    
    pv = malloc(sizeof(Person));
    strcpy(pv->name,"Kevin");   
    pv->mutter = NULL; 
    pv->vater = NULL;
    
    pm = malloc(sizeof(Person));
    strcpy(pm->name,"Klara");     
    pm->mutter = NULL; 
    pm->vater = NULL;
    
    p1 = p1->mutter;       
    p1->mutter = pm;
    p1->vater =  pv;
    
    pm = malloc(sizeof(Person));
    strcpy(pm->name,"Kirsten");   
    pm->mutter = NULL; 
    pm->vater = NULL;
    
    p1 = p1->vater;
    p1->mutter = pm;
    
    pm = malloc(sizeof(Person));
    strcpy(pm->name,"Katima");   
    pm->mutter = NULL; 
    pm->vater = NULL;
    
    pv = malloc(sizeof(Person));
    strcpy(pv->name,"Kai");
    pv->mutter = NULL; 
    pv->vater = NULL; 
    
    p1 = p1->mutter;
    p1->vater = pv;
    p1->mutter = pm;
    
    pm = malloc(sizeof(Person));
    strcpy(pm->name,"Karina");  
    pm->mutter = NULL; 
    pm->vater = NULL;
    
    pv = malloc(sizeof(Person));
    strcpy(pv->name,"Karim");    
    pv->mutter = NULL; 
    pv->vater = NULL;
    
    p1 = anfang->vater;
    p1->vater = pv;
    p1->mutter = pm;
    
}
