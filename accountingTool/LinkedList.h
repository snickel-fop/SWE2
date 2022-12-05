/* VerketteteListen, V2.1
 * Created by Benjamin Zastrow, WIN-B
 * Eigene Implementierung einer doppelt-verketteten Liste (Adaptierung für accountingTool-Aufgabe)
 */


typedef struct node {
    float SOLL;
    float HABEN;
    float BETRAG;
    char TEXT[128];
    struct node* next;
    struct node* before;
} NODE;

typedef struct head {
    int counter;
    struct node* first;
    struct node* last;
} HEAD;

HEAD Linitialise(); //Header erstellen
int Lappend(float SOLL, float HABEN, float BETRAG, char* TEXT, HEAD *header); //Element an der letzten Stelle hinzufügen; return: Stelle (-1 bei Fehler)
int Linsert(int spot, float SOLL, float HABEN, float BETRAG, char* TEXT, HEAD *header); //Element an gegebener Stelle einfügen; return 0: kein Problem, return -1: Problem
void LremoveSpot(int spot, HEAD *header); //Element an der Stelle entfernen
int Llength(HEAD *header);
void Lprint(HEAD *header); //Gibt die Liste auf der Konsole aus
void LprintSpecificBetrag(float BETRAG, HEAD *header); //Gibt alle Einträge mit bestimmtem Betrag aus
void LprintSpecificText(char* TEXT, HEAD *header); //Gibt alle Einträge mit bestimmtem Text aus
void Lclear(HEAD *header); //Leert die Liste
int Limport(char* path, HEAD *header); //Importiert Daten aus einer Kommaseparierten Textdatei
int Lexport(char* path, HEAD *header); //Exportiert Daten in eine Kommaseparierte Textdatei