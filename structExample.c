/* StructExample, V1.0
 * Created by Benjamin Zastrow, WIN-B
 * Struct example storing people in a companies database
 */

#include <stdio.h>
#include <string.h>
#include "structExample.h"

#define DBSIZE 64

int main()
{
    EMPLOYEE employees[DBSIZE]; //Erstellung eines Mitarbeiter-Arrays
    printf("---MitarbeiterDB---\n(Zum Beenden der Eingabe geben sie '-' im Feld Vorname ein.)\n");
    for(int i = 0; i < DBSIZE; ++i) {
        printf("\nMitarbeiter #%d\n---------------\n", i+1);
        printf("Geben Sie den Vornamen des Mitarbeiters ein: "); scanf("%s", employees[i].Fname);
        if(strcmp(employees[i].Fname, "-") == 0) {break;}
        printf("Geben Sie den Nachnamen des Mitarbeiters ein: "); scanf("%s", employees[i].Lname);
        printf("Geben Sie das Alter des Mitarbeiters ein: "); scanf("%d", &employees[i].Age);
        printf("Geben Sie das Gehalt des Mitarbeiters ein: "); scanf("%d", &employees[i].Salary);
        printf("Geben Sie die Abteilung des Mitarbeiters ein [OTHER: 0, ADMIN: 1, FINANCE: 2, PRODUCTION: 3, LOGISTICS: 4, HRM: 5, RESEARCHANDDEVELOPMENT: 6, MARKETING: 7, CONTROLING: 8]: "); scanf("%d", &employees[i].Department);
        printf("Geben Sie die Pendlerstrecke des Mitarbeiters in KM ein: "); scanf("%f", &employees[i].CommuteInKM);
        printf("Geben Sie die Arbeitsstundenzahl des Mitarbeiters ein: "); scanf("%d", &employees[i].HoursPerWeek);
    }
    printf("Ausgabe der Datenbank: \n");
    for(int i = 0; i < DBSIZE; ++i) {
        if(strcmp(employees[i].Fname, "-") == 0) {break;}
        printf("%s %s, Alter: %d, Gehalt: %d, Abteilungs-ID: %d, Pendlerstrecke: %f, Stundenzahl: %d\n", employees[i].Fname, employees[i].Lname, employees[i].Age, employees[i].Salary, employees[i].Department, employees[i].CommuteInKM, employees[i].HoursPerWeek);
    }
    printf("\n");
}
