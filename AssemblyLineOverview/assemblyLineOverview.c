/* AssemblyLineOverview, V1.0
 * Created by Benjamin Zastrow, WIN-B
 * Verwaltung von Werkstücken mit doppelt-verketteter Liste
 * (Adaptierung der eigenen doppelt-verketteten Liste im SWE Portfolio: https://its-git.fh-salzburg.ac.at/fhs46655/swe2_ss2021_portfolio/tree/master/verkettete%20Listen)
 */

#include "assemblyLineOverview.h"
#include <stdio.h>
#include <stdlib.h>

HEAD createList() { //Leeren Header anlegen
    HEAD tmp;
    tmp.counter = 0;
    tmp.first = NULL;
    tmp.last = NULL;
    return tmp;
}

NODE* createNode(int ID, int SIZE, char CONDITION) { //Node anlegen
    NODE temp;
    temp.ID = ID;
    temp.SIZE = SIZE;
    temp.CONDITION = CONDITION;
    temp.next = NULL;
    NODE *ptr = malloc(sizeof(NODE)); //Speicher reservieren
    if(ptr != NULL) {
        *ptr = temp;
    }
    return ptr; //Wenn ptr == NULL, dann nicht reserviert (Fehler bei malloc)
}

int addNodeFirst(NODE* node, HEAD *header) {
    return Linsert(0, node, header);
}
int addNodeLast(NODE* node, HEAD *header) {
    return Lappend(node, header);
}
int addNodeAfterValue(NODE* node, int val, HEAD *header) {
    return Linsert(val+1, node, header);
}
void removeFirstNode(HEAD *header) {
    LremoveSpot(0, header);
}
void removeLastNode(HEAD *header) {
    LremoveSpot(header->counter-1, header);
}
void removeNodeWithValue(int ID, int SIZE, char CONDITION, HEAD *header) {
    NODE* ptr = header->first;
    int counter = 0;
    while(0 == 0) {
        if(ptr == NULL) {break;}
        if(ptr->ID == ID && ptr->CONDITION == CONDITION && ptr->SIZE == SIZE) {
            LremoveSpot(counter, header);
            break;
        }
        ptr = ptr->next;
        counter++;
    }
}
void resetList(HEAD *header) {
    Lclear(header);
}
void printList(HEAD *header) {
    printf("--- Elemente in der Liste: %d ---\n", header->counter);
    NODE *ptr = header->first;
    for(int i = 0; i < header->counter; ++i) {
        printf("#%d: ID: %d, SIZE: %d, CONDITION: %c\n", i+1, ptr->ID, ptr->SIZE, ptr->CONDITION);
        ptr = ptr->next;
    }
}



int Lappend(NODE* node, HEAD *header) { //Element an der letzten Stelle hinzufügen; return: Stelle (-1 bei Fehler)
    if(header->counter == 0) {
        header->first = node;
        header->last = header->first;
        header->counter++;
    }
    else {
        node->next = NULL;
        header->last->next = node;
        header->last = node;
        header->counter++;
    }
    return header->counter-1;
} 
int Linsert(int spot, NODE* node, HEAD *header) {//Element an gegebener Stelle einfügen; return 0: kein Problem, return -1: Problem
    if(spot > header->counter || spot < 0) {return -1;} //Argument prüfen
    if(header->counter == 0) { //Einfügen an Stelle 0 (Weil Liste leer)
        header->last = node;
        header->first = header->last;
        header->counter++;
    }
    else {
        if(spot == header->counter) {Lappend(node, header);} //Einfügen am Ende
        else if(spot == 0) { //Einfügen an Stelle 0 (bei nicht leerer Liste)
            node->next = header->first;
            header->first = node;
            header->counter++;
        }
        else { //Einfügen durch Durchiterieren und Verknüpfen
            NODE* ptr = header->first;
            for(int i = 0; i < spot-1; ++i) {
                ptr = ptr->next;
            }
            node->next = ptr->next;
            ptr->next = node;
            header->counter++;
        }
    }
    return 0;
} 
void LremoveSpot(int spot, HEAD *header) { //Element an der Stelle entfernen
    if(spot >= header->counter || spot < 0) {return;} //Argument prüfen
    NODE *ptr = header->first;
    if(spot == 0) { //Entfernen an Stelle 0 -> Neuverknüpfen
        header->first = ptr->next;
    } else if(spot == header->counter-1) { //Entfernen am Ende -> Neuverknüpfen
        ptr = header->last;
        header->last->next = NULL;
        NODE *temp = header->first;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        header->last = temp;
    } else { //Entfernen in der Mitte -> Durchiterieren und Neuverknüpfen
        for(int i = 0; i < spot; ++i) {
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
    }
    free(ptr); //Speicher des selektierten Elements nach Neuverknüpfung freigeben
    header->counter--;
} 
NODE Lget(int spot, HEAD *header) { //Daten an gegebener Stelle zurückgeben
    if(spot >= header->counter || spot < 0) {return *createNode(0,0,' ');} //Argumente prüfen
    NODE *ptr = header->first;
    for(int i = 0; i < spot; ++i) { //Durchiterieren der Liste
        ptr = ptr->next;
    }
    NODE temp; //Speichern der Informationen der aktuellen Stelle
    temp.SIZE = ptr->SIZE;
    temp.ID = ptr->ID;
    temp.CONDITION = ptr->CONDITION;
    return temp;
} 
void Lclear(HEAD *header) { //Leert die Liste
    NODE *ptr = header->first;
    NODE *temp;
    for(int i = 0; i < header->counter; ++i) { //Durchiterieren und das letzte Element löschen
        if(ptr->next == NULL) {break;}
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    free(ptr); //Das verbleibende Element löschen
    header->first = NULL; //Header reset
    header->last = NULL;
    header->counter = 0;
}
int Llength(HEAD *header) {
    return header->counter; //Länge zurückgeben
}
