1- get me the sqrt(2) using the newton verfahren and check with the abs(actual(sqrt2)-verfahrensqrt2)
2- write a program that gets a ASCII string as input and spits out how many voules are there.
3- write a progran with a funtion that spits out befreundete-zahlen till the number 1250.


> C Programming Tasks with Explanations and PAP

# **1. Calculate sqrt(2) using Newton’s Method and Check Accuracy**

## **Reasoning**:
Newton’s method iteratively approximates the square root by refining guesses using the formula:
\[
x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}
\]
For \( f(x) = x^2 - 2 \), \( f'(x) = 2x \), this becomes:
\[
x_{n+1} = x_n - \frac{x_n^2 - 2}{2x_n} = \frac{x_n}{2} + \frac{1}{x_n}
\]
We use this to compute an approximation and compare it to the actual square root of 2.

## **Code**:
```c
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double newton_sqrt2(double epsilon) {
    double guess = 1.0;
    while (fabs(guess * guess - 2) > epsilon) {
        guess = (guess + 2 / guess) / 2;
    }
    return guess;
}

int main() {
    double epsilon = 1e-6; // precision
    double result = newton_sqrt2(epsilon);
    printf("Approximation: %.6f\n", result);
    printf("Actual sqrt(2): %.6f\n", sqrt(2));
    printf("Difference: %.6f\n", fabs(result - sqrt(2)));
    return 0;
}
```

## **PAP**:
1. **Start**: Initialize a `guess` for the square root of 2 (e.g., 1.0).
2. **Iterate**:
   - Compute the next guess using \( x_{n+1} = (x_n + 2 / x_n) / 2 \).
   - Check if the difference \( |x_n^2 - 2| \) is within the desired precision.
3. **End**: Return the final approximation.

---

# **2. Count Vowels in ASCII Input**

## **Reasoning**:
To count vowels from input without using strings:
1. Read characters one by one until a newline or EOF is encountered.
2. Check if each character matches the set of vowels (`a, e, i, o, u, A, E, I, O, U`).
3. Increment a counter for every match.

## **Code**:
```c
#include <stdio.h>

int count_vowels() {
    int count = 0;
    char ch;
    printf("Enter characters (end with newline): ");
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            count++;
        }
    }
    return count;
}

int main() {
    int vowels = count_vowels();
    printf("Number of vowels: %d\n", vowels);
    return 0;
}
```

## **PAP**:
1. **Start**: Prompt the user for input.
2. **Iterate**:
   - Read each character until a newline or EOF.
   - Check if it is a vowel (`a, e, i, o, u, A, E, I, O, U`).
   - If it is, increment the counter.
3. **End**: Print the count.

---

# **3. Find Befreundete Zahlen (Amicable Numbers) Till 1250**

## **Reasoning**:
Amicable numbers are pairs \( (a, b) \) such that:
\[
\text{sum\_of\_divisors}(a) = b \text{ and } \text{sum\_of\_divisors}(b) = a \text{ with } a \neq b
\]
We compute divisors for each number up to 1250, check for amicable pairs, and avoid duplicates.

## **Code**:
```c
#include <stdio.h>

int sum_of_divisors(int n) {
    int sum = 1; // 1 is always a divisor
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

void find_amicable_numbers(int limit) {
    for (int a = 2; a <= limit; a++) {
        int b = sum_of_divisors(a);
        if (b > a && b <= limit) { // Avoid duplicates
            if (sum_of_divisors(b) == a) {
                printf("(%d, %d)\n", a, b);
            }
        }
    }
}

int main() {
    printf("Amicable numbers up to 1250:\n");
    find_amicable_numbers(1250);
    return 0;
}
```

## **PAP**:
1. **Start**: Define a function to calculate the sum of divisors.
2. **Iterate**:
   - For each number \( a \), calculate \( b = \text{sum\_of\_divisors}(a) \).
   - Check if \( \text{sum\_of\_divisors}(b) = a \) and \( a \neq b \).
   - Print the pair \( (a, b) \).
3. **End**: Stop when the limit is reached.

---

# **Why These Implementations?**

1. **Newton’s Method**: It’s a direct mathematical approach, fast convergence, and easy to implement with floating-point precision in C.
2. **Vowel Count**: Reading individual characters and directly matching ensures memory efficiency and simplicity.
3. **Amicable Numbers**: Efficient divisor sum computation avoids redundancy and ensures correctness.

---

Would you like further optimizations or explanations for any of these?

