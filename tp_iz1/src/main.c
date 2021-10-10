#include "../include/geometry.h"
#include <stdio.h>
int main() {
  struct Triangle triangle;
  struct Circle circle;
  struct Square square;

  printf("Введите стороны треугольника\n");
  if (scanf("%lf", &triangle.a) != 1) {
    return 1;
  }
  if (scanf("%lf", &triangle.b) != 1) {
    return 1;
  }
  if (scanf("%lf", &triangle.c) != 1) {
    return 1;
  }

  if (triangle.a + triangle.b <= triangle.c ||
      triangle.a + triangle.c <= triangle.b ||
      triangle.c + triangle.b <= triangle.a) {
    printf("Такого треугольника не существует\n");
    return 1;
  }

  circle.radius = find_circle_radius(triangle.a, triangle.b, triangle.c);

  // square.side = find_square_side(circle.radius);
  square.side = 2 * circle.radius;

  printf("%f\n", square.side);
  return 0;
}
