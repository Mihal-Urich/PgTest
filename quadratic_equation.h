#ifndef QUADRATIC_EQUATION_H_
#define QUADRATIC_EQUATION_H_

#include <math.h>

enum ResponseStatus {
  REAL_ROOTS,
  COMPLEX_ROOTS,
  ALWAYS_TRUE,
  NO_ROOTS,
  ONE_REAL_ROOT
};

struct ComplexNumber {
  double re;
  double im;
};

struct EquationAnswer {
  struct ComplexNumber x1;
  struct ComplexNumber x2;
  enum ResponseStatus possible_answer;
};

void SwapRoots(struct EquationAnswer *roots);
struct EquationAnswer solve_equation(double a, double b, double c);

#endif  // QUADRATIC_EQUATION_H_