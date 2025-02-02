#include <stdio.h>

// (Vorab-)Deklaration von pong(): „Prototyp“
int pong(int i);

// Deklaration/Definition von ping()
int ping(int k)
{
    printf("Ping-");
    // Benutzung von pong() vor Definition möglich wegen obiger Deklaration
    return 1 + pong(k - 1);
}

// Definition von pong() mit anderem Parameternamen als in der Deklaration
int pong(int k)
{
    printf("Pong\n");
    if (k > 0)
    // Aufruf von ping() kein Problem, da zuvor definiert
        return 1 + ping(k);
    else
        return 1;
}

int main(void)
{
    printf("insgesamt %d Aufrufe\n", ping(3));
    return 0; 
    // könnte man weglassen, 0 wird trotzdem zurückgegeben
}