#include "list_position_experience.h"

int make_report(const Node* head)
{
    if (!head) {
        return 1;
    }

    Node* node = (Node*)head;

    while (node) {
        printf("Position: %-10s   Experience: %-10s   ", node->position, node->experience);
        average_salary(node->employeeArr);
        node = node->next;
    }
    return 0;
}
