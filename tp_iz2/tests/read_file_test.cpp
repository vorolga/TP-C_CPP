#include "gtest/gtest.h"

extern "C" {
#include "main_func.h"
}

TEST(READ_FILE_TEST, wrong_filename)
{
    char filename[30] = "file";
    Node* list_position_experience = NULL;

    EXPECT_EQ(read_file(&list_position_experience, filename), 1);
}

TEST(READ_FILE_TEST, correct_filename)
{
    char filename[30] = "../employee12.dat";
    Node* list_position_experience = NULL;

    EXPECT_EQ(read_file(&list_position_experience, filename), 0);

    if (list_position_experience) {
        free_node(&list_position_experience);
    }
}
