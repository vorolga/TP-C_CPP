#include "list_position_experience.h"
#include <stdlib.h>
#include <string.h>

char* experience_interval(const short experience)
{
    if (experience < 1) {
        return "<1";
    }

    if (experience <= 2) {
        return "1-2";
    }

    if (experience <= 5) {
        return "3-5";
    }

    if (experience <= 10) {
        return "6-10";
    }

    if (experience <= 20) {
        return "11-20";
    }

    return ">20";
}

Node* create_node(const char* position, const short experience)
{
    if (!position) {
        return NULL;
    }

    Node* head = (Node*)malloc(sizeof(Node));
    if (!head) {
        return NULL;
    }

    head->next = NULL;

    head->position = (char*)malloc((strlen(position) + 1) * sizeof(char));
    if (!head->position) {
        free(head);
        return NULL;
    }
    strncpy(head->position, position, strlen(position) + 1);

    head->experience = (char*)malloc((strlen(experience_interval(experience)) + 1) * sizeof(char));
    if (!head->experience) {
        free(head->position);
        free(head);
        return NULL;
    }
    strncpy(head->experience, experience_interval(experience), strlen(experience_interval(experience)) + 1);

    head->employeeArr = create_employee_arr();

    return head;
}

int read_from_file(FILE* file, Node** head)
{
    if (!file || !head) {
        return 1;
    }

    while (1) {
        Employee employee;
        if (read_employee_from_file(file, &employee) == 1) {
            if (feof(file)) {
                break;
            }
            return 1;
        }
        if (!(*head)) {
            *head = create_node(employee.position, employee.experience);
            add_element((*head)->employeeArr, &employee);
        } else {
            Node* node = find_node(*head, employee.position, employee.experience);
            if (!node) {
                if (add_node(head, employee.position, employee.experience)) {
                    return 1;
                }
                add_element((*head)->employeeArr, &employee);
            } else {
                add_element(node->employeeArr, &employee);
            }
        }
    }
    return 0;
}

int add_node(Node** head, const char* position, short experience)
{
    if (!(*head) || !position) {
        return 1;
    }

    Node* tmp = (Node*)malloc(sizeof(Node));
    if (!tmp) {
        return 1;
    }

    tmp->next = *head;
    tmp->position = (char*)malloc(sizeof(char) * (strlen(position) + 1));
    if (!tmp->position) {
        free(tmp);
        return 1;
    }
    strncpy(tmp->position, position, strlen(position) + 1);

    tmp->experience = (char*)malloc(sizeof(char) * (strlen(experience_interval(experience)) + 1));
    if (!tmp->experience) {
        free(tmp->position);
        free(tmp);
        return 1;
    }
    strncpy(tmp->experience, experience_interval(experience), strlen(experience_interval(experience)) + 1);

    tmp->employeeArr = create_employee_arr();
    if (!tmp->employeeArr) {
        free(tmp->position);
        free(tmp->experience);
        free(tmp);
        return 1;
    }

    *head = tmp;

    return 0;
}

Node* find_node(const Node* head, const char* position, short experience)
{
    if (!head || !position) {
        return NULL;
    }

    Node* find_need_node = (Node*)head;

    while (find_need_node) {
        if (strncmp(find_need_node->position, position, strlen(position)) == 0
            && strncmp(find_need_node->experience, experience_interval(experience), strlen(experience_interval(experience))) == 0) {
            return find_need_node;
        }
        find_need_node = find_need_node->next;
    }

    return NULL;
}

int free_node(Node** head)
{
    if (!head) {
        return 1;
    }

    Node* tmp = NULL;

    while (*head) {
        tmp = (*head);
        *head = (*head)->next;
        free(tmp->position);
        free(tmp->experience);
        free_employee_arr(tmp->employeeArr);
        free(tmp);
    }

    return 0;
}
