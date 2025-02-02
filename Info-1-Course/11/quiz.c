#include <stdio.h>

int main(int argc, char* argv[])
{
  FILE* stream[argc-1];                   // Zeiger auf Eingabestreams

  for (int i=0; i < argc-1; i++) {
      stream[i] = fopen(argv[i+1], "r");
      // ... jetzt kann man z.B. Daten aus der geöffneten Datei einlesen      
      printf("File %s geöffnet.\n", argv[i+1]);
  }
  printf("%d, %s, %s",argc, argv[0], argv[argc]);
} 
