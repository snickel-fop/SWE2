/* VerketteteListen, V2.1
 * Created by Benjamin Zastrow, WIN-B
 * Eigene Implementierung einer doppelt-verketteten Liste (Adaptierung für accountingTool-Aufgabe)
 */


#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HEAD Linitialise(int maxSize) {
    HEAD tmp;
    tmp.counter = 0;
    tmp.first = NULL;
    tmp.last = NULL;
    return tmp;
}
int Lappend(float SOLL, float HABEN, float BETRAG, char* TEXT, HEAD *header) { //Element an der letzten Stelle hinzufügen; return: Stelle (-1 bei Fehler)
    NODE temp;
    temp.SOLL = SOLL;
    temp.HABEN = HABEN;
    temp.BETRAG = BETRAG;
    strcpy(temp.TEXT, TEXT);
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
int Linsert(int spot, float SOLL, float HABEN, float BETRAG, char* TEXT, HEAD *header) {//Element an gegebener Stelle einfügen; return 0: kein Problem, return -1: Problem
    if(spot > header->counter || spot < 0) {return -1;}
    NODE temp;
    temp.BETRAG = BETRAG;
    temp.HABEN = HABEN;
    temp.SOLL = SOLL;
    strcpy(temp.TEXT, TEXT);
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
        if(spot == header->counter) {Lappend(SOLL, HABEN, BETRAG, TEXT, header);}
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
void Lprint(HEAD *header) { //Gibt die Liste auf der Konsole aus
    NODE *ptr = header->first;
    for(int i = 0; i < header->counter; ++i) {
        printf("#%d: Text: %s, Soll: %f, Haben: %f, Betrag: %f\n", i, ptr->TEXT, ptr->SOLL, ptr->HABEN, ptr->BETRAG);
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
void LprintSpecificBetrag(float BETRAG, HEAD *header) {
    NODE *ptr = header->first;
    for(int i = 0; i < header->counter; ++i) {
        if(ptr->BETRAG == BETRAG) {
            printf("#%d: Text: %s, Soll: %f, Haben: %f, Betrag: %f\n", i, ptr->TEXT, ptr->SOLL, ptr->HABEN, ptr->BETRAG);
        }
        ptr = ptr->next;
    }
}
void LprintSpecificText(char *TEXT, HEAD *header) {
    NODE *ptr = header->first;
    for(int i = 0; i < header->counter; ++i) {
        if(strcmp(ptr->TEXT, TEXT) == 0) {
            printf("#%d: Text: %s, Soll: %f, Haben: %f, Betrag: %f\n", i, ptr->TEXT, ptr->SOLL, ptr->HABEN, ptr->BETRAG);
        }
        ptr = ptr->next;
    }
}
int Lexport(char* path, HEAD *header) {
    FILE* file = NULL;
    file = fopen(path, "w");
    if(file == NULL) {return -1;}
    NODE* ptr = header->first;
    for(int i = 0; i < header->counter; ++i) {
        fprintf(file, "%s,%f,%f,%f,", ptr->TEXT, ptr->SOLL, ptr->HABEN, ptr->BETRAG);
        ptr = ptr->next;
    }
    fclose(file);  
    return 0;
}
int Limport(char* path, HEAD *header) {
    FILE* file = NULL;
    file = fopen(path, "r");
    if(file == NULL) {return -1;}
    char fileContents[4096];
    char c;
    int counter = 0;
    while((c=fgetc(file)) != EOF) {
        fileContents[counter] = c;
        counter++;
    }
    fileContents[counter] = '\0';
    fclose(file);

    float tBETRAG, tSOLL, tHABEN;
    char tTEXT[128];
    char *token;
    token = strtok(fileContents, ",");
    if(token == NULL) {return 1;}
    while(1 == 1) {
        strcpy(tTEXT, token);
        token = strtok(NULL, ",");
        if(token == NULL) {break;}
        tSOLL = (float) atof(token);
        token = strtok(NULL, ",");
        if(token == NULL) {break;}
        tHABEN = (float) atof(token);
        token = strtok(NULL, ",");
        if(token == NULL) {break;}
        tBETRAG = (float) atof(token);
        Lappend(tSOLL, tHABEN, tBETRAG, tTEXT, header);
        token = strtok(NULL, ",");
        if(token == NULL) {break;}
    }
    
    return 0;
}