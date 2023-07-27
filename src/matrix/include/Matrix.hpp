#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <iostream>
#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>
#include <iomanip>

using namespace std;

const int ESP_IMPR = 10;

template <class T>
class Matrix
{
private:
	T **matrix;
	int f;
	int c;
	T error;
	void allocation_space();

public:
	// CONSTRUCTORES

	Matrix();
	Matrix(int);
	Matrix(int, int);
	Matrix(T **, int, int);
	Matrix(const Matrix<T> &);
	Matrix(const initializer_list<initializer_list<T>> &);

	// DESTRUCTOR

	~Matrix();

	// OPERADORES DE FLUJO

	template <class U>
	friend ostream &operator<<(ostream &, const Matrix<U> &);
	template <class U>
	friend istream &operator>>(istream &, Matrix<U> &);

	// OPERADORES DE ACCESO

	T &operator()(int) const;
	T &operator()(int, int) const;

	// OPERADORES DE CONTROL

	int get_f() const;
	int get_c() const;
	Matrix<T> get_col(const int);
	Matrix<T> get_fil(const int);
	Matrix<T> get_submatrix(int, int, int, int);

	// OPERAcIONES CON MATRICES

	int cofactor_pos(int, int);
	T complementary_minor(int, int);
	T determinant();
	Matrix<T> transposed();
	Matrix<T> cofactor();
	Matrix<T> adjoint();
	Matrix<T> inverse();
	int rank();

	// OPERADORES DE CONFIRMACION

	bool is_square();
	bool is_identity();
	bool is_empty();
	bool is_symmetric();
	bool is_antisymmetric();
	bool is_diagonal();
	bool is_null();
	bool is_invertible();
	bool is_vector();
	bool is_singular();
	bool is_positive_definite();
	bool is_positive_semidefinite();
	bool is_negative_definite();
	bool is_negative_semidefinite();
	bool is_positive();
	bool is_negative();
	bool is_zero();
	bool is_upper_triangular();
	bool is_lower_triangular();
	bool is_triangular();
	bool is_orthogonal();
	bool is_perpendicular();
	bool is_banded();

	// OPERADORES DE ASIGNACION

	Matrix<T> &operator=(const Matrix<T> &);
	Matrix<T> &operator=(const initializer_list<initializer_list<T>> &);
	Matrix<T> &operator=(const T &);
	Matrix<T> &operator+=(const Matrix<T> &);
	Matrix<T> &operator-=(const Matrix<T> &);
	Matrix<T> &operator*=(const Matrix<T> &);
	Matrix<T> &operator*=(const T &);
	Matrix<T> &operator/=(const T &);

	// OPERADORES ARITMETICOS

	Matrix<T> operator+(const Matrix<T> &) const;
	Matrix<T> operator-(const Matrix<T> &) const;
	Matrix<T> operator*(const Matrix<T> &) const;
	Matrix<T> operator*(const T &) const;
	Matrix<T> operator/(const T &) const;

	// OPERADORES DE COMPARACION

	bool operator==(const Matrix<T> &) const;
	bool operator!=(const Matrix<T> &) const;
	template <class U>
	bool operator==(const U &) const;
	template <class U>
	bool operator!=(const U &) const;
	template <class U>
	bool operator<(const U &) const;
	template <class U>
	bool operator>(const U &) const;
	template <class U>
	bool operator<=(const U &) const;
	template <class U>
	bool operator>=(const U &) const;
};

#endif /* _MATRIX_HPP_*/