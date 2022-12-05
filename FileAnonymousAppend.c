/* FileAnonymousAppend.c, V1.0
 * Created by Benjamin Zastrow, WIN-B
 * Hängt den Inhalt einer Textdatei an eine andere Textdatei an, ersetzt aber einen String des Orginals durch ***
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    if(argc < 4) {printf("Usage: %s srcFile destFile replaceSting\n", argv[0]); return 1;}

    FILE* src = NULL;
    FILE* dest = NULL;
	//Abbrechen, wenn Dateistreams nicht zu öffnen
    if((src = fopen(argv[1], "r")) == NULL) {printf("Specified source file %s does not exist or cannot be opened in read-mode!\n", argv[1]); return 1;} 
    if((dest = fopen(argv[2], "a")) == NULL) {printf("Specified destination file %s cannot be opened in write-mode!\n", argv[2]); fclose(src); return 1;}
    
    char temp[2048];
    char c;
    int counter = 0;
    while((c = fgetc(src)) != EOF) { //Datei src in einen String einlesen
        temp[counter] = c;
        counter++;
    }
    temp[counter] = '\0';

    for(int i = 0; i < strlen(temp); ++i) { //String durcharbeiten...
        if(temp[i] == argv[3][0]) {
            for(int j = 0; j < strlen(argv[3]); ++j) { //String in argv[3] im String temp durch * ersetzen
                if(temp[i+j] == argv[3][j]) {
                    temp[i+j] = '*';
                }
            }
        }
    }

    for(int i = 0; temp[i] != '\0'; ++i) { //Datei schreiben (im append-mode)
        fputc(temp[i], dest);
    }
    
    fclose(src); //Dateien schließen
    fclose(dest);
}