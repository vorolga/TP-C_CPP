#ifndef TP_C_CPP_EMPLOYEE_H
#define TP_C_CPP_EMPLOYEE_H
#include <stdio.h>

typedef struct Employee {
    char* name;
    char* surname;
    char* position;
    char* gender;
    int salary;
    short age;
    short experience;
} Employee;

int read_employee_from_file(FILE*, Employee*);

#endif //TP_C_CPP_EMPLOYEE_H
