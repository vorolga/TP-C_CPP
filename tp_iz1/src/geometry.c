#include "geometry.h"

int read_triangle_sides(struct Triangle* triangle) {
    if (triangle == NULL) {
        printf("Нулевой указатель\n");
        return 1;
    }

    printf("Введите стороны треугольника\n");
    if (scanf("%lf", &triangle->a) != 1 || scanf("%lf", &triangle->b) != 1 || scanf("%lf", &triangle->c) != 1) {
        return 1;
    }

    //Проверка существования треугольника
    if (triangle->a + triangle->b <= triangle->c && triangle->a + triangle->c <= triangle->b && triangle->c + triangle->b <= triangle->a){
        printf("Такого треугольника не существует\n");
        return 1;
    }

    return  0;
}

double find_circle_radius(double a, double b, double c)
{
    double p = (a + b + c) / 2; //полупериметр
    double triangle_square = sqrt(p * (p - a) * (p - b) * (p - c));
    return a * b * c / (4 * triangle_square);
}

 double find_square_side(double radius) {
    return 2 * radius;
}