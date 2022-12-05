/* ContainerLookup, V1.0
 * Created by Benjamin Zastrow, WIN-B
 * Verwaltung von Containern mittels einer Baumstruktur
 */

typedef struct cont { //Definition eines Containers
    int id;
    double volume;
} Container;

typedef struct node { //Definition einer Baumnode
    Container c;
    struct node *lesser;
    struct node *greater;
} Node;

Node* ContainerInsert(int ID, double VOLUME, Node* ROOT); //Container einfügen (ist Root = NULL, wird davon ausgegangen, dass noch kein Baum existiert)
void ContainerSearch(double VOLUME, Node* ROOT); //Container nach Volumen suchen und auf stdout ausgeben
Node* ContainerRemove(double VOLUME, Node* ROOT); //Container nach Volumen suchen und entfernen
void ContainerPrint(Node* ROOT); //Suchbaum ausgeben (aufsteigend sortiert nach Fassungsvermögen)