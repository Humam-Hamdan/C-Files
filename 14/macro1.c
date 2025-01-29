
#include <stdio.h>

#define LINE_LENGTH 80

int main(){
    char line[LINE_LENGTH];

    printf("Your Name: ");
    fgets(line, LINE_LENGTH, stdin);
}

