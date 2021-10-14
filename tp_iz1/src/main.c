#include "geometry.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    struct Triangle triangle;
    struct Circle circle;
    struct Square square;


    if (argc > 1) {
        triangle.a = strtod(argv[1], NULL);
        triangle.b = strtod(argv[2], NULL);
        triangle.c = strtod(argv[3], NULL);
        circle.radius = find_circle_radius(&triangle);
    } else {
        if (read_triangle_sides(&triangle)) {
            return 1;
        }
        circle.radius = find_circle_radius(&triangle);
    }

    square.side = find_square_side(circle.radius);

    if (!printf("%f\n", square.side)) {
        return 1;
    }
    return 0;
}
