#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    int age;
    long salary;
} Person;

int main(){
    Person *chef , *angest;

    chef = malloc(sizeof(Person));
    bool ChefNullPtr = (chef == NULL);
    if(ChefNullPtr){
        printf("Break, coz no memory for chef");
        exit(EXIT_FAILURE);
    }

    chef->age = 35;
    chef->salary = 4000;

    angest = calloc(20, sizeof(Person));
    bool AngNullPtr = (angest == NULL);
    if(AngNullPtr){
        printf("Break, no memory");
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<20; i++){
        angest[i].age = 50+i;
        angest[i].salary = 2000 + 3 * i;
    }

    // Here you play with data

    free(chef);
    free(angest);
}
