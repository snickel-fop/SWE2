/* VerketteteListen, V2.0
 * Created by Benjamin Zastrow, WIN-B
 * Eigene Implementierung einer verketteten Liste (Adaptierung für Stack- und Queue-Aufgabe)
 */


#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

HEAD Linitialise(int maxSize) {
    HEAD tmp;
    tmp.counter = 0;
    tmp.maxSize = maxSize;
    tmp.first = NULL;
    tmp.last = NULL;
    return tmp;
}
int Lappend(int data, HEAD *header) { //Element an der letzten Stelle hinzufügen; return: Stelle (-1 bei Fehler)
    if(header->counter == header->maxSize && header->maxSize != 0) {return -1;}
    
    NODE temp;
    temp.data = data;
    if(header->counter == 0) {
        header->first = malloc(sizeof(NODE));
        if(header->first == NULL) {return -1;}
        header->last = header->first;
        temp.next = NULL;
        temp.before = NULL;
        *(header->first) = temp;
        header->counter++;
    }
    else {
        header->last->next = malloc(sizeof(NODE));
        if(header->last->next == NULL) {return -1;}
        temp.next = NULL;
        temp.before = header->last;
        header->last = header->last->next;
        *(header->last) = temp;
        header->counter++;
    }
    return header->counter-1;
} 
int Linsert(int spot, int data, HEAD *header) {//Element an gegebener Stelle einfügen; return 0: kein Problem, return -1: Problem
    if(header->counter == header->maxSize && header->maxSize != 0) {return -1;}
    
    if(spot > header->counter || spot < 0) {return -1;}
    NODE temp;
    temp.data = data;
    if(header->counter == 0) {
        header->first = malloc(sizeof(NODE));
        if(header->first == NULL) {return -1;}
        header->last = header->first;
        temp.next = NULL;
        temp.before = NULL;
        *(header->first) = temp;
        header->counter++;
    }
    else {
        if(spot == header->counter) {Lappend(data, header);}
        else if(spot == 0) {
            temp.before = NULL;
            temp.next = header->first;
            header->first = malloc(sizeof(NODE));
            if(header->first == NULL) {header->first = temp.next; return -1;}
            *(header->first) = temp;
            header->counter++;
        }
        else {
            NODE* ptr = header->first;
            NODE* newptr;
            for(int i = 0; i < spot-1; ++i) {
                ptr = ptr->next;
            }
            temp.before = ptr;
            temp.next = ptr->next;
            newptr = malloc(sizeof(NODE));
            if(newptr == NULL) {return -1;}
            *newptr = temp;
            ptr->next->before = newptr;
            ptr->next = newptr;
            header->counter++;
        }
    }
    return 0;
} 
void LremoveSpot(int spot, HEAD *header) { //Element an der Stelle entfernen
    if(spot >= header->counter || spot < 0) {return;}
    NODE *ptr = header->first;
    if(spot == 0) {
        ptr->next->before = NULL;
        header->first = ptr->next;
    } else if(spot == header->counter-1) {
        ptr = header->last;
        header->last = ptr->before;
        header->last->next = NULL;
    } else {
        for(int i = 0; i < spot; ++i) {
            ptr = ptr->next;
        }
        ptr->before->next = ptr->next;
        ptr->next->before = ptr->before;
    }
    free(ptr);
    header->counter--;
} 
int Lget(int spot, HEAD *header) { //Daten an gegebener Stelle zurückgeben
    if(spot >= header->counter || spot < 0) {return -1;}
    NODE *ptr = header->first;
    for(int i = 0; i < spot; ++i) {
        ptr = ptr->next;
    }
    return ptr->data;
} 
int Lsearch(int data, HEAD *header) { //Sucht, ob Daten in der Liste vorhanden sind; Return 0: gefunden, Return -1: nicht gefunden
    NODE *ptr = header->first;
    for(int i = 0; i < header->counter; ++i) {
        if(ptr->data == data) {return 0;}
        ptr = ptr->next;
    }
    return -1;
}
void Lprint(HEAD *header) { //Gibt die Liste auf der Konsole aus
    NODE *ptr = header->first;
    for(int i = 0; i < header->counter; ++i) {
        printf("#%d: %d\n", i, ptr->data);
        ptr = ptr->next;
    }
}
void Lclear(HEAD *header) { //Leert die Liste
    NODE *ptr = header->first;
    for(int i = 0; i < header->counter; ++i) {
        if(ptr->next == NULL) {break;}
        ptr = ptr->next;
        free(ptr->before);
    }
    free(ptr);
    header->first = NULL;
    header->last = NULL;
    header->counter = 0;
} 
int Llength(HEAD *header) {
    return header->counter;
}

int LinsertFront(int data, HEAD *header) {
    return Linsert(0, data, header);
}
int LinsertBack(int data, HEAD *header) {
    return Lappend(data, header);
}
void LremoveFront(HEAD *header) {
    LremoveSpot(0, header);
}
void LremoveBack(HEAD *header) {
    LremoveSpot(header->counter-1, header);
}