/* VerketteteListen, V2.0
 * Created by Benjamin Zastrow, WIN-B
 * Eigene Implementierung einer verketteten Liste (Adaptierung für Stack- und Queue-Aufgabe)
 */


typedef struct node {
    int data;
    struct node* next;
    struct node* before;
} NODE;

typedef struct head {
    int counter;
    int maxSize;
    struct node* first;
    struct node* last;
} HEAD;

HEAD Linitialise(int maxSize); //Header erstellen
int Lappend(int data, HEAD *header); //Element an der letzten Stelle hinzufügen; return: Stelle (-1 bei Fehler)
int Linsert(int spot, int data, HEAD *header); //Element an gegebener Stelle einfügen; return 0: kein Problem, return -1: Problem
void LremoveSpot(int spot, HEAD *header); //Element an der Stelle entfernen
int Lget(int spot, HEAD *header); //Daten an gegebener Stelle zurückgeben
int Lsearch(int data, HEAD *header); //Sucht, ob Daten in der Liste vorhanden sind; Return 0: gefunden, Return -1: nicht gefunden
int Llength(HEAD *header);
void Lprint(HEAD *header); //Gibt die Liste auf der Konsole aus
void Lclear(HEAD *header); //Leert die Liste

//Spezifische List- und Queue-Funktionen
int LinsertFront(int data, HEAD *header);
int LinsertBack(int data, HEAD *header);
void LremoveFront(HEAD *header);
void LremoveBack(HEAD *header);