#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct {
    int age;
    long salary;
} Person;

int main(){
    Person *chef , *angest;

    chef=malloc(sizeof(Person));
    chef = NULL;
    assert(chef != NULL);
    chef->age =25;
    chef->salary = 4000;

}

// USED mostly only in dev time, not production
