/* Stack, V1.0
 * Created by Benjamin Zastrow, WIN-B
 * Implementierung einer Stack-Datenstruktur basierend auf einer verketteten Liste
 */

#include "Stack.h"

Stack initialiseStack(int maxSize){
    return Linitialise(maxSize);
}
int push(int newInt, Stack *stack) {
    return LinsertBack(newInt, stack);
}
int pop(Stack *stack) {
    int temp = Lget(stack->counter-1, stack);
    LremoveBack(stack);
    return temp;
}
int isEmpty(Stack *stack) {
    if(Llength(stack) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}
int isFull(Stack *stack) {
    if(Llength(stack) == stack->maxSize) {
        return 1;
    }
    else {
        return 0;
    }
}
int top(Stack *stack) {
    return Lget(stack->counter-1, stack);
}
int length(Stack *stack) {
    return Llength(stack);
}
int size(Stack *stack) {
    return stack->maxSize;
}
void reset(Stack *stack) {
    Lclear(stack);
}