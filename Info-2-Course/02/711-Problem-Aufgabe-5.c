
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// THERE IS SOME KIND OF PROBLEM WITH THIS CODE. IG IT IS THE INT/FLOAT THING

int main(void){
  int seveneleven = 711;
  int limit = 710;
  double delta = 0.001;

  for(int i = 1; i < (limit-3); i++){
    for(int j = 1; j < (limit-(2+i)); j++){
      for(int k = 1; k < (limit-(1+i+j)); k++){
        for(int l = 1; l < (limit-(i+j+k)); l++){
          int sum = i+j+k+l;
          double prod= (i/100.0) * (j/100.0) * (k/100.0) * (l/100.0);
          if( (fabs(prod-7.11)<delta) && (sum==seveneleven) )
            printf("Treffer: %.2f, %.2f, %.2f, %.2f\n", i/100.0, j/100.0, k/100.0, l/100.0);
        }
      }
    }
  }
}
