#include "s21_math.h"

//	вычисляет синус
long double s21_sin(double x) {
  long double y = 0;
  long double rez = x;
  long double i = 1.0;
  int sing = 1;  // знак первого члена ряда
  if (s21_isnan(x) || s21_isinf(x)) return s21_nan;
  while (s21_fabs(rez) > s21_EPS) {
    if ((x >= -s21_pi && x <= s21_pi)) {  // интервал радиан
      y += sing * rez;
      sing *= -1;  // меняем знак при каждой итерации
      rez = rez * x * x / (2 * i * (2 * i + 1));  // ряд Тейлора
      i = i + 1;  // хранитромер текущего члена ряда
    } else {
      x = s21_mod(x);
      rez = x;
    }
  }
  return y;
}
