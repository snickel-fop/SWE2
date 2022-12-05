#include "Stack.h"
#include <stdio.h>

int main() {
    Stack s = initialiseStack(10);
    printf("size: %d, length: %d\n", size(&s), length(&s));
    push(1, &s);
    push(2, &s);
    push(3, &s);
    push(4, &s);
    push(5, &s);
    push(6, &s);
    push(7, &s);
    push(8, &s);
    push(9, &s);
    push(10, &s);
    push(11, &s);
    printf("size: %d, length: %d\n", size(&s), length(&s));
    Lprint(&s);
    printf("Pop: %d\n", pop(&s));
    printf("Pop: %d\n", pop(&s));
    printf("Pop: %d\n", pop(&s));
    printf("Pop: %d\n", pop(&s));
    printf("size: %d, length: %d\n", size(&s), length(&s));
    printf("top: %d\n", top(&s));
    Lprint(&s);
    reset(&s);
    printf("size: %d, length: %d\n", size(&s), length(&s));
}