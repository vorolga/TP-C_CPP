#include "gtest/gtest.h"

extern "C" {
#include "main_func.h"
}

TEST(ADD_EMPLOYEE_TEST, wrong_node)
{
    char filename[30] = "../employee12.dat";
    Node** list_position_experience = NULL;

    EXPECT_EQ(add_employee(list_position_experience, filename), 1);
}


