#ifndef _RATIONAL_HPP_
#define _RATIONAL_HPP_

#include <iostream>
#include <string>
#include <regex>
#include <cmath>

using namespace std;

const int RAT_ROUND = 8;

class Rational
{
private:
    int numerator;
    int denominator;

public:
    // CONSTRUCTORES
    Rational();
    Rational(int);
    Rational(double);
    Rational(string);
    Rational(const Rational &);
    Rational(int, int);
    // DESTRUCTOR
    ~Rational();
    // OPERADORES DE FLUJO
    friend ostream &operator<<(ostream &, const Rational &);
    friend istream &operator>>(istream &, Rational &);
    // OPERADORES DE ACCESO
    int get_numerator() const;
    int get_denominator() const;
    void set_numerator(int);
    void set_denominator(int);
    // METODOS
    friend Rational abs(const Rational &);
    friend Rational pow(const Rational &, int);
    Rational reciprocal() const;
    void simplify();
    // OPERADORES DE CONVERSION
    operator int() const;
    operator double() const;
    operator string() const;
    operator bool() const;
    // OERADORES DE ASIGNACION
    Rational &operator=(const Rational &);
    Rational &operator+=(const Rational &);
    Rational &operator-=(const Rational &);
    Rational &operator*=(const Rational &);
    Rational &operator/=(const Rational &);
    Rational &operator=(int);
    Rational &operator+=(int);
    Rational &operator-=(int);
    Rational &operator*=(int);
    Rational &operator/=(int);
    Rational &operator=(double);
    Rational &operator+=(double);
    Rational &operator-=(double);
    Rational &operator*=(double);
    Rational &operator/=(double);
    // OPERADORES ARITMETICOS
    Rational operator+(const Rational &) const;
    Rational operator-(const Rational &) const;
    Rational operator*(const Rational &) const;
    Rational operator/(const Rational &) const;
    Rational operator+(int) const;
    Rational operator-(int) const;
    Rational operator*(int) const;
    Rational operator/(int) const;
    Rational operator+(double) const;
    Rational operator-(double) const;
    Rational operator*(double) const;
    Rational operator/(double) const;
    // OPERADORES LOGICOS
    bool operator==(const Rational &) const;
    bool operator!=(const Rational &) const;
    bool operator<(const Rational &) const;
    bool operator>(const Rational &) const;
    bool operator<=(const Rational &) const;
    bool operator>=(const Rational &) const;
    bool operator==(int) const;
    bool operator!=(int) const;
    bool operator<(int) const;
    bool operator>(int) const;
    bool operator<=(int) const;
    bool operator>=(int) const;
    bool operator==(double) const;
    bool operator!=(double) const;
    bool operator<(double) const;
    bool operator>(double) const;
    bool operator<=(double) const;
    bool operator>=(double) const;
};

// OPERADORES ARITMETICOS (COMUNTATIVIDAD)
Rational operator+(int, const Rational &);
Rational operator-(int, const Rational &);
Rational operator*(int, const Rational &);
Rational operator/(int, const Rational &);
Rational operator+(double, const Rational &);
Rational operator-(double, const Rational &);
Rational operator*(double, const Rational &);
Rational operator/(double, const Rational &);
// OPERADORES LOGICOS (COMUNTATIVIDAD)
bool operator==(int, const Rational &);
bool operator!=(int, const Rational &);
bool operator<(int, const Rational &);
bool operator>(int, const Rational &);
bool operator<=(int, const Rational &);
bool operator>=(int, const Rational &);
bool operator==(double, const Rational &);
bool operator!=(double, const Rational &);
bool operator<(double, const Rational &);
bool operator>(double, const Rational &);
bool operator<=(double, const Rational &);
bool operator>=(double, const Rational &);

#endif /* _RATIONAL_HPP_ */
