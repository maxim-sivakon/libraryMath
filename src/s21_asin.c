#include "s21_math.h"

long double s21_asin(double x) {
  if (s21_isinf(x)) return s21_inf;
  if (s21_isnan(x)) return s21_nan;
  return (x < -1 || x > 1) ? s21_nan : s21_atan(x / s21_sqrt(1 - x * x));
}
