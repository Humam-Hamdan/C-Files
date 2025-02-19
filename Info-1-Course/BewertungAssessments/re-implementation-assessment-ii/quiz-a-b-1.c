#include <stdio.h>

char kategorie1( int a ) {
    if ( a <=10 )
        return 'A';
    else
        return 'B';
}

char kategorie2( int a ) {
    if ( a <=10 )
        return 'A';
    return 'B';
}

char kategorie3( int a ) {
    return 'B';
    if ( a <=10 )
        return 'A';
}

int main(void){
	printf("%c\n", kategorie1(5));
	printf("%c\n", kategorie1(100));
	printf("%c\n", kategorie2(5));
	printf("%c\n", kategorie2(100));
	printf("%c\n", kategorie3(5));
	printf("%c\n", kategorie3(100));

}
