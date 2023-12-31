#include "s21_math.h"

// вспомогателльная функция( "сворачивает" значение x в пределах диапазона (-pi,
// pi])
long double s21_mod(double x) {
  if (x > s21_pi) {
    x -= 2 * s21_pi;
    // значение x уменьшается на 2πбчтобы x оказался в диапазоне от -π до π
  } else if (x < s21_pi) {
    x += 2 * s21_pi;
  }
  // значение x увеличивается на 2π, чтобы x оказался в том же диапазоне
  return x;
}
