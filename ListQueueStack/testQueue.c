#include "Queue.h"
#include <stdio.h>

int main() {
    Queue q = initialiseQueue(10);
    printf("size: %d, length: %d\n", size(&q), length(&q));
    enqueue(1, &q);
    enqueue(2, &q);
    enqueue(3, &q);
    enqueue(4, &q);
    enqueue(5, &q);
    enqueue(6, &q);
    enqueue(7, &q);
    enqueue(8, &q);
    enqueue(9, &q);
    enqueue(10, &q);
    enqueue(11, &q);
    printf("size: %d, length: %d\n", size(&q), length(&q));
    Lprint(&q);
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    printf("size: %d, length: %d\n", size(&q), length(&q));
    printf("First: %d\n", first(&q));
    Lprint(&q);
    reset(&q);
    printf("size: %d, length: %d\n", size(&q), length(&q));
}