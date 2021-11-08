#include "gtest/gtest.h"

extern "C" {
#include "list_position_experience.h"
}

TEST(MAKE_REPORT_TEST, null_node)
{
    Node* list_position_experience = nullptr;

    EXPECT_EQ(make_report(list_position_experience), 1);
}

TEST(MAKE_REPORT_TEST, full_node)
{
    Node* list_position_experience;

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

    list_position_experience = create_node(employee.position, employee.experience);
    add_element(list_position_experience->employeeArr, &employee);

    EXPECT_EQ(make_report(list_position_experience), 0);

    free_node(&list_position_experience);
}
