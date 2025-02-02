
enum { NAMEMAX = 30 };

typedef struct Room{
    char building;
    short floor;
    short number;
} Room;

typedef struct Office{
    Room room;
    char name[NAMEMAX];
    int telephone_nr;
} Office;

// Die Datei raumbelegung.dat auf Moodle enthält Datensätze des Personals der Arbeitsgruppe
// Angewandte Informatik im Binärformat. Die Reihenfolge entspricht obigen Strukturen, also
// Gebäude Ebene Nummer Name Telefonnummer
// Die Datensätze können also direkt in die Struktur Buero eingelesen werden.
// Schreiben Sie ein C-Programm, welches die Daten aus der Datei in einer Liste speichert. Lesen Sie
// die Datensätze hierzu nacheinander aus der Datei (bspw. mit fread) und fügen Sie sie jeweils am
// Ende der Liste ein. Anschließend lassen Sie das Programm die Liste ausgeben.


