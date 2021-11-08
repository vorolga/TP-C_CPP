#include "main_func.h"

int main()
{
    Node* list_position_experience = NULL;
    char filename[30] = "../employee10000.dat";
    if (read_file(&list_position_experience, filename)) {
        return 1;
    }
    while (1) {
        printf("\nChoose action:\n");
        printf("1. Add employee\n");
        printf("2. Print report\n");
        printf("3. Exit\n\n");
        int action;
        scanf("%d", &action);
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
