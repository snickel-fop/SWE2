/* ContainerLookup, V1.0
 * Created by Benjamin Zastrow, WIN-B
 * Verwaltung von Containern mittels einer Baumstruktur
 */

#include "containerLookup.h"
#include <stdio.h>
#include <stdlib.h>

Node* ContainerInsert(int ID, double VOLUME, Node* ROOT) {
    Node temp;
    Node* ptr;
    if((ptr = (Node*) malloc(sizeof(Node))) == NULL) {
		return NULL;
	}
    temp.c.id = ID;
    temp.c.volume = VOLUME;
    temp.greater = NULL;
    temp.lesser = NULL;
    *ptr = temp;
    if(ROOT == NULL) {
        return ptr;
    }
    else {
        Node* curr = ROOT;
        while(0==0) { //Realisierung mit Schleife
            if(VOLUME <= curr->c.volume) {
                if(curr->lesser == NULL) {
                    curr->lesser = ptr;
                    return ptr;
                }
                else {
                    curr = curr->lesser;
                }
            }
            else if(VOLUME > curr->c.volume) {
                if(curr->greater == NULL) {
                    curr->greater = ptr;
                    return ptr;
                }
                else {
                    curr = curr->greater;
                }
            }
        }
    }
}

void ContainerSearch(double VOLUME, Node* ROOT) { //Realisierung mittels Rekursion
    if(VOLUME < ROOT->c.volume) { 
        if(ROOT->lesser == NULL) {return;}
        ContainerSearch(VOLUME, ROOT->lesser);
    }
    else if(VOLUME > ROOT->c.volume) {
        if(ROOT->greater == NULL) {return;}
        ContainerSearch(VOLUME, ROOT->greater);
    }
    else {
        printf("Eintrag gefunden: ID: %d, Volumen: %lf\n", ROOT->c.id, ROOT->c.volume);
        if(ROOT->lesser != NULL) {
            ContainerSearch(VOLUME, ROOT->lesser);
        }
        if(ROOT->greater != NULL) {
            ContainerSearch(VOLUME, ROOT->greater);
        }
    }
}
Node* ContainerRemove(double VOLUME, Node* ROOT){ //Mit Hilfe aus dem Internet, das war mir mit Rekursion noch zu hoch (https://www.tutorialspoint.com/binary-search-tree-delete-operation-in-cplusplus)
    if(ROOT == NULL) {return ROOT;}
    if(VOLUME < ROOT->c.volume)
        ROOT->lesser = ContainerRemove(VOLUME, ROOT->lesser);
    else if(VOLUME > ROOT->c.volume)
        ROOT->greater = ContainerRemove(VOLUME, ROOT->greater);
    else {
        if(ROOT->lesser == NULL){
            Node *temp = ROOT->greater;
            free(ROOT);
            return temp;
        }
        else if(ROOT->greater == NULL){
            Node *temp = ROOT->greater;
            free(ROOT);
            return temp;
        }
        Node* current = ROOT->greater;
        while (current && current->lesser != NULL) {current = current->lesser;}
        Node* temp = current;
        ROOT->c.volume = temp->c.volume;
        ROOT->greater = ContainerRemove(temp->c.volume, ROOT->greater);
    }
    return ROOT;
}
void ContainerPrint(Node* ROOT) { //In-Order-Traversierung (l-m-r) mit Rekursion
    if(ROOT->lesser != NULL) {
        ContainerPrint(ROOT->lesser);
    }
    printf("ID: %d, Volumen: %lf\n", ROOT->c.id, ROOT->c.volume);
    if(ROOT->greater != NULL) {
        ContainerPrint(ROOT->greater);
    }
}