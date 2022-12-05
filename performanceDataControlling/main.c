/* PerformanceDataControlling, V1.0
 * Created by Benjamin Zastrow, WIN-B
 * Maschinenperformancekontrolle mittels Binärbaum und einfach-verketteter Liste
 * Zu Debuggingzwecken alles in einer Datei
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
void traverseInOrder(TreeNode *tree, Container *c, int *counter);

/* PerformanceDataControlling, V1.0
 * Created by Benjamin Zastrow, WIN-B
 * Maschinenperformancekontrolle mittels Binärbaum und einfach-verketteter Liste
 */
#include <stdio.h>
#include <stdlib.h>

SListElement* createSListElement(Container c) { //Funktion zum erstellen eines SListElements
    SListElement *tmp = malloc(sizeof(SListElement));
    if(tmp != NULL) {
        tmp->c = c;
        tmp->next = NULL;
    }
    else {
        free(tmp);
        return NULL;
    }
    return tmp;
}

DListElement* createDListElement(Container c) { //Funktion zum Erstellen eines DListElements
    DListElement *tmp = malloc(sizeof(DListElement));
    if(tmp != NULL) {
        tmp->sl = createSListElement(c);
        if(tmp->sl == NULL) {
            free(tmp->sl);
            free(tmp);
            return NULL;
        }
        tmp->before = NULL;
        tmp->next = NULL;
    }
    else {
        free(tmp);
        return NULL;
    }
    return tmp;
}

TreeNode* createTreeNode(Container c) { //Funktion zum Erstellen einer TreeNode
    TreeNode *tmp = malloc(sizeof(TreeNode));
    if(tmp != NULL) {
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->list = createSListElement(c);
        if(tmp->list == NULL) {
            free(tmp->list);
            free(tmp);
            return NULL;
        }
    }
    else {
        free(tmp);
        return NULL;
    }
    return tmp;
}

TreeNode* insertIntoTree(Container c, TreeNode *tree) { //Node in Tree einfügen (sollte funktionieren)
    if(tree->list->c.worktime > c.worktime) {
        if(tree->left != NULL) {
            insertIntoTree(c, tree->left);
        }
        else {
            tree->left = createTreeNode(c);
        }
    }
    else if(tree->list->c.worktime == c.worktime) {
        SListElement *tmp = tree->list;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = createSListElement(c);
    }
    else if(tree->list->c.worktime < c.worktime) {
        if(tree->right != NULL) {
            insertIntoTree(c, tree->right);
        }
        else {
            tree->right = createTreeNode(c);
        }
    }
    return tree;
}
void traverseInOrder(TreeNode *tree, Container *c, int *counter) { //Baum traversieren und alle Container in der richtigen Reihenfolge in ein Array speichern (funktioniert nicht richtig)
    if(tree == NULL) {return;}
    int i = *counter;
    if(tree->left != NULL) {
        traverseInOrder(tree->left, c, counter);
    }

    SListElement *temp = tree->list;

    while(temp != NULL) {
        c[i] = temp->c;
        i++;
        temp = temp->next;
    }

    *counter = i;

    if(tree->right != NULL) {
        traverseInOrder(tree->right, c, counter);
    }
}

int insertData(int id, double worktime, TreeNode *tree) { //Anwenderfunktion zum Einfügen eines Containers in den Baum
    if(tree == NULL) {return -1;}
    Container tmpC;
    tmpC.id = id;
    tmpC.worktime = worktime;

    if(insertIntoTree(tmpC, tree) != NULL) {
        return 0;
    }
    else {
        return -1;
    }
}

DListElement* traverse(TreeNode *tree) { //Anwenderfunktion zum Traversieren des Baumes
    if(tree == NULL) {return NULL;}

    Container c[1024];
    int counter = 0;
    traverseInOrder(tree, c, &counter);
    DListElement *dList = createDListElement(c[0]);
    DListElement *temp = dList;
    for(int i = 0; i < counter; ++i) {
        while(temp != NULL) {
            if(temp->sl->c.id == c[i].id) {
                temp->sl->next = createSListElement(c[i]);
                temp = dList;
                break;
            }
            else if(temp->next == NULL) {
                temp->next = createDListElement(c[i]);
                temp = dList;
                break;
            }
            temp = temp->next;
        }
    }
    return dList;
}

void printList (DListElement *list) { //Liste ausgeben (funktioniert wegen dem falschen Traversieren/Speichern nicht richtig)
    while(list != NULL) {
        printf("ID: %d, TIME: %lf\n", list->sl->c.id, list->sl->c.worktime);
        list = list->next;
    }
}
void printTree (TreeNode *tree) { //Tree ausgeben (funktioniert)
    if(tree->left != NULL) {
        printTree(tree->left);
    }
    SListElement *tmp = tree->list;
    while(tmp != NULL) {
        printf("ID: %d, TIME: %lf\n", tmp->c.id, tmp->c.worktime);
        tmp = tmp->next;
    }
    

    if(tree->right != NULL) {
        printTree(tree->right);
    }
}

int main() {
    Container c;
    c.id = 0;
    c.worktime = 1;
    TreeNode *tree = createTreeNode(c);
    insertData(0, 2, tree);
    insertData(1, 5, tree);
    insertData(2, 2, tree);
    insertData(3, 1, tree);
    insertData(4, 4, tree);
    insertData(4, 5, tree);
    insertData(5, 3, tree);
    insertData(6, 2, tree);
    insertData(6, 1, tree);
    insertData(6, 0, tree);

    DListElement *dList = traverse(tree);
    printf("--- Ausgabe der Liste ---\n");
    printList(dList);
    printf("--- Ausgabe des Baums ---\n");
    printTree(tree);
    return 0;
}
