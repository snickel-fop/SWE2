/* PerformanceDataControlling, V1.0
 * Created by Benjamin Zastrow, WIN-B
 * Maschinenperformancekontrolle mittels Binärbaum und einfach-verketteter Liste
 */

typedef struct c {
    int id;
    double worktime;
} Container;

typedef struct sle {
    Container c;
    struct sle *next;
} SListElement;

typedef struct dle {
    SListElement *sl;
    struct dle *next;
    struct dle *before;
} DListElement;

typedef struct tn {
    SListElement *list;
    struct tn *left;
    struct tn *right;
} TreeNode;

int insertData(int id, double worktime, TreeNode *tree); //Neues Element einfügen
DListElement* traverse(TreeNode *tree); //Baum traversieren und doppelt-verkettete Liste anlegen mit Containern nach ID sortiert
void printList (DListElement *list); //Gibt die doppelt-verkettete Traversierungsliste aus
void printTree (TreeNode *tree); //Gibt den Baum traversiert aus

//Interne Funktionen
TreeNode* insertIntoTree(Container c, TreeNode *tree);
TreeNode* createTreeNode(Container c);
SListElement* createSListElement(Container c);
DListElement* createDListElement(Container c);
DListElement* traverseInOrder(TreeNode *tree, DListElement *dList);
