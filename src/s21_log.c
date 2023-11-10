#include "s21_math.h"

long double s21_log(double x) {
  long double result = 0;

  if (x < 0 || x == -s21_inf || s21_isnan(x)) {
    result = s21_nan;
  } else if (x == 0) {
    result = -s21_inf;
  } else if (x == s21_inf) {
    result = s21_inf;
  } else if (x == 1) {
    result = 0;
  } else {
    double N = 0.0, P = x, A = 0;
    while (P >= S21_n) {
      P /= S21_n;
      N++;
    }
    N += (P / S21_n);
    P = x;
    int j = 0;
    do {
      double L, R;
      A = N;
      L = (P / (s21_exp(N - 1.0)));
      R = ((N - 1.0) * S21_n);
      N = ((L + R) / S21_n);
      j++;
    } while (N != A && j < s21_MAX);
    result = N;
  }

  return result;
}
