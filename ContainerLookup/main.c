#include "containerLookup.h"
#include <stdlib.h>


int main() {
    Node* r = ContainerInsert(1, 20, NULL);
    ContainerInsert(3, 15, r);
    ContainerInsert(2, 14, r);
    ContainerInsert(4, 16.4, r);
    ContainerInsert(6, 12.12, r);
    ContainerInsert(8, 19, r);
    ContainerInsert(7, 18.2, r);
    ContainerInsert(5, 14.1, r);
    ContainerInsert(11, 20, r);
    ContainerInsert(9, 110.2, r);
    ContainerInsert(10, 10.1, r);
    ContainerPrint(r);
    ContainerSearch(10.1, r);
    ContainerRemove(19, r);
    ContainerPrint(r);
}