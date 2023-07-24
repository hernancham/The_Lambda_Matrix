
#include "Rational.hpp"

// CONSRUCTORES

Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int num)
{
    numerator = num;
    denominator = 1;
}

Rational::Rational(double num)
{
    numerator = num * 10000;
    denominator = 10000;
    this->simplify();
}

Rational::Rational(string num)
{
    regex pattern(R"(^([+-]?\d+)([/.])?(\d*)$)");
    smatch matches;

    if (regex_match(num, matches, pattern))
    {
        numerator = stoi(matches[1].str());
        if (matches[2].str() == "/")
            denominator = stoi(matches[3].str());
        else
            denominator = 1;
    }
    else
    {
        numerator = 0;
        denominator = 1;
    }
    this->simplify();
}

Rational::Rational(const Rational &rat)
{
    numerator = rat.numerator;
    denominator = rat.denominator;
}

Rational::Rational(int num, int den)
{
    numerator = num;
    denominator = den;
    this->simplify();
}

// DESTRUCTOR

Rational::~Rational()
{
    numerator = 0;
    denominator = 1;
}

// OPERADORES DE FLUJO

ostream &operator<<(ostream &os, const Rational &rat)
{
    if (rat.get_denominator() == 1)
        os << rat.get_numerator();
    else if (rat.get_denominator() == 0)
        os << "Error";
    else
        os << string(rat);
    return os;
}

istream &operator>>(istream &is, Rational &rat)
{
    string imput;
    is >> imput;
    regex pattern(R"(^([+-]?\d+)([/.])?(\d*)$)");
    smatch matches;

    if (regex_match(imput, matches, pattern))
    {
        rat.set_numerator(stoi(matches[1].str()));
        if (matches[2].str() == "/")
            rat.set_denominator(stoi(matches[3].str()));
        else
            rat.set_denominator(1);
    }
    else
    {
        rat.set_numerator(0);
        rat.set_denominator(0);
    }
    rat.simplify();
    return is;
}

// OPERADORES DE ACCESO

int Rational::get_numerator() const
{
    return numerator;
}

int Rational::get_denominator() const
{
    return denominator;
}

void Rational::set_numerator(int num)
{
    numerator = num;
}

void Rational::set_denominator(int den)
{
    denominator = den;
}

// METODOS

Rational abs(const Rational &rat)
{
    return Rational(abs(rat.numerator), abs(rat.denominator));
}

Rational pow(const Rational &rat, int exp)
{
    return Rational(pow(rat.numerator, exp), pow(rat.denominator, exp));
}

Rational Rational::reciprocal() const
{
    Rational rat(*this);
    if (numerator != 0)
    {
        rat.set_numerator(denominator);
        rat.set_denominator(numerator);
    }

    return rat;
}

