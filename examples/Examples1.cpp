#include <iostream>
#include "Rational.hpp"

using namespace std;

int main()
{
    Rational R1(3, 4);
    Rational R2(1, 2);
    // Matrix<int> M1{{1, 2}, {3, 4}};

    Rational R3 = R1 + R2;

    cout << R3 << endl;

    system("pause");

    return 0;
}
