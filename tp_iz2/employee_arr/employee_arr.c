#include "employee_arr.h"
#include <stdlib.h>

EmployeeArr* create_employee_arr()
{
    EmployeeArr* employeeArr = (EmployeeArr*)malloc(sizeof(EmployeeArr));
    if (!employeeArr) {
        return NULL;
    }

    employeeArr->size = 10;
    employeeArr->real_size = 0;

    employeeArr->employee = (Employee*)malloc(employeeArr->size * sizeof(Employee));
    if (!employeeArr->employee) {
        free(employeeArr);
        return NULL;
    }
    return employeeArr;
}

int resize(EmployeeArr* employeeArr)
{
    if (!employeeArr) {
        return 1;
    }

    employeeArr->employee = (Employee*)realloc(employeeArr->employee, 2 * employeeArr->size * sizeof(Employee));

    if (!employeeArr->employee) {
        return 1;
    }

    employeeArr->size *= 2;

    return 0;
}

int add_element(EmployeeArr* employeeArr, const Employee* employee)
{
    if (!employeeArr || !employee) {
        return 1;
    }

    if (employeeArr->size < employeeArr->real_size + 1) {
        if (resize(employeeArr)) {
            return 1;
        }
    }
    employeeArr->employee[employeeArr->real_size++] = *employee;

    return 0;
}

int free_employee_arr(EmployeeArr* employeeArr)
{
    if (!employeeArr) {
        return 1;
    }

    for (size_t i = 0; i < employeeArr->real_size; ++i) {
        free(employeeArr->employee[i].name);
        free(employeeArr->employee[i].surname);
        free(employeeArr->employee[i].position);
        free(employeeArr->employee[i].gender);
    }

    free(employeeArr->employee);

    free(employeeArr);

    return 0;
}

int average_salary(EmployeeArr* employeeArr)
{
    if (!employeeArr) {
        return 1;
    }
    int sum_salary = 0;
    for (size_t i = 0; i < employeeArr->real_size; i++) {
        sum_salary = sum_salary + employeeArr->employee[i].salary;
    }

    double avg_salary = (double)sum_salary / (double)employeeArr->real_size;
    printf("Average salary: %f\n", avg_salary);
    return 0;
}

int get_sum(EmployeeArr* employeeArr, size_t start, size_t end)
{
    if (!employeeArr) {
        exit(EXIT_FAILURE);
    }
    int sum_salary = 0;
    for (size_t i = start; i < end; ++i) {
        sum_salary = sum_salary + employeeArr->employee[i].salary;
    }
    return sum_salary;
}
