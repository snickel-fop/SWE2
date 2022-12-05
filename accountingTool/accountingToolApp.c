#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    HEAD h = Linitialise();
    if(argc > 2) {
        printf("Syntax: %s [Dateipfad]\n", argv[0]);
        return 1;
    }
    else if(argc == 2) {
        FILE *tmpF = fopen(argv[1], "r");
        if(tmpF == NULL) {
            printf("!!! Fehler: Datei existiert nicht, keine Daten werden geladen!\n");
        }
        else {
            fclose(tmpF);
            Limport(argv[1], &h);
            printf("--- %d Eintraege wurden geladen ---\n", Llength(&h));
        }
    }
    else {
        printf("--- Keine Datei spezifiziert. Starte mit leerer Liste. ---\n");
    }

    int selection = 0, saved = 1, tmp = 0;
    float tBETRAG = 0.0, tSOLL = 0.0, tHABEN = 0.0;
    char tTEXT[128], tBETRAGINPUT[32], filePath[128], fileName[32];
    while(1 == 1) {
        printf("--- MENUE ---\n(1) Buchungssatz hinzufuegen\n(2) Buchungssaetze auf der Konsole ausgeben\n(3) Buchungssatz mit bestimmtem Text suchen\n(4) Alle Buchungssaetze mit bestimmtem Betrag auf der Konsole ausgeben\n(5) Buchungssatz an x-ter Stelle der Liste entfernen\n(6) Liste in Datei exportieren\n(7) Programm beenden\n\nEingabe> ");
        scanf("%d", &selection);
        switch (selection)
        {
        case 1:
            printf("Geben Sie einen Sollbetrag ein: ");
            scanf("%f", &tSOLL);
            printf("Geben Sie einen Habenbetrag ein: ");
            scanf("%f", &tHABEN);
            printf("Geben Sie einen Saldobetrag ein ('default' fuer %f): ", tHABEN - tSOLL);
            scanf("%s", tBETRAGINPUT);
            if(strcmp(tBETRAGINPUT, "default") == 0) {tBETRAG = tHABEN - tSOLL;}
            else {tBETRAG = (float) strtod(tBETRAGINPUT, NULL);}
            printf("Geben Sie einen Beschreibungstext ein: ");
            scanf("%s", tTEXT);

            Lappend(tSOLL, tHABEN, tBETRAG, tTEXT, &h);
            saved = 0;
            printf("\n");
            break;
        case 2:
            Lprint(&h);
            break;
        case 3:
            printf("Eingabe des zu suchenden Texts: ");
            scanf("%s", tTEXT);
            LprintSpecificText(tTEXT, &h);
            printf("\n");
            break;
        case 4:
            printf("Eingabe des zu suchenden Betrags: ");
            scanf("%f", &tBETRAG);
            LprintSpecificBetrag(tBETRAG, &h);
            printf("\n");
            break;
        case 5:
            printf("An welcher Stelle soll ein Buchungssatz entfernt werden [0-%d]: ", Llength(&h)-1);
            scanf("%d", &tmp);
            if(tmp > Llength(&h)-1 || tmp < 0) {printf("Eingabefehler: Ungueltige Zahl!"); break;}
            LremoveSpot(tmp, &h);
            saved = 0;
            break;
        case 6:
            printf("Geben Sie den relativen oder Absoluten Pfad+Dateiname fuer die Datei ein: ");
            scanf("%s", filePath);
            Lexport(filePath, &h);

            saved = 1;
            printf("\n");
            break;
        case 7:
            if(saved == 0) {
                printf("Liste wurde ungespeichert veraendert, wollen Sie das Programm trotzdem verlassen? [ja/nein]: ");
                scanf("%s", tTEXT);
                if(strcmp(tTEXT, "ja") == 0) {
                    return 0;
                }
                else if(strcmp(tTEXT, "nein") == 0) {
                    break;
                }
                else {
                    printf("Keine gueltige Antwort!\n");
                }
            }
            else {
                return 0;
            }
            break;
        
        default:
            break;
        }
    }
}