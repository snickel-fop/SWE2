/* VerketteteListen, V1.0
 * Created by Benjamin Zastrow, WIN-B
 * Eigene Implementierung einer verketteten Liste
 */


typedef struct node {
    double data;
    struct node* next;
    struct node* before;
} NODE;

typedef struct head {
    int counter;
    struct node* first;
    struct node* last;
} HEAD;

HEAD Linitialise(); //Header erstellen
int Lappend(double data, HEAD *header); //Element an der letzten Stelle hinzufügen; return: Stelle (-1 bei Fehler)
int Linsert(int spot, double data, HEAD *header); //Element an gegebener Stelle einfügen; return 0: kein Problem, return -1: Problem
void LremoveSpot(int spot, HEAD *header); //Element an der Stelle entfernen
double Lget(int spot, HEAD *header); //Daten an gegebener Stelle zurückgeben
int Lsearch(double data, HEAD *header); //Sucht, ob Daten in der Liste vorhanden sind; Return 0: gefunden, Return -1: nicht gefunden
int Llength(HEAD *header);
void Lprint(HEAD *header); //Gibt die Liste auf der Konsole aus
void Lclear(HEAD *header); //Leert die Liste
int Lexport(char* path, int binary, HEAD *header); //Exportiert Liste in Datei path in Binär- (1) oder Textmodus (0); Return 0: erfolgreich, return -1: nicht erfolgreich
int Limport(char* path, int binary, HEAD *header); //Importiert Liste aus Datei path im Binär- (1) oder Textmodus (0); Aktuelle Liste im RAM wird überschrieben; Return 0: erfolgreich, return -1: nicht erfolgreich