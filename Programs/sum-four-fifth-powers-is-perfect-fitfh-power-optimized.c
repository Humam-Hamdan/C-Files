#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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

void find_solutions(int upper_limit, Solution **solutions, int *count) {
    *count = 0;
    *solutions = NULL;
    
    // Store FIRST valid (c,d) for each sum
    CDSum *sum_cd = malloc(upper_limit * (upper_limit + 1) / 2 * sizeof(CDSum));
    int index = 0;
    
    for (int c = 1; c <= upper_limit; c++) {
        unsigned long long c5 = (unsigned long long)c * c * c * c * c;
        for (int d = 1; d <= c; d++) {
            unsigned long long s = c5 + (unsigned long long)d * d * d * d * d;
            // Only store first occurrence of each sum
            if (index == 0 || s > sum_cd[index-1].sum) {
                sum_cd[index].sum = s;
                sum_cd[index].c = c;
                sum_cd[index].d = d;
                index++;
            }
        }
    }

    // Search phase remains O(n³)
    for (int a = 1; a <= upper_limit; a++) {
        unsigned long long a5 = (unsigned long long)a * a * a * a * a;
        for (int b = 1; b <= a; b++) {
            unsigned long long b5 = (unsigned long long)b * b * b * b * b;
            unsigned long long s_ab = a5 + b5;
            int e_max = (int)(pow(s_ab + 2*b5, 0.2)) + 2;

            for (int e = 1; e <= e_max; e++) {
                unsigned long long target = (unsigned long long)e * e * e * e * e - s_ab;
                CDSum key = {target, 0, 0};
                CDSum *found = bsearch(&key, sum_cd, index, sizeof(CDSum), compare);
                if (found && found->c <= b && found->d <= found->c) {
                    *solutions = realloc(*solutions, (*count + 1) * sizeof(Solution));
                    (*solutions)[*count] = (Solution){a, b, found->c, found->d, e};
                    (*count)++;
                }
            }
        }
    }
    free(sum_cd);
}
