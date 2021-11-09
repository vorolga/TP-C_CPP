#ifndef TP_IZ2_LIST_POSITION_EXPERIENCE_H
#define TP_IZ2_LIST_POSITION_EXPERIENCE_H

#include "employee_arr.h"

typedef struct Node {
    struct Node* next;
    char* position;
    char* experience;
    EmployeeArr* employeeArr;
} Node;

Node* create_node(const char*, short);

int add_node(Node**, const char*, short);

int free_node(Node**);

int read_from_file(FILE*, Node**);

Node* find_node(const Node*, const char*, short);

int make_report(const Node*);

#endif //TP_IZ2_LIST_POSITION_EXPERIENCE_H
