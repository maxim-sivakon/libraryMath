#include <check.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "s21_math.h"
double temp = 1;

START_TEST(s21_sqrtTEST) {
  ck_assert_ldouble_nan(s21_sqrt(-2));
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(-0), sqrt(-0), s21_EPS);
  ck_assert_ldouble_infinite(s21_sqrt(-s21_inf));
  ck_assert_ldouble_infinite(s21_sqrt(s21_inf));
  ck_assert_ldouble_nan(s21_sqrt(s21_nan));
  ck_assert_ldouble_eq_tol(s21_sqrt(s21_pi), sqrt(s21_pi), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(123456), sqrt(123456), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(123456789), sqrt(123456789), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(126.8647465), sqrt(126.8647465), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(75846.8647465), sqrt(75846.8647465),
                           s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(1e20), sqrt(1e20), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(35), sqrt(35), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(2), sqrt(2), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(4), sqrt(4), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(9), sqrt(9), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(16), sqrt(16), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(25), sqrt(25), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(100), sqrt(100), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(10000), sqrt(10000), s21_EPS);
}
END_TEST

START_TEST(s21_absTEST) {
  ck_assert_int_eq(s21_abs(5), abs(5));
  ck_assert_int_eq(s21_abs(-5), abs(-5));
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(2147483647), abs(2147483647));
}
END_TEST

START_TEST(s21_fabsTEST) {
  ck_assert_ldouble_eq_tol(s21_fabs(0.), fabs(0.), s21_EPS);
  ck_assert_ldouble_nan(s21_fabs(s21_nan));
  ck_assert_ldouble_eq_tol(s21_fabs(5.), fabs(5.), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_fabs(3.2), fabs(3.2), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_fabs(-3.2), fabs(-3.2), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_fabs(75846.8647465), fabs(75846.8647465),
                           s21_EPS);
  ck_assert_ldouble_eq_tol(s21_fabs(-126.8647465), fabs(-126.8647465), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_fabs(s21_pi), fabs(s21_pi), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_fabs(s21_DBL_MAX), fabs(s21_DBL_MAX), s21_EPS);
}
END_TEST

START_TEST(s21_expTEST) {
  ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(1.2598), exp(1.2598), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(-3.256), exp(-3.256), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(s21_pi), exp(s21_pi), s21_EPS);
  ck_assert_ldouble_nan(s21_exp(s21_nan));
  ck_assert_ldouble_eq_tol(s21_exp(-s21_inf), exp(-s21_inf), s21_EPS);
}
END_TEST

START_TEST(s21_cosTEST) {
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(1.2598), cos(1.2598), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(-3.256), cos(-3.256), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(126.8647465), cos(126.8647465), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(-126.8647465), cos(-126.8647465), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), s21_EPS);
  // ck_assert_ldouble_infinite(s21_cos(-s21_inf));
  // ck_assert_ldouble_infinite(s21_cos(s21_inf));
  ck_assert_ldouble_nan(s21_cos(s21_nan));
  ck_assert_ldouble_eq_tol(s21_cos(s21_MAX), cos(s21_MAX), s21_EPS);
}
END_TEST
START_TEST(s21_sinTEST) {
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(1.2598), sin(1.2598), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(-3.256), sin(-3.256), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(126.8647465), sin(126.8647465), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(-126.8647465), sin(-126.8647465), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), s21_EPS);
  // ck_assert_ldouble_infinite(s21_sin(-s21_inf));
  // ck_assert_ldouble_infinite(s21_sin(s21_inf));
  ck_assert_ldouble_nan(s21_sin(s21_nan));
  ck_assert_ldouble_eq_tol(s21_sin(s21_MAX), sin(s21_MAX), s21_EPS);
}
END_TEST

START_TEST(s21_floorTEST) {
  ck_assert_ldouble_eq_tol(s21_floor(1.2598), floor(1.2598), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_floor(-3.256), floor(-3.256), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_floor(126.8647465), floor(126.8647465), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_floor(-126.8647465), floor(-126.8647465),
                           s21_EPS);
  ck_assert_ldouble_infinite(s21_floor(-s21_inf));
  ck_assert_ldouble_infinite(s21_floor(s21_inf));
  ck_assert_ldouble_eq_tol(s21_floor(0), floor(0), s21_EPS);
}
END_TEST

