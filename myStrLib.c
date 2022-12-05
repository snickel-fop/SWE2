#include <stdio.h>
#include "myStrLib.h"

int StrLength(char* Str) { //Funktion, um die Länge eines Strings zu bestimmen (Ohne '\0')
    int i;
    for(i = 0; i > -1; ++i) {
        if(Str[i] == '\0') {break;}
    }
    return i;
}

int StrCompare(char* str1, char* str2) { //Gibt -1 bei Ungleichheit und 0 bei Gleichheit zurück
    if(StrLength(str1) != StrLength(str2)) {
        return -1; //Strings haben unterschiedliche Länge
    }
    for(int i = 0; i < StrLength(str1); i++) { //Durchlaufen der Arrays Zeichen für Zeichen
        if(str1[i] != str2[i]) { //Vergleichen beider Arrays an jeweils der gleichen Position
            return -1; //Strings sind nicht gleich an der Stelle
        }
    }
    return 0; //Bei erfolgreichem Schleifendurchlauf sind Strings identisch
}

void StrCopy(char* src, char* dst) { //Kopiert den String bei src nach dst
    for(int i = 0; i > -1; ++i) { //Schrittweises Kopieren der Zeichen aus str1 in str2
        dst[i] = src[i];
        if(dst[i] == '\0') {break;}
    }
}

void StrCat(char* str1, char* str2, char* dst) { //Fügt str2 an str1 an und speichert das Ergebnis in dst
    int c;
    for(c = 0; c > -1; ++c) { //Kopieren von str1 nach dst (ohne '\0')
        if(str1[c] == '\0') {break;}
        dst[c] = str1[c];
    }
    for(int d = c; d > -1; ++d) { //Anfügen von str2 nach dst (mit '\0')
        dst[d] = str2[d-c];
        if(str2[d-c] == '\0') {break;}
    }
}

int StrCheckPalindrome(char* str) { //Prüft, ob str ein Palindrom ist; Gibt 1 zurück, wenn ja; Gibt 0 zurück, wenn nein.
    int len = StrLength(str) - 1;
    for(int i = 0; i < len; ++i) {
        if(str[i] != str[len-i]) {
            return 0;
        }
    }
    return 1;
}

void StrNCat(char* str1, char* str2, char* dst, int length) { //Fügt length Zeichen von str2 an str1 an und speichert das Ergebnis in dst
    int c, d;
    for(c = 0; c > -1; ++c) { //Kopieren von str1 nach dst (ohne '\0')
        if(str1[c] == '\0') {break;}
        dst[c] = str1[c];
    }
    for(d = c; (d-c) < length; ++d) { //Anfügen von length Zeichen aus str2 nach dst (mit '\0')
        dst[d] = str2[d-c];
        if(str2[d-c] == '\0') {break;}
    }
    if(dst[d] != '\0') {dst[d] = '\0';}
}

int StrStr(char* haystack, char* needle) { //Gibt 0 zurück, wenn needle nicht in haystack vorkommt; Gibt 1 zurück, wenn schon.
    int needleCounter = 0;
    for(int i = 0; i < StrLength(haystack); ++i) {
        if(haystack[i] == needle[needleCounter]) {
            needleCounter++;
        }
    }
    if(StrLength(needle) != needleCounter) {
        return 0;
    } else {
        return 1;
    }
}