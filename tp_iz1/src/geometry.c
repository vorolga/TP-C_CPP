#include "geometry.h"

void read_triangle_sides(struct Triangle* triangle) {
    printf("Введите стороны треугольника\n");
    assert(scanf("%lf", &triangle->a) == 1);
    assert(scanf("%lf", &triangle->b) == 1);
    assert(scanf("%lf", &triangle->c) == 1);

    //Проверка существования треугольника
    assert(triangle->a + triangle->b > triangle->c && triangle->a + triangle->c > triangle->b && triangle->c + triangle->b > triangle->a);
}

double find_circle_radius(double a, double b, double c)
{
    double p = (a + b + c) / 2; //полупериметр
    double triangle_square = sqrt(p * (p - a) * (p - b) * (p - c));
    return a * b * c / (4 * triangle_square);
}

// double find_square_side(double radius) {
//    return 2 * radius;
//}