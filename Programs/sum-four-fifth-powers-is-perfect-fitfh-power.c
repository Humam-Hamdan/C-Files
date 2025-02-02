
// the Original idea is from Julia Code of the Prof. of Analysis I, was changed and edited to get time and multiple solutions using DeepSeek R1.

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

/* Structure to store a solution tuple */
typedef struct {
    int a, b, c, d, e;
} Solution;

/**
 * Brute-force search for a^5 + b^5 + c^5 + d^5 = e^5 solutions
 * 
 * @param upper_limit Maximum value for component a
 * @param solutions   Pointer to array of solutions (output)
 * @param count       Pointer to solution count (output)
 */
void find_solutions(int upper_limit, Solution **solutions, int *count) {
    *count = 0;
    *solutions = NULL;  // Initialize empty solution array
    
    // Quadruply nested loops for a >= b >= c >= d
    for (int a = 1; a <= upper_limit; a++) {
        const unsigned long long a5 = (unsigned long long)a*a*a*a*a;
        
        for (int b = 1; b <= a; b++) {
            const unsigned long long b5 = (unsigned long long)b*b*b*b*b;
            
            for (int c = 1; c <= b; c++) {
                const unsigned long long c5 = (unsigned long long)c*c*c*c*c;
                
                for (int d = 1; d <= c; d++) {
                    const unsigned long long d5 = (unsigned long long)d*d*d*d*d;
                    const unsigned long long total = a5 + b5 + c5 + d5;
                    
                    /* Calculate fifth root with floating-point precision
                     * Add 0.5 before truncation for proper rounding */
                    const double e_raw = pow(total, 1.0/5.0);
                    const int e = (int)(e_raw + 0.5);  // Round to nearest integer
                    
                    /* Critical verification:
                     * 1. Check e is positive to avoid 0^5 edge case
                     * 2. Verify exact integer match using 64-bit math */
                    if (e > 0 && (unsigned long long)e*e*e*e*e == total) {
                        // Dynamically grow solutions array
                        *solutions = realloc(*solutions, (*count + 1) * sizeof(Solution));
                        (*solutions)[*count] = (Solution){a, b, c, d, e};
                        (*count)++;
                    }
                }
            }
        }
    }
}

int main() {
    printf("Euler vs Fermat Solver (Complete Brute-Force)\n");
    printf("Enter search limit: ");
    
    int upper_limit;
    scanf("%d", &upper_limit);
    
    // Start timing
    clock_t start = clock();
    
    Solution *solutions = NULL;
    int count = 0;
    find_solutions(upper_limit, &solutions, &count);
    
    // Calculate elapsed time
    clock_t end = clock();
    double time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    
    // Print results
    printf("\nFound %d solutions:\n", count);
    for (int i = 0; i < count; i++) {
        printf("Solution %d:\n", i+1);
        printf("a=%d, b=%d, c=%d, d=%d\n", 
              solutions[i].a, solutions[i].b, 
              solutions[i].c, solutions[i].d);
        printf("e=%d\n\n", solutions[i].e);
    }
    
    // Cleanup memory
    free(solutions);
    printf("Time taken: %.2f seconds\n", time_taken);
    
    return 0;
}
