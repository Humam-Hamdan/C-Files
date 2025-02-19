#include <stdio.h>

// (Vorab-)Deklaration von pong(): „Prototyp“
int pong(int i);

// Deklaration/Definition von ping()
int ping(int k)
{
    printf("Ping-");
    // Benutzung von pong() vor Definition möglich wegen obiger Deklaration
    int ToReturn=1 + pong(k - 1);
    return ToReturn;
}

// Definition von pong() mit anderem Parameternamen als in der Deklaration
int pong(int k)
{
    printf("Pong\n");
    if (k > 0){
    // Aufruf von ping() kein Problem, da zuvor definiert
        int ToReturn=1 + ping(k);
        return ToReturn;
    }
    else
        return 1;
}

int main(void)
{
    int repeat;
    printf("Zahl für Funktion ping: ");
    scanf("%i",&repeat);
    printf("insgesamt %d Aufrufe\n", ping(repeat));
    return 0; 
    // könnte man weglassen, 0 wird trotzdem zurückgegeben
}