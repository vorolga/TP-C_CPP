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
    char* files[3][30] = {{"../employee10000.dat"},  {"../employee12.dat"}, {"../employee200.dat"}};

    for (size_t i = 0; i < 3; ++i) {
        double start = perf_counter();

        if (read_file(&list_position_experience, *files[i])) {
            return 1;
        }

        if (make_report(list_position_experience)) {
            return 1;
        }

        if (free_node(&list_position_experience)) {
            return 1;
        }

        printf("\nmake report: in %.2f seconds\n\n\n", perf_counter() - start);
    }

    return 0;
}
