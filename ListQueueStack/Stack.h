/* Stack, V1.0
 * Created by Benjamin Zastrow, WIN-B
 * Implementierung einer Stack-Datenstruktur basierend auf einer verketteten Liste
 */

#include "LinkedList.h"

typedef HEAD Stack;

Stack initialiseStack(int maxSize); //Erstellt einen Stack mit begrenzter Größe (maxSize = 0: variable Größe)
int push(int newInt, Stack *stack); //Fügt ein Element new auf den Stack hinzu. Gibt 0 bei Erfolg zurück, -1 bei Fehler.
int pop(Stack *stack); //Gibt das oberste Element zurück und entfernt dieses anschließend aus dem Stack
int isEmpty(Stack *stack); //Gibt 1 zurück, wenn der Stack leer ist, 0 wenn nicht.
int isFull(Stack *stack); //Gibt 1 zurück, wenn der Stack voll ist, 0 wenn nicht.
int top(Stack *stack); //Gibt das oberste Element zurück
int length(Stack *stack); //Gibt die Länge des Stacks (befüllte Elemente) zurück
int size(Stack *stack); //Gibt die Größe des Stacks (maximale Elementzahl) zurück
void reset(Stack *stack); //Leert den Stack (oder initialisiert ihn)