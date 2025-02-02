#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// the Original idea is from Julia Code of the Prof. of Analysis I, was changed and edited to get time and multiple soltuions using DeepSeek R1.

typedef struct {
    unsigned long long sum;
    int c;
    int d;
} CDSum;

typedef struct {
    int a, b, c, d, e;
} Solution;

int compare(const void *a, const void *b) {
    const CDSum *sa = (const CDSum *)a;
    const CDSum *sb = (const CDSum *)b;
    return (sa->sum > sb->sum) - (sa->sum < sb->sum);
}

void find_solutions(int schranke, Solution **solutions, int *count) {
    *count = 0;
    *solutions = NULL;
    
    // Precompute all c^5 + d^5 pairs
    int cd_count = schranke * (schranke + 1) / 2;
    CDSum *sum_cd = malloc(cd_count * sizeof(CDSum));
    int index = 0;
    
    for (int c = 1; c <= schranke; c++) {
        unsigned long long c5 = (unsigned long long)c * c * c * c * c;
        for (int d = 1; d <= c; d++) {
            sum_cd[index].sum = c5 + (unsigned long long)d * d * d * d * d;
            sum_cd[index].c = c;
            sum_cd[index].d = d;
            index++;
        }
    }

    qsort(sum_cd, cd_count, sizeof(CDSum), compare);

    // Search for solutions
    for (int a = 1; a <= schranke; a++) {
        unsigned long long a5 = (unsigned long long)a * a * a * a * a;
        for (int b = 1; b <= a; b++) {
            unsigned long long b5 = (unsigned long long)b * b * b * b * b;
            unsigned long long s_ab = a5 + b5;
            int e_max = (int)(pow(s_ab + 2*b5, 0.2)) + 2;

            for (int e = 1; e <= e_max; e++) {
                unsigned long long e5 = (unsigned long long)e * e * e * e * e;
                unsigned long long target = e5 - s_ab;
                
                CDSum key = {target, 0, 0};
                CDSum *found = bsearch(&key, sum_cd, cd_count, sizeof(CDSum), compare);
                
                if (found) {
                    int pos = found - sum_cd;
                    // Find first matching entry
                    while (pos > 0 && sum_cd[pos-1].sum == target) pos--;
                    // Add all matching entries
                    for (; pos < cd_count && sum_cd[pos].sum == target; pos++) {
                        int c = sum_cd[pos].c;
                        int d = sum_cd[pos].d;
                        if (c <= b && d <= c) {
                            // Add to solutions array
                            *solutions = realloc(*solutions, (*count + 1) * sizeof(Solution));
                            (*solutions)[*count] = (Solution){a, b, c, d, e};
                            (*count)++;
                        }
                    }
                }
            }
        }
    }
    
    free(sum_cd);
}

int main() {
    int schranke;
    printf("Euler vs Fermat Solver\n");
    printf("Enter search limit: ");
    scanf("%d", &schranke);

    clock_t start = clock();
    Solution *solutions = NULL;
    int solution_count = 0;
    find_solutions(schranke, &solutions, &solution_count);
    clock_t end = clock();

    printf("\nFound %d solutions:\n", solution_count);
    for (int i = 0; i < solution_count; i++) {
        Solution s = solutions[i];
        printf("Solution %d:\n", i+1);
        printf("a = %d, b = %d, c = %d, d = %d\n", s.a, s.b, s.c, s.d);
        printf("e = %d\n\n", s.e);
    }

    free(solutions);
    printf("Time taken: %.3f seconds\n", ((double)(end - start))/CLOCKS_PER_SEC);
    return 0;
}
