#include "main_func.h"
#include <stdlib.h>
#include <string.h>

#define N_STR_EMPLOYEE 140
#define N_ELEMENT_EMPLOYEE 20

int read_file(Node** list_position_experience, char* filename)
{
    if (!list_position_experience) {
        return 1;
    }

    FILE* file;

    file = fopen(filename, "r");
    if (!file) {
        return 1;
    }

    if (read_from_file(file, list_position_experience)) {
        return 1;
    }

    fclose(file);
    return 0;
}

int add_employee(Node** list_position_experience, char* filename)
{
    if (!list_position_experience) {
        return 1;
    }

    FILE* file;

    file = fopen(filename, "a");
    if (file == NULL) {
        return 1;
    }

    Employee employee;

    char buff[N_ELEMENT_EMPLOYEE];
    char buff_str[N_STR_EMPLOYEE];

    printf("\nName:");
    scanf("%19s", buff);
    employee.name = (char*)malloc(strlen(buff) + 1);
    if (!employee.name) {
        return 1;
    }
    strncpy(employee.name, buff, strlen(buff) + 1);
    strcat(buff, " ");
    strcat(buff_str, buff);

    printf("\nSurname:");
    scanf("%19s", buff);
    employee.surname = (char*)malloc(strlen(buff) + 1);
    if (!employee.surname) {
        free(employee.name);
        return 1;
    }
    strncpy(employee.surname, buff, strlen(buff) + 1);
    strcat(buff, " ");
    strcat(buff_str, buff);

    printf("\nGender:");
    scanf("%6s", buff);
    if (strncmp(buff, "Male", strlen("Male")) != 0 && strncmp(buff, "Female", strlen("Female")) != 0) {
        return 1;
    }
    employee.gender = (char*)malloc(strlen(buff) + 1);
    if (!employee.gender) {
        free(employee.name);
        free(employee.surname);
        return 1;
    }
    strncpy(employee.gender, buff, strlen(buff) + 1);
    strcat(buff, " ");
    strcat(buff_str, buff);

    printf("\nAge:");
    scanf("%3s", buff);
    char* end;
    if (strtol(buff, &end, 10) < 18 || strtol(buff, &end, 10) > 70) {
        return 1;
    }
    employee.age = (short)strtol(buff, &end, 10);
    strcat(buff, " ");
    strcat(buff_str, buff);

    printf("\nSalary:");
    scanf("%7s", buff);
    employee.salary = (int)strtol(buff, &end, 10);
    strcat(buff, " ");
    strcat(buff_str, buff);

    printf("\nPosition:");
    scanf("%19s", buff);
    employee.position = (char*)malloc(strlen(buff) + 1);
    if (!employee.position) {
        free(employee.name);
        free(employee.surname);
        free(employee.gender);
        return 1;
    }
    strncpy(employee.position, buff, strlen(buff) + 1);
    strcat(buff, " ");
    strcat(buff_str, buff);

    printf("\nExperience:");
    scanf("%3s", buff);
    if (strtol(buff, &end, 10) < 0 || strtol(buff, &end, 10) > 52) {
        return 1;
    }
    employee.experience = (short)strtol(buff, &end, 10);
    strcat(buff, " ");
    strcat(buff_str, buff);

    fprintf(file, "%s", buff_str);
    fclose(file);

    Node* node = find_node(*list_position_experience, employee.position, employee.experience);
    if (!node) {
        if (add_node(list_position_experience, buff, (short)strtol(buff, &end, 10))) {
            return 1;
        }
        if (add_element((*list_position_experience)->employeeArr, &employee)) {
            return 1;
        }
    } else {
        add_element(node->employeeArr, &employee);
    }

    return 0;
}