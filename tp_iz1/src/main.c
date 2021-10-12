#include "../include/geometry.h"

int main()
{
    struct Triangle triangle;
    struct Circle circle;
    struct Square square;

    read_triangle_sides(&triangle);

    circle.radius = find_circle_radius(triangle.a, triangle.b, triangle.c);

    // square.side = find_square_side(circle.radius);
    square.side = 2 * circle.radius;

    printf("%f\n", square.side);
    return 0;
}
