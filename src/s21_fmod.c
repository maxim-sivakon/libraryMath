#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res;
  if (x == s21_nan || x == s21_inf || x == -s21_inf || x != x || y == 0)
    res = s21_nan;
  else if (y == s21_inf || y == -s21_inf)
    res = x;
  else {
    long long int quot = 0;
    quot = (x * 1e+16) / (y * 1e+16);
    res = (long double)x - quot * (long double)y;
  }
  return res;
}