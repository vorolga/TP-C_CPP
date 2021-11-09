#include "gtest/gtest.h"

extern "C" {
#include "employee_arr.h"
}

TEST(GET_SUM_TEST, null_arr)
{
    EmployeeArr* employee_arr = NULL;

    EXPECT_EQ(get_sum(employee_arr, 0, 1), -2);
}

TEST(GET_SUM_TEST, full_arr)
{
    EmployeeArr* employee_arr = create_employee_arr();

    Employee employee;

    employee.name = (char*)malloc(strlen("Olga") + 1);
    strncpy(employee.name, "Olga", strlen("Olga") + 1);

    employee.surname = (char*)malloc(strlen("Voronova") + 1);
    strncpy(employee.surname, "Voronova", strlen("Voronova") + 1);

    employee.gender = (char*)malloc(strlen("Female") + 1);
    strncpy(employee.gender, "Female", strlen("Female") + 1);

    employee.age = 20;

    employee.salary = 80000;

    employee.position = (char*)malloc(strlen("Developer") + 1);
    strncpy(employee.position, "Developer", strlen("Developer") + 1);

    employee.experience = 1;

    add_element(employee_arr, &employee);

    employee.name = (char*)malloc(strlen("O") + 1);
    strncpy(employee.name, "O", strlen("O") + 1);

    employee.surname = (char*)malloc(strlen("V") + 1);
    strncpy(employee.surname, "V", strlen("V") + 1);

    employee.gender = (char*)malloc(strlen("Female") + 1);
    strncpy(employee.gender, "Male", strlen("Male") + 1);

    employee.age = 25;

    employee.salary = 90000;

    employee.position = (char*)malloc(strlen("Developer") + 1);
    strncpy(employee.position, "Developer", strlen("Developer") + 1);

    employee.experience = 2;

    add_element(employee_arr, &employee);

    EXPECT_EQ(get_sum(employee_arr, 0, 1), 80000);

    free_employee_arr(employee_arr);
}

TEST(GET_SUM_TEST, big_start)
{
    EmployeeArr* employee_arr = create_employee_arr();

    Employee employee;

    employee.name = (char*)malloc(strlen("Olga") + 1);
    strncpy(employee.name, "Olga", strlen("Olga") + 1);

    employee.surname = (char*)malloc(strlen("Voronova") + 1);
    strncpy(employee.surname, "Voronova", strlen("Voronova") + 1);

    employee.gender = (char*)malloc(strlen("Female") + 1);
    strncpy(employee.gender, "Female", strlen("Female") + 1);

    employee.age = 20;

    employee.salary = 80000;

    employee.position = (char*)malloc(strlen("Developer") + 1);
    strncpy(employee.position, "Developer", strlen("Developer") + 1);

    employee.experience = 1;

    add_element(employee_arr, &employee);

    employee.name = (char*)malloc(strlen("O") + 1);
    strncpy(employee.name, "O", strlen("O") + 1);

    employee.surname = (char*)malloc(strlen("V") + 1);
    strncpy(employee.surname, "V", strlen("V") + 1);

    employee.gender = (char*)malloc(strlen("Female") + 1);
    strncpy(employee.gender, "Male", strlen("Male") + 1);

    employee.age = 25;

    employee.salary = 90000;

    employee.position = (char*)malloc(strlen("Developer") + 1);
    strncpy(employee.position, "Developer", strlen("Developer") + 1);

    employee.experience = 2;

    add_element(employee_arr, &employee);

    EXPECT_EQ(get_sum(employee_arr, 10, 1), -2);

    free_employee_arr(employee_arr);
}
