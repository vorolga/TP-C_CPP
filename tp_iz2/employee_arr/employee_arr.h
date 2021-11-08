#ifndef TP_IZ2_EMPLOYEE_ARR_H
#define TP_IZ2_EMPLOYEE_ARR_H

#include "employee.h"

typedef struct EmployeeArr {
    int size;
    int real_size;
    Employee* employee;
} EmployeeArr;

EmployeeArr* create_employee_arr();

int add_element(EmployeeArr*, const Employee*);

int free_employee_arr(EmployeeArr*);

int average_salary(EmployeeArr*);

#endif //TP_IZ2_EMPLOYEE_ARR_H
