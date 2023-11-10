#ifndef S21_MATH_H
#define S21_MATH_H

#include <float.h>
#include <limits.h>
#include <stdio.h>
#define s21_EPS 1e-06
#define s21_pi 3.141592653589793238462643383279502884197169399375105820974944
#define s21_nan __builtin_nanf("0x7fc00000")
#define s21_inf __builtin_huge_valf()
#define s21_MAX 10000
#define s21_DBL_MAX 1.7976931348623157e+308
#define S21_DBL_MIN 2.22507e-308L
#define S21_n 2.7182818284590452353602874
#define s21_pi_2 1.57079632679489661923132169163975144        // pi/2
#define s21_pi_4 0.785398163397448309615660845819875721       // pi/4
#define S21_M_SQRT1_2 0.707106781186547524400844362104849039  // 1/sqrt(2)

#define s21_isinf(x)                                            \
  (sizeof(x) == sizeof(float)    ? __builtin_isinff((float)(x)) \
   : sizeof(x) == sizeof(double) ? __builtin_isinf((double)(x)) \
                                 : __builtin_isinfl((long double)(x)))

#define s21_isnan(x)                                            \
  (sizeof(x) == sizeof(float)    ? __builtin_isnanf((float)(x)) \
   : sizeof(x) == sizeof(double) ? __builtin_isnan((double)(x)) \
                                 : __builtin_isnanl((long double)(x)))

int s21_abs(int x);
long double s21_atan(double x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_ceil(long double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_mod(double x);  // вспомогательная функция
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_pow_2(double a, int b);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif
