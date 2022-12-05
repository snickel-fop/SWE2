/* Queue, V1.0
 * Created by Benjamin Zastrow, WIN-B
 * Implementierung einer Queue-Datenstruktur basierend auf einer verketteten Liste
 */

#include "Queue.h"

Queue initialiseQueue(int maxSize) {
    return Linitialise(maxSize);
}
int enqueue(int newInt, Queue *queue) {
    return LinsertBack(newInt, queue);
}
int dequeue(Queue *queue) {
    int temp = Lget(0, queue);
    LremoveFront(queue);
    return temp;
}
int isEmpty(Queue *queue) {
    if(Llength(queue) == 0) {
        return 1;
    }
    else {return 0;}
}
int first(Queue *queue) {
    return Lget(0, queue);
}
int length(Queue *queue) {
    return Llength(queue);
}
int size(Queue *queue) {
    return queue->maxSize;
}
void reset(Queue *queue) {
    Lclear(queue);
}