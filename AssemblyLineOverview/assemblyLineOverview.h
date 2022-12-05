/* AssemblyLineOverview, V1.0
 * Created by Benjamin Zastrow, WIN-B
 * Verwaltung von Werkstücken mit doppelt-verketteter Liste
 * (Adaptierung der eigenen doppelt-verketteten Liste im SWE Portfolio: https://its-git.fh-salzburg.ac.at/fhs46655/swe2_ss2021_portfolio/tree/master/verkettete%20Listen)
 */


typedef struct node {
    int ID;
    int SIZE;
    char CONDITION;
    struct node* next;
} NODE;

typedef struct head {
    int counter;
    struct node* first;
    struct node* last;
} HEAD;


HEAD createList(); //Header erstellen
NODE* createNode(int ID, int SIZE, char CONDITION); //Node dynamisch anlegen
int addNodeFirst(NODE* node, HEAD *header); //Node am Anfang hinzufügen
int addNodeLast(NODE* node, HEAD *header); //Node am Ende hinzufügen
int addNodeAfterValue(NODE* node, int val, HEAD *header); //Node nach val einfügen
void removeFirstNode(HEAD *header); //Node am Anfang entfernen
void removeLastNode(HEAD *header); //Node am Ende entfernen
void removeNodeWithValue(int ID, int SIZE, char CONDITION, HEAD *header); //Node mit gegebenen Werten entfernen
void resetList(HEAD *header); //-> Lclear
void printList(HEAD *header); //Gibt die Daten der Liste aus

int Lappend(NODE* node, HEAD *header); //Element an der letzten Stelle hinzufügen; return: Stelle (-1 bei Fehler)
int Linsert(int spot, NODE* node, HEAD *header); //Element an gegebener Stelle einfügen; return 0: kein Problem, return -1: Problem
void LremoveSpot(int spot, HEAD *header); //Element an der Stelle entfernen
NODE Lget(int spot, HEAD *header); //Daten an gegebener Stelle zurückgeben
int Llength(HEAD *header);
void Lclear(HEAD *header); //Leert die Liste
