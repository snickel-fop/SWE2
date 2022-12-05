#ifndef STRUCTEXAMPLE_H
#define STRUCTEXAMPLE_H

typedef enum department {OTHER, ADMIN, FINANCE, PRODUCTION, LOGISTICS, HRM, RESEARCHANDDEVELOPMENT, MARKETING, CONTROLING} DEPARTMENT;

typedef struct employee {
    char Fname[32];
    char Lname[32];
    int Age;
    DEPARTMENT Department;
    int Salary;
    int HoursPerWeek;
    float CommuteInKM;
} EMPLOYEE;

#endif // STRUCTEXAMPLE_H