START_TEST(s21_powTEST) {
  ck_assert_ldouble_eq_tol(s21_pow(1, 1), pow(1, 1), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(0.000, 1), pow(0.000, 1), s21_EPS);
  // ck_assert_ldouble_nan(s21_pow(1, 0.000));
  // ck_assert_ldouble_nan(s21_pow(0.000, 0.000));
  ck_assert_ldouble_eq_tol(s21_pow(0, 24), pow(0, 24), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(0, 35), pow(0, 35), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(-0, 24), pow(-0, 24), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(-0, 35), pow(-0, 35), s21_EPS);
  // ck_assert_ldouble_infinite(s21_pow(0, -35));
  // ck_assert_ldouble_nan(s21_pow(3213.321, 0));
  // ck_assert_ldouble_nan(s21_pow(-333, 32.2));
  // ck_assert_ldouble_infinite(s21_pow(s21_inf, 0));
}
END_TEST

START_TEST(s21_ceilTEST) {
  ck_assert_ldouble_eq_tol(s21_ceil(1.2598), ceil(1.2598), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_ceil(-3.256), ceil(-3.256), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_ceil(126.8647465), ceil(126.8647465), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_ceil(-126.8647465), ceil(-126.8647465), s21_EPS);
  ck_assert_ldouble_infinite(s21_ceil(-s21_inf));
  ck_assert_ldouble_infinite(s21_ceil(s21_inf));
  ck_assert_ldouble_eq_tol(s21_ceil(0), floor(0), s21_EPS);
}
END_TEST

START_TEST(s21_fmodTEST) {
  ck_assert_ldouble_eq_tol(s21_fmod(0.1111111, -0.1111111),
                           fmod(0.1111111, -0.1111111), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(111112343444, 1555555543333),
                           fmod(111112343444, 1555555543333), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(0.000, 1), fmod(0.000, 1), s21_EPS);
  ck_assert_ldouble_nan(s21_fmod(1, 0.000));
  ck_assert_ldouble_nan(s21_fmod(0.000, 0.000));
  ck_assert_ldouble_eq_tol(s21_fmod(-0, 24), fmod(-0, 24), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(0, 198.2888888888), fmod(0, 198.2888888888),
                           s21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(-0, 24), fmod(-0, 24), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(0, s21_inf), fmod(0, s21_inf), s21_EPS);
  ck_assert_ldouble_nan(s21_fmod(3213.321, 0));
  ck_assert_ldouble_nan(s21_fmod(-0, s21_nan));
  ck_assert_ldouble_nan(s21_fmod(s21_nan, 0));
  ck_assert_ldouble_eq_tol(s21_fmod(-333, 32.2), fmod(-333, 32.2), s21_EPS);
  ck_assert_ldouble_nan(s21_fmod(s21_inf, 0));
  ck_assert_ldouble_eq_tol(s21_fmod(0, s21_inf), fmod(0, s21_inf), s21_EPS);
}
END_TEST

START_TEST(s21_tanTEST) {
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(1.2598), tan(1.2598), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(-3.2564444), tan(-3.2564444), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(126.8647465), tan(126.8647465), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(0), sin(0), s21_EPS);
  // ck_assert_ldouble_infinite(s21_tan(-s21_inf));
  // ck_assert_ldouble_infinite(s21_tan(s21_inf));
  ck_assert_ldouble_nan(s21_tan(s21_nan));
  ck_assert_ldouble_eq_tol(s21_tan(s21_MAX), tan(s21_MAX), s21_EPS);
}
END_TEST

START_TEST(s21_atanTEST) {
  ck_assert_ldouble_eq_tol(s21_atan(s21_pi), atan(s21_pi), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(-1.2), atan(-1.2), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(99999999), atan(99999999), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(-1.111111), atan(-1.111111), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(-3.256454), atan(-3.256454), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(-0.8647465), atan(-0.8647465), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(12345678.123456), atan(12345678.123456),
                           s21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(-12345678.123456), atan(-12345678.123456),
                           s21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(-s21_inf), atan(-s21_inf), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(s21_inf), atan(s21_inf), s21_EPS);
  ck_assert_ldouble_nan(s21_atan(s21_nan));
}
END_TEST

START_TEST(s21_acosTEST) {
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(0.2598), acos(0.2598), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(-0.8647465), acos(-0.8647465), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(0.8647465), acos(0.8647465), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), s21_EPS);
  ck_assert_ldouble_nan(s21_acos(126.8647465));
  ck_assert_ldouble_nan(s21_acos(4));
  ck_assert_ldouble_infinite(s21_acos(-s21_inf));
  ck_assert_ldouble_infinite(s21_acos(s21_inf));
  ck_assert_ldouble_nan(s21_acos(s21_nan));
}
END_TEST

