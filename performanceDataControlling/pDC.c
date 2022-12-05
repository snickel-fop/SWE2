/* PerformanceDataControlling, V1.0
 * Created by Benjamin Zastrow, WIN-B
 * Maschinenperformancekontrolle mittels Binärbaum und einfach-verketteter Liste
 */

#include "pDC.h"
#include <stdio.h>
#include <stdlib.h>

SListElement* createSListElement(Container c) {
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

DListElement* createDListElement(Container c) {
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

TreeNode* createTreeNode(Container c) {
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

TreeNode* insertIntoTree(Container c, TreeNode *tree) {
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
        while(tmp != NULL) {
            tmp = tmp->next;
        }
        tmp = createSListElement(c);
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
DListElement* traverseInOrder(TreeNode *tree, DListElement *dList) {
    if(tree == NULL) {return NULL;}
    DListElement *temp = dList;
    int i = 0;
    if(tree->left != NULL) {
        traverseInOrder(tree->left, dList);
    }

    while(temp != NULL) {
        if(temp->sl->c.id == tree->list->c.id) {
            temp->sl->next = createSListElement(tree->list->c);
            i = 1;
            break;
        }
        temp = temp->next;
    }
    if(i == 0) {
        temp = createDListElement(tree->list->c);
    }

    if(tree->right != NULL) {
        traverseInOrder(tree->right, dList);
    }
}

int insertData(int id, double worktime, TreeNode *tree) {
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

DListElement* traverse(TreeNode *tree) {
    if(tree == NULL) {return NULL;}
    DListElement *dList = createDListElement(tree->list->c);
    return traverseInOrder(tree, dList);
}

void printList (DListElement *list) {
    while(list != NULL) {
        printf("ID: %d, TIME: %lf\n", list->sl->c.id, list->sl->c.worktime);
        list = list->next;
    }
}
void printTree (TreeNode *tree) {
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