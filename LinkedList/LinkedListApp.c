/* VerketteteListen, V1.0
 * Created by Benjamin Zastrow, WIN-B
 * Eigene Implementierung einer verketteten Liste
 */

#include "LinkedList.h"
#include <stdio.h>

int main() {
    HEAD test = Linitialise();
    /* 
    Lappend(20, &test);
    Lappend(1.4, &test);
    Lappend(1.4, &test);
    Lappend(1.4, &test);
    Lappend(1.4, &test);
    Lappend(1.4, &test);
    Lappend(1.4, &test);
    Lappend(40, &test);
    */
    Limport("test.bin", 1, &test);
    Lprint(&test);
    Lexport("test.txt", 0, &test);
    Lclear(&test);
}