#include <gtest/gtest.h>

#include "Rational.hpp"
#include "Matrix.hpp"

TEST(ALibraryTests, Print)
{
    Rational r1("5/7");
    Rational r2(2, 7);
    EXPECT_EQ(Rational(1, 1), r1 + r2);
}

TEST(ALibraryTests, Calculation)
{
    Rational r1("3/4");
    Rational r2(5, 4);
    EXPECT_EQ(Rational(2, 1), r1 + r2);
}