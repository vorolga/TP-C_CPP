#include "main_func.h"
#include <stdlib.h>

int main(int argc, char* argv)
{
    int steps[2];
    if (argc > 1) {
        steps[0] = strtod(argv[1], NULL);
        steps[1] = strtod(argv[2], NULL);
        if (steps[1] != 3) {
            return 1;
        }
    }

    Node* list_position_experience = NULL;
    char filename[30] = "../employee10000.dat";
    if (read_file(&list_position_experience, filename)) {
        return 1;
    }

    size_t i = 0;
    while (1) {
        printf("\nChoose action:\n");
        printf("1. Add employee\n");
        printf("2. Print report\n");
        printf("3. Exit\n\n");
        int action;

        if (argc > 1) {
            action = steps[i];
        } else {
            scanf("%d", &action);
        }

        i++;
        switch (action) {
        case 1:
            if (add_employee(&list_position_experience, filename)) {
                return 1;
            }
            break;
        case 2:
            if (make_report(list_position_experience)) {
                return 1;
            }
            break;
        case 3:
            if (free_node(&list_position_experience)) {
                return 1;
            }
            return 0;

        default:
            break;
        }
    }
}