void Rational::simplify()
{
    int a = numerator, b = denominator, r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    if (a < 0)
        a = -a;
    numerator /= a;
    denominator /= a;
    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// OPERADORES DE CONVERSION

Rational::operator int() const
{
    return numerator / denominator;
}

Rational::operator double() const
{
    return (double)numerator / (double)denominator;
}

Rational::operator string() const
{
    return to_string(numerator) + "/" + to_string(denominator);
}

Rational::operator bool() const
{
    return numerator != 0;
}

// OPERADORES DE ASIGNACION

Rational &Rational::operator=(const Rational &rat)
{
    numerator = rat.numerator;
    denominator = rat.denominator;
    return *this;
}

Rational &Rational::operator+=(const Rational &rat)
{
    numerator = numerator * rat.denominator + denominator * rat.numerator;
    denominator *= rat.denominator;
    this->simplify();
    return *this;
}

Rational &Rational::operator-=(const Rational &rat)
{
    numerator = numerator * rat.denominator - denominator * rat.numerator;
    denominator *= rat.denominator;
    this->simplify();
    return *this;
}

Rational &Rational::operator*=(const Rational &rat)
{
    numerator *= rat.numerator;
    denominator *= rat.denominator;
    this->simplify();
    return *this;
}

Rational &Rational::operator/=(const Rational &rat)
{
    numerator *= rat.denominator;
    denominator *= rat.numerator;
    this->simplify();
    return *this;
}

Rational &Rational::operator=(int num)
{
    *this = Rational(num);
    return *this;
}

Rational &Rational::operator+=(int num)
{
    *this += Rational(num);
    this->simplify();
    return *this;
}

Rational &Rational::operator-=(int num)
{
    *this -= Rational(num);
    this->simplify();
    return *this;
}

Rational &Rational::operator*=(int num)
{
    *this *= Rational(num);
    this->simplify();
    return *this;
}

Rational &Rational::operator/=(int num)
{
    *this /= Rational(num);
    this->simplify();
    return *this;
}

Rational &Rational::operator=(double num)
{
    *this += Rational(num);
    this->simplify();
    return *this;
}

Rational &Rational::operator+=(double num)
{
    *this += Rational(num);
    this->simplify();
    return *this;
}

Rational &Rational::operator-=(double num)
{
    *this -= Rational(num);
    this->simplify();
    return *this;
}

Rational &Rational::operator*=(double num)
{
    *this *= Rational(num);
    this->simplify();
    return *this;
}

Rational &Rational::operator/=(double num)
{
    *this /= Rational(num);
    this->simplify();
    return *this;
}

// OPERADORES ARITMETICOS

Rational Rational::operator+(const Rational &rat) const
{
    return Rational(*this) += rat;
}

Rational Rational::operator-(const Rational &rat) const
{
    return Rational(*this) -= rat;
}

Rational Rational::operator*(const Rational &rat) const
{
    return Rational(*this) *= rat;
}

Rational Rational::operator/(const Rational &rat) const
{
    return Rational(*this) /= rat;
}

Rational Rational::operator+(int num) const
{
    return Rational(*this) += num;
}

Rational Rational::operator-(int num) const
{
    return Rational(*this) -= num;
}

Rational Rational::operator*(int num) const
{
    return Rational(*this) *= num;
}

Rational Rational::operator/(int num) const
{
    return Rational(*this) /= num;
}

Rational Rational::operator+(double num) const
{
    return Rational(*this) += num;
}

Rational Rational::operator-(double num) const
{
    return Rational(*this) -= num;
}

Rational Rational::operator*(double num) const
{
    return Rational(*this) *= num;
}

Rational Rational::operator/(double num) const
{
    return Rational(*this) /= num;
}

// OPERADORES DE LOGICOS

bool Rational::operator==(const Rational &rat) const
{
    return numerator == rat.numerator && denominator == rat.denominator;
}

bool Rational::operator!=(const Rational &rat) const
{
    return !(*this == rat);
}

bool Rational::operator<(const Rational &rat) const
{
    return numerator * rat.denominator < denominator * rat.numerator;
}

bool Rational::operator>(const Rational &rat) const
{
    return numerator * rat.denominator > denominator * rat.numerator;
}

bool Rational::operator<=(const Rational &rat) const
{
    return numerator * rat.denominator <= denominator * rat.numerator;
}

bool Rational::operator>=(const Rational &rat) const
{
    return numerator * rat.denominator >= denominator * rat.numerator;
}

bool Rational::operator==(int num) const
{
    return *this == Rational(num);
}

bool Rational::operator!=(int num) const
{
    return *this != Rational(num);
}

bool Rational::operator<(int num) const
{
    return *this < Rational(num);
}

bool Rational::operator>(int num) const
{
    return *this > Rational(num);
}

bool Rational::operator<=(int num) const
{
    return *this <= Rational(num);
}

bool Rational::operator>=(int num) const
{
    return *this >= Rational(num);
}

bool Rational::operator==(double num) const
{
    return *this == Rational(num);
}

bool Rational::operator!=(double num) const
{
    return *this != Rational(num);
}

bool Rational::operator<(double num) const
{
    return *this < Rational(num);
}

bool Rational::operator>(double num) const
{
    return *this > Rational(num);
}

bool Rational::operator<=(double num) const
{
    return *this <= Rational(num);
}

bool Rational::operator>=(double num) const
{
    return *this >= Rational(num);
}

//______________________________________________________________

// OPERADORES ARITMETICOS (COMUNTATIVIDAD)

Rational operator+(int num, const Rational &rat)
{
    return Rational(num) + rat;
}

Rational operator-(int num, const Rational &rat)
{
    return Rational(num) - rat;
}

Rational operator*(int num, const Rational &rat)
{
    return Rational(num) * rat;
}

Rational operator/(int num, const Rational &rat)
{
    return Rational(num) / rat;
}

Rational operator+(double num, const Rational &rat)
{
    return Rational(num) + rat;
}

Rational operator-(double num, const Rational &rat)
{
    return Rational(num) - rat;
}

Rational operator*(double num, const Rational &rat)
{
    return Rational(num) * rat;
}

Rational operator/(double num, const Rational &rat)
{
    return Rational(num) / rat;
}

// OPERADORES LOGICOS (COMUNTATIVIDAD)

bool operator==(int num, const Rational &rat)
{
    return Rational(num) == rat;
}

bool operator!=(int num, const Rational &rat)
{
    return Rational(num) != rat;
}

bool operator<(int num, const Rational &rat)
{
    return Rational(num) < rat;
}

bool operator>(int num, const Rational &rat)
{
    return Rational(num) > rat;
}

bool operator<=(int num, const Rational &rat)
{
    return Rational(num) <= rat;
}

bool operator>=(int num, const Rational &rat)
{
    return Rational(num) >= rat;
}

bool operator==(double num, const Rational &rat)
{
    return Rational(num) == rat;
}

bool operator!=(double num, const Rational &rat)
{
    return Rational(num) != rat;
}

bool operator<(double num, const Rational &rat)
{
    return Rational(num) < rat;
}

bool operator>(double num, const Rational &rat)
{
    return Rational(num) > rat;
}

bool operator<=(double num, const Rational &rat)
{
    return Rational(num) <= rat;
}

bool operator>=(double num, const Rational &rat)
{
    return Rational(num) >= rat;
}
