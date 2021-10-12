#include "../include/geometry.h"
#include <math.h>

void read_triangle_sides(struct Triangle* triangle) {
    printf("Введите стороны треугольника\n");
    if (scanf("%lf", &triangle->a) != 1) {
        return 1;
    }
    if (scanf("%lf", &triangle->b) != 1) {
        return 1;
    }
    if (scanf("%lf", &triangle->c) != 1) {
        return 1;
    }

    if (triangle->a + triangle->b <= triangle->c || triangle->a + triangle->c <= triangle->b || triangle->c + triangle->b <= triangle->a) {
        printf("Такого треугольника не существует\n");
        return 1;
    }
}

double find_circle_radius(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    double triangle_square = sqrt(p * (p - a) * (p - b) * (p - c));
    return a * b * c / (4 * triangle_square);
}

// double find_square_side(double radius) {
//    return 2 * radius;
//}