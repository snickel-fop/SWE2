/* Queue, V1.0
 * Created by Benjamin Zastrow, WIN-B
 * Implementierung einer Queue-Datenstruktur basierend auf einer verketteten Liste
 */

#include "LinkedList.h"

typedef HEAD Queue;

Queue initialiseQueue(int maxSize); //Erstellt eine neue Queue mit begrenzter Größe (maxSize = 0: variable Größe)
int enqueue(int newInt, Queue *queue); //Fügt ein Element der Queue hinzu. Gibt 0 bei Erfolg zurück, -1 bei Fehler.
int dequeue(Queue *queue); //Gibt das erste Element zurück und entfernt dieses anschließend aus der Queue (+ nachfolgende Restrukturierung, damit die Queue wieder mit dem ersten Element bei [0] beginnt)
int isEmpty(Queue *queue); //Gibt 1 zurück, wenn die Queue leer ist, 0 wenn nicht.
int first(Queue *queue); //Gibt das erste Element zurück
int length(Queue *queue); //Gibt die Länge der Queue (befüllte Elemente) zurück
int size(Queue *queue); //Gibt die Größe der Queue (maximale Elementzahl) zurück
void reset(Queue *queue); //Leert die Queue (oder initialisiert sie)