START_TEST(s21_asinTEST) {
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(-0.8647465), asin(-0.8647465), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(0.8647465), asin(0.8647465), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), s21_EPS);
  ck_assert_ldouble_nan(s21_asin(42352));
  ck_assert_ldouble_nan(s21_asin(4));
  ck_assert_ldouble_nan(s21_asin(99999999));
  ck_assert_ldouble_infinite(s21_asin(-s21_inf));
  ck_assert_ldouble_infinite(s21_asin(s21_inf));
  ck_assert_ldouble_nan(s21_asin(s21_nan));
}
END_TEST

START_TEST(s21_logTEST) {
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_log(0.8647465), log(0.8647465), s21_EPS);
  ck_assert_ldouble_eq_tol(log(2.523), s21_log(2.523), s21_EPS);
  ck_assert_ldouble_nan(s21_log(-3432.12));
  ck_assert_ldouble_infinite(s21_log(0));
  ck_assert_ldouble_eq_tol(log(1), s21_log(1), s21_EPS);
  ck_assert_ldouble_nan(s21_log(-s21_inf));
  ck_assert_ldouble_infinite(s21_log(s21_inf));
}
END_TEST

int main(void) {
  Suite* suite = suite_create("S21_KEK");
  SRunner* srunner = srunner_create(suite);

  TCase* s21_sqrt_p = tcase_create("s21_sqrt");
  suite_add_tcase(suite, s21_sqrt_p);
  tcase_add_test(s21_sqrt_p, s21_sqrtTEST);

  TCase* s21_abs_p = tcase_create("s21_abs");
  suite_add_tcase(suite, s21_abs_p);
  tcase_add_test(s21_abs_p, s21_absTEST);

  TCase* s21_fabs_p = tcase_create("s21_fabs");
  suite_add_tcase(suite, s21_fabs_p);
  tcase_add_test(s21_fabs_p, s21_fabsTEST);

  TCase* s21_exp_p = tcase_create("s21_exp");
  suite_add_tcase(suite, s21_exp_p);
  tcase_add_test(s21_exp_p, s21_expTEST);

  TCase* s21_cos_p = tcase_create("s21_cos");
  suite_add_tcase(suite, s21_cos_p);
  tcase_add_test(s21_cos_p, s21_cosTEST);

  TCase* s21_sin_p = tcase_create("s21_sin");
  suite_add_tcase(suite, s21_sin_p);
  tcase_add_test(s21_sin_p, s21_sinTEST);

  TCase* s21_floor_p = tcase_create("s21_floor");
  suite_add_tcase(suite, s21_floor_p);
  tcase_add_test(s21_floor_p, s21_floorTEST);

  TCase* s21_pow_p = tcase_create("s21_pow");
  suite_add_tcase(suite, s21_pow_p);
  tcase_add_test(s21_pow_p, s21_powTEST);

  TCase* s21_ceil_p = tcase_create("s21_ceil");
  suite_add_tcase(suite, s21_ceil_p);
  tcase_add_test(s21_ceil_p, s21_ceilTEST);

  TCase* s21_fmod_p = tcase_create("s21_fmod");
  suite_add_tcase(suite, s21_fmod_p);
  tcase_add_test(s21_fmod_p, s21_fmodTEST);

  TCase* s21_tan_p = tcase_create("s21_tan");
  suite_add_tcase(suite, s21_tan_p);
  tcase_add_test(s21_tan_p, s21_tanTEST);

  TCase* s21_atan_p = tcase_create("s21_atan");
  suite_add_tcase(suite, s21_atan_p);
  tcase_add_test(s21_atan_p, s21_atanTEST);

  TCase* s21_acos_p = tcase_create("s21_acos");
  suite_add_tcase(suite, s21_acos_p);
  tcase_add_test(s21_acos_p, s21_acosTEST);

  TCase* s21_asin_p = tcase_create("s21_asin");
  suite_add_tcase(suite, s21_asin_p);
  tcase_add_test(s21_asin_p, s21_asinTEST);

  TCase* s21_log_p = tcase_create("s21_log");
  suite_add_tcase(suite, s21_log_p);
  tcase_add_test(s21_log_p, s21_logTEST);

  srunner_run_all(srunner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
