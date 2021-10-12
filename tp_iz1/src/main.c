#include "../include/geometry.h"

int main(int argc, char* argv[])
{
    struct Triangle triangle;
    struct Circle circle;
    struct Square square;


    if (argc > 1) {
        int* f= (int*)malloc(5*sizeof(int));
        triangle.a = strtod(argv[1], NULL);
        triangle.b = strtod(argv[2], NULL);
        triangle.c = strtod(argv[3], NULL);
        circle.radius = find_circle_radius(triangle.a, triangle.b, triangle.c);
    } else {
        read_triangle_sides(&triangle);
        circle.radius = find_circle_radius(triangle.a, triangle.b, triangle.c);
    }

    // square.side = find_square_side(circle.radius);
    square.side = 2 * circle.radius;

    printf("%f\n", square.side);
    return 0;
}
