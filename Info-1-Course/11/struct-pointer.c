#include <stdio.h>

typedef struct {
    char FirstName[15];
    char LastName[15];
    // More data
    
} Person;

void printPerson1(Person p){
    printf("FirstName = %s\n", p.FirstName);
    printf("LastName = %s\n", p.LastName);
    // ...
}

void printPerson2(const Person* p){
    // cont sothat it becoms immutable
    printf("FirstName = %s\n", p->FirstName);
    printf("LaseName = %s\n", p->LastName);
    // ...
}

int main(void){
    Person chef ={ "The", "Boss" };

    printPerson1(chef); // => 50 Bytes
    printPerson2(&chef); // ~= 8 Bytes
}
