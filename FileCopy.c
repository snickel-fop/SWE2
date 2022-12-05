/* FileCopy, V1.0
 * Created by Benjamin Zastrow, WIN-B, Simon Kranzer
 * Kopiert eine Datei zu einem neuen Pfad
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    if(argc == 1) { printf("USAGE: %s srcfile dstfile\n", argv[0]); return 1; }

    FILE* src;
    FILE* dst;
    src = fopen(argv[1], "rt");
    if(NULL == src) { printf("File %s does not exist or is not readable!\n", argv[1]); return 1; }
    dst = fopen(argv[2], "rt");
    if(dst != NULL) {
        printf("Destination file %s already exists. Exiting...\n", argv[2]);
        fclose(dst);
        return 1;
    }
    else {
        dst = fopen(argv[2], "wt");
        if(dst == NULL) {
            printf("Unable to open destination file. Exiting...\n");
            return 1;
        }
        else {
            int c;
            while(EOF != (c = fgetc(src)))
            {
                fputc(c, dst);
            }
        }
    }

    fclose(dst);
    fclose(src);

    return 0;
}
