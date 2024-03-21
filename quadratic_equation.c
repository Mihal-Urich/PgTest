#include "quadratic_equation.h"

void swap_roots(struct EquationAnswer *roots) {
  double tmp = 0;
  tmp = roots->x1.re;
  roots->x1.re = roots->x2.re;
  roots->x2.re = tmp;
  tmp = roots->x1.im;
  roots->x1.im = roots->x2.im;
  roots->x2.im = tmp;
}

struct EquationAnswer solve_equation(double a, double b, double c) {
  const double EPSILON = 1e-7;
  struct EquationAnswer answer = {{0, 0}, {0, 0}, REAL_ROOTS};

  if ((fabs(a) < EPSILON) && (fabs(b) > EPSILON) && (fabs(c) > EPSILON)) {
    answer.x1.re = answer.x2.re = -(c / b);
    answer.possible_answer = ONE_REAL_ROOT;
    return answer;
  }
  if ((fabs(a) < EPSILON) && (fabs(b) < EPSILON) && (fabs(c) > EPSILON)) {
    answer.possible_answer = NO_ROOTS;
    return answer;
  }
  if (((fabs(a) < EPSILON) && (fabs(b) > EPSILON) && (fabs(c) < EPSILON)) ||
      ((fabs(a) > EPSILON) && (fabs(b) < EPSILON) && (fabs(c) < EPSILON))) {
    answer.possible_answer = ONE_REAL_ROOT;
    return answer;
  }
  if ((fabs(a) < EPSILON) && (fabs(b) < EPSILON) && (fabs(c) < EPSILON)) {
    answer.possible_answer = ALWAYS_TRUE;
    return answer;
  }

  double discriminant = pow(b, 2.0) - (4 * a * c);
  if (fabs(discriminant) < EPSILON) {
    answer.x1.re = answer.x2.re = (-b) / (2 * a);
    answer.possible_answer = ONE_REAL_ROOT;
  } else if (discriminant > EPSILON) {
    answer.x1.re = ((-b) + sqrt(discriminant)) / (2 * a);
    answer.x2.re = ((-b) - sqrt(discriminant)) / (2 * a);
  } else {
    answer.x1.re = (-b) / (2 * a);
    answer.x2.re = (-b) / (2 * a);
    answer.x1.im = sqrt(fabs(discriminant)) / (2 * a);
    answer.x2.im = -sqrt(fabs(discriminant)) / (2 * a);
    answer.possible_answer = COMPLEX_ROOTS;
  }

  // ensures that the roots are in ascending order
  if (answer.x1.re > answer.x2.re) {
    swap_roots(&answer);
  } else if ((answer.x1.re == answer.x2.re) && (answer.x1.im > answer.x2.im)) {
    swap_roots(&answer);
  }
  return answer;
}
