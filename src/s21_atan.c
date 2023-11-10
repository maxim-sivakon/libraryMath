#include "s21_math.h"

long double s21_atan(double x) {
  double ax = s21_fabs(x);  // arctan(-x) = -arctan(x)
  double a =
      (ax > 1.0) ? 1.0 / ax : ax;  // arctan(1/x) = pi/2 - arctan(x) if x > 0
  double k = 1;
  long double temp = 0, pred = 1;
  while (s21_fabs(pred - temp) > 1e-10) {
    pred = temp;
    temp += s21_pow(a, k) / k - s21_pow(a, k + 2) / (k + 2);
    k += 4;
  }
  temp = s21_fmod(temp, s21_pi);
  long double result = (ax > 1.0) ? (s21_pi_2 - temp) : temp;
  int sign = (x < 0) ? -1 : 1;
  return sign * result;
}
