#include "s21_math.h"
// поиск тангенса через отношения косинуса к синусу
long double s21_tan(double x) {
  long double rez = 0.;

  if (s21_isnan(x) || s21_isinf(x)) return s21_nan;
  if (x != 0) {
    rez = s21_sin(x) / s21_cos(x);
  }
  return rez;
}
