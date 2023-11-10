#include "s21_math.h"

// возвращает ближайшее целое число, не превышающее заданное значение
long double s21_floor(double x) {
  long long int rez = (long long int)x;
  // целочисленному типу long long int, что позволяет получить целую часть числа
  // x
  if (s21_isinf(x)) return s21_inf;
  if (s21_isnan(x)) return s21_nan;
  if (x < rez) {
    rez = (long double)rez - 1.0L;  // В данном коде 1.0L обозначает число с
                                    // плавающей точкой двойной точности
  } else {
    return rez;
  }
  return rez;
}
