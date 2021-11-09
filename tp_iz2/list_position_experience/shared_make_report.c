#include "list_position_experience.h"
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define PROCNAME "shared-make-report"

static int get_sum_int(const int* arr, size_t size)
{
    if (!arr) {
        exit(EXIT_FAILURE);
    }
    int sum_salary = 0;
    for (size_t i = 0; i < size; i++) {
        sum_salary = sum_salary + arr[i];
    }

    return sum_salary;
}

int make_report(const Node* head)
{
    if (!head) {
        return 1;
    }

    Node* node = (Node*)head;

    const long number_of_processors = sysconf(_SC_NPROCESSORS_ONLN);

    if (number_of_processors == -1) {
        return 1;
    }

    pid_t pid[number_of_processors];

    int exit_status = EXIT_SUCCESS;

    while (node) {
        int fd[2];

        if (pipe(fd) < 0) {
            return 1;
        }

        for (size_t child = 0; child < number_of_processors; child++) {
            if ((pid[child] = fork()) < 0) {
                return 1;
            } else if (pid[child] == 0) {
                int sum = 0;
                close(fd[0]);

                size_t start = 0;
                size_t end = 0;
                if (child == number_of_processors - 1) {
                    start = node->employeeArr->real_size / number_of_processors * child;
                    end = node->employeeArr->real_size;
                } else {
                    start = node->employeeArr->real_size / number_of_processors * child;
                    end = node->employeeArr->real_size / number_of_processors * (child + 1);
                }


                sum += get_sum(node->employeeArr, start, end);

                for (ssize_t nwritten = 0; nwritten != sizeof(sum);) {
                    ssize_t n_bytes = write(fd[1], &sum + nwritten, sizeof(sum) - nwritten);
                    if (n_bytes != -1) {
                        nwritten += n_bytes;
                    } else if (errno != EINTR) {
                        _exit(EXIT_FAILURE);
                    }
                }
                close(fd[1]);
                _exit(EXIT_SUCCESS);
            }
        }

        close(fd[1]);

        FILE* fp = fdopen(fd[0], "rb");
        int sums[number_of_processors];
        if (fp && fread(sums, sizeof(*sums), number_of_processors, fp) == (size_t)number_of_processors) {
            double avg_salary = (double)get_sum_int(sums, number_of_processors) / (double)node->employeeArr->real_size;
            printf("Position: %-10s   Experience: %-10s   Average salary: %f\n", node->position, node->experience,
                avg_salary);
        } else {
            fputs(PROCNAME ": failed to read sums from children\n",
                stderr);
            exit_status = EXIT_FAILURE;
        }

        if (fp) {
            fclose(fp);
        }

        for (size_t child = 0; child < number_of_processors;) {
            int status = 0;
            if (waitpid(pid[child], &status, 0) == -1) {
                if (errno != EINTR) {
                    perror("waitpid");
                    exit_status = EXIT_FAILURE;
                } else {
                    continue;
                }
            } else if (WIFEXITED(status)) {
                int return_code = WEXITSTATUS(status);
                if (return_code != 0) {
                    fprintf(stderr, PROCNAME ": %d child returned non-zero status %d\n", pid[child], return_code);
                }
            } else if (WIFSIGNALED(status)) {
                fprintf(stderr, PROCNAME ": %d child killed by signal %d\n", pid[child], WTERMSIG(status));
            } else {
                fprintf(stderr, PROCNAME ": %d child returned unexpected status %d\n", pid[child], status);
            }
            ++child;
        }

        node = node->next;
    }

    return exit_status;
}
