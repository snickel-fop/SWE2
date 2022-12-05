#include <stdio.h>

int main() {
    int zahl;
    int* ptr = &zahl; //Anlegen eines int-Pointers mit int*, welcher mit der Adresse der Variablen zahl verknüpft wird.
    printf("INT-Variable angelegt. Aktueller Inhalt: %d; Adresse im Speicher: %p\n", zahl, (void*) &zahl);
    printf("So geht es aber jetzt auch: Inhalt: %d; Adresse: %p\n", *ptr, (void*) ptr); //mit *ptr wird auf den Inhalt des Speichers an der Adresse ptr zugegriffen.
    printf("Geben sie eine neue Ganzzahl ein: "); scanf("%d", ptr); //Zugriff auf die Adresse von Zahl
    printf("Der neue Inhalt der Variablen ist: %d\n", *ptr);
}