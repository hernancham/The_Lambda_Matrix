#include <iostream>
#include "Rational.hpp"
#include "Matrix.hpp"

using namespace std;

int main()
{
    Matrix<int> m1(2, 2);

    m1 = {{2, },
          {4, 5}};

    cout << m1 << endl;

    return 0;
}
