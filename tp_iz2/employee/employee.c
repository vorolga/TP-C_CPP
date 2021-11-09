#include "employee.h"
#include <stdlib.h>
#include <string.h>

int read_employee_from_file(FILE* file, Employee* employee)
{
    if (!file || !employee) {
        return 1;
    }

    char buff[20];

    fscanf(file, "%19s", buff);
    if (feof(file)) {
        return 1;
    }
    employee->name = (char*)malloc(strlen(buff) + 1);
    if (!employee->name) {
        return 1;
    }
    strncpy(employee->name, buff, strlen(buff) + 1);

    fscanf(file, "%19s", buff);
    employee->surname = (char*)malloc(strlen(buff) + 1);
    if (!employee->surname) {
        free(employee->name);
        return 1;
    }
    strncpy(employee->surname, buff, strlen(buff) + 1);

    fscanf(file, "%19s", buff);
    employee->gender = (char*)malloc(strlen(buff) + 1);
    if (!employee->gender) {
        free(employee->name);
        free(employee->surname);
        return 1;
    }
    strncpy(employee->surname, buff, strlen(buff) + 1);

    fscanf(file, "%hd", &employee->age);

    fscanf(file, "%d", &employee->salary);

    fscanf(file, "%19s", buff);
    employee->position = (char*)malloc(strlen(buff) + 1);
    if (!employee->position) {
        free(employee->name);
        free(employee->surname);
        free(employee->gender);
        return 1;
    }
    strncpy(employee->position, buff, strlen(buff) + 1);

    fscanf(file, "%hd", &employee->experience);
    return 0;
}
