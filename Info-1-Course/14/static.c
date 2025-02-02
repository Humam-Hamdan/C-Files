#include <stdio.h>

int counter1; // set as 0
// known everywhere

static int counter2; // set at 0
// only known in this script


int f1(int n){
    int k;
// only in f1, but with every call the value changed

    static int j;
// only in f2, and with any number of calls there will be no change


    return 1;
}

// only known in this script
static double f2(int n){
    return 2;
}


// is known
int main(){
    return 1;
}
