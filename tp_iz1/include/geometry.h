#ifndef TP_IZ1_GEOMETRY_H
#define TP_IZ1_GEOMETRY_H

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

double find_circle_radius(double, double, double);

// double find_square_side(double);

#endif // TP_IZ1_GEOMETRY_H
