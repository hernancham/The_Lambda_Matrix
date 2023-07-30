#include <iostream>
#include "Rational.hpp"

using namespace std;

int main()
{
    Rational R1(5, 6);
    Rational R2(2, 3);

    Rational R3 = R1 + R2;

    cout << R3 << endl;

    system("pause");

    return 0;
}
