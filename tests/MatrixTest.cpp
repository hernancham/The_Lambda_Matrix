/*
    En esta parte, se define una prueba llamada "Print" dentro del grupo de pruebas "ALibraryTests". 
    La función TEST es una macro de Google Test que define una nueva prueba. En este caso, la prueba 
    simplemente realiza una aserción utilizando la macro EXPECT_EQ. La aserción verifica que el valor 
    2 es igual a 2, lo cual siempre será verdadero, por lo que esta prueba siempre pasa.            
*/

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
