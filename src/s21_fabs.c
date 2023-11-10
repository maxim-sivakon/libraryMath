#include "s21_math.h"

// вычисляет абсолютное значение числа с плавающей точкой
long double s21_fabs(double x) {
  if (x < 0) x *= -1.0L;
  return x;
}
