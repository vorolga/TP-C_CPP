#ifndef TP_IZ1_GEOMETRY_H
#define TP_IZ1_GEOMETRY_H

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Circle {
    double radius;
};

struct Triangle {
    double a;
    double b;
    double c;
};

struct Square {
    double side;
};

int read_triangle_sides(struct Triangle*);

double find_circle_radius(double, double, double);

double find_square_side(double);

#endif // TP_IZ1_GEOMETRY_H
