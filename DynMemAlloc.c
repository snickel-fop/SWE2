/* DynMemAlloc, V1.0
 * Created by Benjamin Zastrow, WIN-B2020
 * Utilises dynamic memory allocation to store Strings
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* strptrs[64];
    int counter = 0;
    char temp[128];
    printf("StringDB!\nGeben sie Strings ein, um alle Strings auszugeben, bestätigen sie ihre Eingabe mit '0'!\n");
    for(int i = 0; i < 64; ++i) {
        printf("Eingabe: ");
        scanf("%s", temp);
        if(strcmp(temp, "0\0") == 0) { break; }
        strptrs[counter] = (char*) malloc((strlen(temp) * sizeof(char)) + 2*sizeof(char));
        strcpy(strptrs[counter], temp);
    }
    printf("Ausgabe aller Strings: ");
    for(int i = 0; i < counter; ++i) {
        printf("\n%s", strptrs[counter]);
        free(strptrs[counter]);
    }
    return 0;
}
