#include "s21_math.h"
// вычисляет квадратный корень
long double s21_sqrt(double x) {
  long double upper = 0;
  if (s21_isinf(x)) {
    return s21_inf;
  }
  if (x > 0) {
    long double max_value = s21_DBL_MAX - 1;
    // уменьшенное на единицу, чтобы избежать переполнения.
    upper = max_value / 2;
    long double lower = 0;  // в качестве начального значения для поиска корня
    long double otvet = upper * upper;
    while (s21_fabs(otvet - x) > s21_EPS) {
      //(бинарный поиск)
      if (otvet > x) {
        max_value = upper;
        upper = ((max_value - lower) * 0.5L) + lower;
        // В первом случае (if (otvet > x)), новое значение upper выбирается
        // так, чтобы интервал поиска сужался влево, потому что квадрат текущего
        // значения upper больше x, и корень должен находиться в интервале
        // меньшем, чем текущий интервал.
      } else if (otvet < x) {
        lower = upper;
        upper = ((max_value - lower) * 0.5L) + lower;
        // Во втором случае (else if (otvet < x)), новое значение upper
        // выбирается так, чтобы интервал поиска сужался вправо, потому что
        // квадрат текущего значения upper меньше x, и корень должен находиться
        // в интервале большем, чем текущий интервал.
      } else
        break;
      otvet = upper * upper;
    }
  } else if (x == 0) {
    upper = 0;
  } else {
    upper = s21_nan;
  }
  return upper;
}
// в обоих случаях используется один и тот же код для вычисления нового значения
// верхней границы интервала upper. Да так надо, в этом состоит принцип
// бинарного поиска