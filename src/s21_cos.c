#include "s21_math.h"

long double s21_cos(double x) {
  long double rez = 0;
  if (s21_isnan(x) || s21_isinf(x)) return s21_nan;
  if ((x >= -s21_pi && x <= s21_pi)) {
    rez = s21_sin((s21_pi / 2) - x);
    // позволяет вычислить значение синуса для аргумента
    // затем применить формулу cos(x) = sin(pi/2 - x)
  } else {
    x = s21_mod(x);
    // используется для приведения аргумента функции x к диапазону от 0 до 2π,
    // если значение x выходит за пределы этого диапазона
    rez = s21_cos(x);
  }
  return rez;
}
