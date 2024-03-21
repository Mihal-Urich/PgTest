#include <gtest/gtest.h>
#include <stdio.h>

#include "quadratic_equation.h"

const double EPSILON = 1e-7;

TEST(BasicCases, OnlyreNumbers1) {
  double args[3] = {4, 4, 1};
  struct EquationAnswer answer;
  answer.x1.re = -0.5;
  answer.x1.im = 0;
  answer.x2.re = -0.5;
  answer.x2.im = 0;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, ONE_REAL_ROOT);
}

TEST(BasicCases, OnlyreNumbers2) {
  double args[3] = {3, 7, -6};
  struct EquationAnswer answer;
  answer.x1.re = -3.0;
  answer.x1.im = 0;
  answer.x2.re = 0.6666667;
  answer.x2.im = 0;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, REAL_ROOTS);
}

TEST(BasicCases, OnlyreNumbers3) {
  double args[3] = {-1, 7, 8};
  struct EquationAnswer answer;
  answer.x1.re = -1.0;
  answer.x1.im = 0;
  answer.x2.re = 8.0;
  answer.x2.im = 0;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, REAL_ROOTS);
}

TEST(BasicCases, OnlyComplexNumbers1) {
  double args[3] = {2, 1, 1};
  struct EquationAnswer answer;
  answer.x1.re = -0.25;
  answer.x1.im = -0.6614379;
  answer.x2.re = -0.25;
  answer.x2.im = 0.6614379;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, COMPLEX_ROOTS);
}

TEST(BasicCases, OnlyComplexNumbers2) {
  double args[3] = {1, 2, 5};
  struct EquationAnswer answer;
  answer.x1.re = -1.0;
  answer.x1.im = -2.0;
  answer.x2.re = -1.0;
  answer.x2.im = 2.0;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, COMPLEX_ROOTS);
}

TEST(OneArgumentZero, Zero_a1) {
  double args[3] = {0, 3, 4};
  struct EquationAnswer answer;
  answer.x1.re = -1.3333333;
  answer.x1.im = 0.0;
  answer.x2.re = -1.3333333;
  answer.x2.im = 0.0;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, ONE_REAL_ROOT);
}

TEST(OneArgumentZero, Zero_a2) {
  double args[3] = {0, -13, 15};
  struct EquationAnswer answer;
  answer.x1.re = 1.1538461;
  answer.x1.im = 0.0;
  answer.x2.re = 1.1538461;
  answer.x2.im = 0.0;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, ONE_REAL_ROOT);
}

TEST(OneArgumentZero, Zero_a3) {
  double args[3] = {0, 13, -1};
  struct EquationAnswer answer;
  answer.x1.re = 0.0769230;
  answer.x1.im = 0.0;
  answer.x2.re = 0.0769230;
  answer.x2.im = 0.0;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, ONE_REAL_ROOT);
}

TEST(OneArgumentZero, Zero_a4) {
  double args[3] = {0, -1, -11};
  struct EquationAnswer answer;
  answer.x1.re = -11.0;
  answer.x1.im = 0.0;
  answer.x2.re = -11.0;
  answer.x2.im = 0.0;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, ONE_REAL_ROOT);
}

TEST(OneArgumentZero, Zero_b1) {
  double args[3] = {3, 0, 4};
  struct EquationAnswer answer;
  answer.x1.re = 0.0;
  answer.x1.im = -1.1547005;
  answer.x2.re = 0.0;
  answer.x2.im = 1.1547005;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, COMPLEX_ROOTS);
}

TEST(OneArgumentZero, Zero_b2) {
  double args[3] = {-6, 0, 4};
  struct EquationAnswer answer;
  answer.x1.re = -0.8164965;
  answer.x1.im = 0.0;
  answer.x2.re = 0.8164965;
  answer.x2.im = 0.0;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, REAL_ROOTS);
}

TEST(OneArgumentZero, Zero_b3) {
  double args[3] = {1, 0, -8};
  struct EquationAnswer answer;
  answer.x1.re = -2.8284271;
  answer.x1.im = 0.0;
  answer.x2.re = 2.8284271;
  answer.x2.im = 0.0;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, REAL_ROOTS);
}

TEST(OneArgumentZero, Zero_b4) {
  double args[3] = {-21, 0, -2};
  struct EquationAnswer answer;
  answer.x1.re = 0.0;
  answer.x1.im = -0.3086066;
  answer.x2.re = 0.0;
  answer.x2.im = 0.3086066;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, COMPLEX_ROOTS);
}

TEST(OneArgumentZero, Zero_c1) {
  double args[3] = {3, 4, 0};
  struct EquationAnswer answer;
  answer.x1.re = -1.3333333;
  answer.x1.im = 0.0;
  answer.x2.re = 0.0;
  answer.x2.im = 0.0;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, REAL_ROOTS);
}

TEST(OneArgumentZero, Zero_c2) {
  double args[3] = {-9, 42, 0};
  struct EquationAnswer answer;
  answer.x1.re = 0.0;
  answer.x1.im = 0.0;
  answer.x2.re = 4.6666666;
  answer.x2.im = 0.0;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, REAL_ROOTS);
}

TEST(OneArgumentZero, Zero_c3) {
  double args[3] = {10, -11, 0};
  struct EquationAnswer answer;
  answer.x1.re = 0.0;
  answer.x1.im = 0.0;
  answer.x2.re = 1.1;
  answer.x2.im = 0.0;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, REAL_ROOTS);
}

TEST(OneArgumentZero, Zero_c4) {
  double args[3] = {-7, -4, 0};
  struct EquationAnswer answer;
  answer.x1.re = -0.5714285;
  answer.x1.im = 0.0;
  answer.x2.re = 0.0;
  answer.x2.im = 0.0;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, REAL_ROOTS);
}

TEST(TwoArgumentZero, Zero_a_b) {
  double args[3] = {0, 0, 4};
  struct EquationAnswer answer;
  answer.x1.re = 0.0;
  answer.x1.im = 0.0;
  answer.x2.re = 0.0;
  answer.x2.im = 0.0;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, NO_ROOTS);
}

TEST(TwoArgumentZero, Zero_a_c) {
  double args[3] = {0, 4, 0};
  struct EquationAnswer answer;
  answer.x1.re = 0.0;
  answer.x1.im = 0.0;
  answer.x2.re = 0.0;
  answer.x2.im = 0.0;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, ONE_REAL_ROOT);
}

TEST(TwoArgumentZero, Zero_b_c) {
  double args[3] = {4, 0, 0};
  struct EquationAnswer answer;
  answer.x1.re = 0.0;
  answer.x1.im = 0.0;
  answer.x2.re = 0.0;
  answer.x2.im = 0.0;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, ONE_REAL_ROOT);
}

TEST(ThreeArgumentZero, Zero_a_b_c) {
  double args[3] = {0, 0, 0};
  struct EquationAnswer answer;
  answer.x1.re = 0.0;
  answer.x1.im = 0.0;
  answer.x2.re = 0.0;
  answer.x2.im = 0.0;

  struct EquationAnswer result;
  result = solve_equation(args[0], args[1], args[2]);

  EXPECT_NEAR(result.x1.re, answer.x1.re, EPSILON);
  EXPECT_NEAR(result.x1.im, answer.x1.im, EPSILON);
  EXPECT_NEAR(result.x2.re, answer.x2.re, EPSILON);
  EXPECT_NEAR(result.x2.im, answer.x2.im, EPSILON);
  EXPECT_EQ(result.possible_answer, ALWAYS_TRUE);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
