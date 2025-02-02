
# Schnelle Exponentiation (Rekursiv)

```c
// Problem: Berechnung von x^n effizient mit Rekursion
#include <stdio.h>

int callCount = 0; // Zähler für Funktionsaufrufe

double fastExponentiation(double x, int n) {
    callCount++; // Zähler inkrementieren
    if (n == 0) return 1; // Basisfall
    double half = fastExponentiation(x, n / 2);
    if (n % 2 == 0) {
        return half * half;
    } else {
        return x * fastExponentiation(x, n - 1);
    }
}

int main() {
    double x = 2.0;
    int n = 10;
    printf("%.2f^%d = %.2f\n", x, n, fastExponentiation(x, n));
    printf("Anzahl der Funktionsaufrufe: %d\n", callCount);
    return 0;
}
```

### Erläuterung
1. **Problemverständnis**: Hier soll \(x^n\) effizient berechnet werden. Ein Ansatz mit rekursiver Halbierung des Exponenten reduziert die Anzahl der Multiplikationen erheblich.
2. **Effizienz**: Die Verwendung von `half * half` für gerade Exponenten minimiert redundante Berechnungen.
3. **Grenzfälle**: Der Basisfall \(n = 0\) wird behandelt, um \(x^0 = 1\) sicherzustellen.
4. **Testfälle**: Werte wie \(x = 2, n = 10\) überprüfen die Korrektheit und Effizienz der Implementierung.

---

# Suchen und Ersetzen von Strings

```c
// Problem: Ersetzen eines Strings in einem anderen, Länge max. 200 Zeichen
#include <stdio.h>
#include <string.h>

void searchAndReplace(char *str, const char *old_str, const char *new_str) {
    size_t old_len = strlen(old_str);
    size_t new_len = strlen(new_str);

    if (old_len != new_len) {
        printf("Fehler: Strings haben unterschiedliche Längen!\n");
        return;
    }

    for (char *pos = strstr(str, old_str); pos != NULL; pos = strstr(pos + old_len, old_str)) {
        memcpy(pos, new_str, new_len);
    }
}

int main() {
    char str[201];
    char old_str[21];
    char new_str[21];

    printf("Geben Sie den Hauptstring ein (max. 200 Zeichen): ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Entferne das Zeilenumbruchzeichen

    printf("Geben Sie den zu ersetzenden Teilstring ein (max. 20 Zeichen): ");
    fgets(old_str, sizeof(old_str), stdin);
    old_str[strcspn(old_str, "\n")] = 0; // Entferne das Zeilenumbruchzeichen

    printf("Geben Sie den neuen Teilstring ein (max. 20 Zeichen): ");
    fgets(new_str, sizeof(new_str), stdin);
    new_str[strcspn(new_str, "\n")] = 0; // Entferne das Zeilenumbruchzeichen

    printf("Vorher: %s\n", str);
    searchAndReplace(str, old_str, new_str);
    printf("Nachher: %s\n", str);
    return 0;
}
```

### Erläuterung
1. **Problemverständnis**: Ziel ist es, einen Teilstring im Hauptstring zu ersetzen, wobei die Längen der beiden Teilstrings gleich sein müssen.
2. **Effizienz**: Die Verwendung von `strstr` und `memcpy` sorgt für effiziente Suche und Ersetzung.
3. **Grenzfälle**: Es wird geprüft, ob die Längen der Teilstrings übereinstimmen.
4. **Testfälle**: Hauptstring mit mehreren Vorkommen des alten Teilstrings überprüfen.

---

# Arithmetisches Mittel und Standardabweichung

```c
// Problem: Berechnung von Mittelwert und Standardabweichung aus Benutzereingaben
#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100

double arithmeticMean(const double *arr, size_t size) {
    if (size == 0) return 0; // Sicherstellung
    double sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

double standardDeviation(const double *arr, size_t size) {
    if (size < 2) return 0;
    double mean = arithmeticMean(arr, size);
    double sumSquaredDifferences = 0;
    for (size_t i = 0; i < size; ++i) {
        double difference = arr[i] - mean;
        sumSquaredDifferences += difference * difference;
    }
    return sqrt(sumSquaredDifferences / (size - 1)); // Verwende N-1 für Stichproben-Stdabweichung
}

int main() {
    double data[MAX_SIZE];
    size_t size;

    printf("Geben Sie die Anzahl der Elemente ein (max. %d): ", MAX_SIZE);
    scanf("%zu", &size);

    if (size == 0 || size > MAX_SIZE) {
        printf("Ungültige Anzahl von Elementen. Beenden.\n");
        return 1;
    }

    printf("Geben Sie die Elemente ein:\n");
    for (size_t i = 0; i < size; ++i) {
        printf("Element %zu: ", i + 1);
        scanf("%lf", &data[i]);
    }

    printf("Arithmetisches Mittel: %.5f\n", arithmeticMean(data, size));
    printf("Standardabweichung: %.5f\n", standardDeviation(data, size));
    return 0;
}
```

### Erläuterung
1. **Problemverständnis**: Das Programm berechnet den Mittelwert und die Standardabweichung einer Liste von Zahlen.
2. **Effizienz**: Der Mittelwert wird nur einmal berechnet, um doppelte Berechnungen zu vermeiden.
3. **Grenzfälle**: Leere Eingaben oder nur ein Element werden abgefangen.
4. **Testfälle**: Werte wie \(2, 1, 3, 2, 4\) überprüfen die Genauigkeit der Berechnung.

---
