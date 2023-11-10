#include "s21_math.h"

long double s21_exp(double x) {
  if (s21_isnan(x)) return s21_nan;
  if (s21_isinf(x)) return x < 0 ? 0 : s21_inf;
  int num = x < 0;
  if (num) x = -x;
  long double result = 1, temp = x;
  unsigned n = 1;
  while (s21_fabs(temp) >= s21_EPS && result != s21_inf) {
    result += temp;
    temp = (temp * x) / ++n;
    if (result > s21_DBL_MAX) {
      result = s21_inf;
    }
  }
  return num ? (1 / result) : result;
}