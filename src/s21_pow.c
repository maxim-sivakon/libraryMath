#include "s21_math.h"

// long double s21_pow(double base, double exp) {
//   long double res = 0;

//   res = s21_exp(exp * s21_log(base));
//   return res;
// }

long double s21_pow(double x, double y) {
  long double result = 0;
  if (x < 0 && (int)y != y) {
    result = s21_nan;
  } else if (x == 1 || y == 0) {
    result = 1;
  } else if (y != y) {
    result = s21_nan;
  } else {
    if (y < 0) {
      result = 1.0 / s21_pow(x, (-1) * y);
    } else if ((int)y == y) {
      result = s21_pow_2(x, (int)y);
    } else {
      result = s21_exp(y * s21_log(x));
    }
  }
  return result;
}

long double s21_pow_2(double a, int b) {
  long double res = 1;
  for (int i = 0; i < b; i++) res = res * a;
  return res;
}