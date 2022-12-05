#include "assemblyLineOverview.h"

int main() {
    HEAD h = createList();
    addNodeFirst(createNode(1,20,'g'), &h);
    addNodeFirst(createNode(2,3,'m'), &h);
    addNodeLast(createNode(3,23,'b'), &h);
    addNodeAfterValue(createNode(4, 1, 'g'), 0, &h);
    printList(&h);
    removeFirstNode(&h);
    printList(&h);
    removeLastNode(&h);
    printList(&h);
    removeNodeWithValue(1, 20, 'g', &h);
    printList(&h);
    resetList(&h);
    printList(&h);

}