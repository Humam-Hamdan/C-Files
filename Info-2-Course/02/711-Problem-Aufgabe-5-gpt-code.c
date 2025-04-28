
#include <stdio.h>
#include <math.h>

int main(void){
  const int seveneleven = 711;
  const double target = 7.11;
  const double epsilon = 0.001;

  for(int i = 1; i < seveneleven; i++){
    for(int j = 1; j < seveneleven - i; j++){
      for(int k = 1; k < seveneleven - i - j; k++){
        int l = seveneleven - i - j - k;
        if (l <= 0) continue;

        double prod = (i/100.0) * (j/100.0) * (k/100.0) * (l/100.0);

        if (fabs(prod - target) < epsilon){
          printf("Treffer: %.2f, %.2f, %.2f, %.2f\n", i/100.0, j/100.0, k/100.0, l/100.0);
        }
      }
    }
  }

  return 0;
}
