#include "main_func.h"
#include <stdlib.h>
#include <time.h>

double perf_counter() {
    struct timespec tp;
    if (clock_gettime(CLOCK_MONOTONIC_RAW, &tp) < 0) {
        perror("clock_gettime");
        abort();
    }
    return tp.tv_sec + tp.tv_nsec * 1e-9;
}

int main()
{
    Node* list_position_experience = NULL;
    char filename[30] = "../employee10000.dat";

    double start = perf_counter();

    if (read_file(&list_position_experience, filename)) {
        return 1;
    }

    if (make_report(list_position_experience)) {
        return 1;
    }

    if (free_node(&list_position_experience)) {
        return 1;
    }

    printf("\nmake report: in %.2f seconds\n\n\n", perf_counter() - start);

    char filename1[30] = "../employee12.dat";

    start = perf_counter();

    if (read_file(&list_position_experience, filename1)) {
        return 1;
    }

    if (make_report(list_position_experience)) {
        return 1;
    }

    if (free_node(&list_position_experience)) {
        return 1;
    }

    printf("\nmake report: in %.2f seconds\n\n\n", perf_counter() - start);

    char filename2[30] = "../employee200.dat";

    start = perf_counter();

    if (read_file(&list_position_experience, filename2)) {
        return 1;
    }

    if (make_report(list_position_experience)) {
        return 1;
    }

    if (free_node(&list_position_experience)) {
        return 1;
    }

    printf("\nmake report: in %.2f seconds\n\n\n", perf_counter() - start);
    return 0;
}
