#pragma once
#include <stdio.h>
#define TEST(num, a, b, c, X1_, X2_, x1_, x2_)    \
     decision(a, b, c, &x1_, &x2_);               \
     if ((X1_ == x1_) && (X2_ == x2_))            \
         printf("TEST "#num" is ok\n");           \
     else                                         \
         printf("TEST  is BAD: expected "#X1_" "#X2_" got %lg %lg\n", x1_, x2_);


void unittest()
{
    double x1_ = 0, x2_ = 0;

    //  num  a   b   c  x_1 x_2
    TEST(1,  1,  2, -3,  1, -3, x1_, x2_)
    TEST(2,  1,  2,  1, -1, -1, x1_, x2_)
    TEST(3,  1,  0, -4,  2, -2, x1_, x2_)
    TEST(4,  1,  0,  0,  0,  0, x1_, x2_)
    TEST(5,  0,  1, -5,  5,  5, x1_, x2_)
    TEST(6,  0,  0,  0,  INF, INF, x1_, x2_)
    TEST(7,  0,  0,  1,  NULL_, NULL_, x1_, x2_)
    TEST(8,  1,  2,  3,  NULL_, NULL_, x1_, x2_)
    TEST(9,  1,  0,  3,  NULL_, NULL_, x1_, x2_)
}
