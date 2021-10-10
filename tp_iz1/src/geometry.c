#include "../include/geometry.h"
#include <math.h>

double find_circle_radius(double a, double b, double c) {
    double p = (a + b + c) / 2;
    double triangle_square = sqrt(p * (p - a) * (p - b) * (p - c));
    return a * b * c / (4 * triangle_square);
}

//double find_square_side(double radius) {
//    return 2 * radius;
//}