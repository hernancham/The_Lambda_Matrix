#include "Matrix.hpp"
#include "Rational.hpp"

// CONSTRUCTORES

template <class T>
void Matrix<T>::allocation_space()
{
    matrix = new T *[f];
    for (int i = 0; i < f; i++)
        matrix[i] = new T[c]();
}

template <class T>
Matrix<T>::Matrix() : f(0), c(0)
{
    matrix = nullptr;
}

template <class T>
Matrix<T>::Matrix(int nfc) : f(nfc), c(nfc)
{
    if (nfc > 0)
        allocation_space();
    else
        matrix = nullptr;
}

template <class T>
Matrix<T>::Matrix(int nf, int nc) : f(nf), c(nc)
{
    if (nf > 0 && nc > 0)
        allocation_space();
    else
        matrix = nullptr;
}

template <class T>
Matrix<T>::Matrix(T **mat, int nf, int nc) : f(nf), c(nc)
{
    if (nf > 0 && nc > 0)
    {
        allocation_space();
        for (int n = 0; n < f; n++)
            for (int m = 0; m < c; m++)
                matrix[n][m] = mat[n][m];
    }
    else
        matrix = nullptr;
}

template <class T>
Matrix<T>::Matrix(const Matrix &mat) : f(mat.f), c(mat.c)
{
    if (mat.f > 0 && mat.c > 0)
    {
        allocation_space();
        for (int n = 0; n < f; n++)
            for (int m = 0; m < c; m++)
                matrix[n][m] = mat.matrix[n][m];
    }
    else
        matrix = nullptr;
}

template <class T>
Matrix<T>::Matrix(const initializer_list<initializer_list<T>> &list) : f(0), c(0)
{
    for (const auto &row : list)
    {
        if (c == 0)
        {
            c = row.size();
            matrix = new T *[f = list.size()];
            for (int i = 0; i < f; i++)
            {
                matrix[i] = new T[c];
                fill_n(matrix[i], c, error);
            }
        }
        else if (row.size() != c)
        {
            throw invalid_argument("Invalid matrix dimensions");
        }

        copy(row.begin(), row.end(), matrix[f]);
        f++;
    }
}

// DESTRUCTOR

template <class T>
Matrix<T>::~Matrix()
{
    if (matrix != nullptr)
    {
        for (int n = 0; n < f; n++)
            delete[] matrix[n];
        delete[] matrix;
        matrix = nullptr;
    }
}

// OPERADORES DE FLUJO

template <class U>
ostream &operator<<(ostream &os, const Matrix<U> &mat)
{
    for (int n = 0; n < mat.f; n++)
    {
        os << "\263 ";
        for (int m = 0; m < mat.c; m++)
            os << setw(ESP_IMPR) << mat.matrix[n][m] << " ";
        os << " \263" << endl;
    }
    return os;
}

template <class U>
istream &operator>>(istream &is, Matrix<U> &mat)
{
    for (int n = 0; n < mat.f; n++)
        for (int m = 0; m < mat.c; m++)
            is >> mat.matrix[n][m];
    return is;
}

// OPERADORES DE ACCESO

template <class T>
T &Matrix<T>::operator()(int n) const
{
    if (n >= 0 && n < f * c)
        return matrix[n / c][n % c];
    else
        throw out_of_range("Index out of range");
}

template <class T>
T &Matrix<T>::operator()(int n, int m) const
{
    if (n >= 0 && n < f && m >= 0 && m < c)
        return matrix[n][m];
    else
        throw out_of_range("Index out of range");
}

// OPERADORES DE CONTROL

template <class T>
int Matrix<T>::get_f() const
{
    return f;
}

template <class T>
int Matrix<T>::get_c() const
{
    return c;
}

template <class T>
Matrix<T> Matrix<T>::get_col(const int c)
{
    Matrix<T> col(f, 1);

    for (int i = 0; i < f; i++)
        col.matrix[i][0] = matrix[i][c - 1];

    return col;
}

template <class T>
Matrix<T> Matrix<T>::get_fil(const int f)
{
    Matrix<T> fil(1, c);

    for (int i = 0; i < c; i++)
        fil.matrix[0][i] = matrix[f - 1][i];

    return fil;
}

template <class T>
Matrix<T> Matrix<T>::get_submatrix(int f1, int c1, int f2, int c2)
{
    Matrix<T> submatrix(f2 - f1 + 1, c2 - c1 + 1);

    for (int i = f1; i <= f2; i++)
        for (int j = c1; j <= c2; j++)
            submatrix.matrix[i - f1][j - c1] = matrix[i - 1][j - 1];

    return submatrix;
}

// OPERAcIONES CON MATRICES

template <class T>
int Matrix<T>::cofactor_pos(int x, int y)
{
    return ((x + y) % 2 == 0) ? 1 : -1;
}

template <class T>
T Matrix<T>::complementary_minor(int x, int y)
{
    T det = 0;
    if (is_square() and f > 1)
    {
        int order = f - 1;
        Matrix<T> subm(order);
        int n = 0;
        int m = 0;
        for (int i = 0; i < f; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (i != x && j != y)
                {
                    subm.matrix[n][m] = matrix[i][j];
                    m++;
                    if (m >= order)
                    {
                        n++;
                        m = 0;
                    }
                }
            }
        }
        det = subm.determinant();
    }
    return det;
}

// DETERMINANTE

template <class T>
T Matrix<T>::determinant()
{
    T det = 0;
    if (is_square())
    {
        if (f == 1)
            det = matrix[0][0];
        else
        {
            int order = f - 1;
            Matrix<T> subm(order);
            for (int k = 0; k < f; k++)
            {
                int x = 0;
                int y = 0;
                for (int i = 0; i < f; i++)
                {
                    for (int j = 0; j < c; j++)
                    {
                        if (i != 0 && j != k)
                        {
                            subm.matrix[x][y] = matrix[i][j];
                            y++;
                            if (y >= order)
                            {
                                x++;
                                y = 0;
                            }
                        }
                    }
                }
                det += matrix[0][k] * cofactor_pos(0, k) * subm.determinant();
            }
        }
    }
    return det;
}

template <class T>
Matrix<T> Matrix<T>::transposed()
{
    Matrix<T> trans(c, f);
    for (int i = 0; i < f; ++i)
        for (int j = 0; j < c; ++j)
            trans.matrix[j][i] = matrix[i][j];
    return trans;
}

template <class T>
Matrix<T> Matrix<T>::cofactor()
{
    Matrix<T> cof(1);
    if (is_square() and f > 1)
    {
        Matrix aux(f);
        for (int i = 0; i < f; ++i)
            for (int j = 0; j < c; ++j)
                aux.matrix[j][i] = complementary_minor(i, j) * cofactor_pos(i, j);
        return aux;
    }
    return cof;
}

template <class T>
Matrix<T> Matrix<T>::adjoint()
{
    Matrix<T> att(1);
    if (is_square() and f > 1)
    {
        Matrix<T> aux(f);
        for (int i = 0; i < f; ++i)
            for (int j = 0; j < c; ++j)
                aux.matrix[i][j] = complementary_minor(i, j) * cofactor_pos(i, j);
        return aux;
    }
    return att;
}

template <class T>
Matrix<T> Matrix<T>::inverse()
{
    Matrix<T> inv(1);
    if (is_square() and f > 1)
    {
        return adjoint() / determinant();
    }
    return inv;
}

template <class T>
int Matrix<T>::rank()
{
    int r = 0;
    if (f > 0)
    {
        Matrix<T> aux(f, c);
        aux = *this;
        for (int i = 0; i < f; i++)
        {
            if (aux.matrix[i][i] != 0)
            {
                for (int j = i + 1; j < f; j++)
                {
                    T m = aux.matrix[j][i] / aux.matrix[i][i];
                    for (int k = 0; k < c; k++)
                    {
                        aux.matrix[j][k] = aux.matrix[j][k] - m * aux.matrix[i][k];
                    }
                }
            }
        }
        for (int i = 0; i < f; i++)
        {
            int j = 0;
            while (j < c && aux.matrix[i][j] == 0)
            {
                j++;
            }
            if (j < c)
            {
                r++;
            }
        }
    }
    return r;
}

// OPERADORES DE CONFIRMACION

template <class T>
bool Matrix<T>::is_square()
{
    return f == c;
}

template <class T>
bool Matrix<T>::is_identity()
{
    if (is_square())
    {
        for (int n = 0; n < f; n++)
            for (int m = 0; m < c; m++)
                if (n == m and matrix[n][m] != 1)
                    return false;
                else if (n != m and matrix[n][m] != 0)
                    return false;
        return true;
    }
    return false;
}

template <class T>
bool Matrix<T>::is_symmetric()
{
    if (is_square())
    {
        for (int n = 0; n < f; n++)
            for (int m = 0; m < c; m++)
                if (matrix[n][m] != matrix[m][n])
                    return false;
        return true;
    }
    return false;
}

template <class T>
bool Matrix<T>::is_antisymmetric()
{
    if (is_square())
    {
        for (int n = 0; n < f; n++)
            for (int m = 0; m < c; m++)
                if (n == m and matrix[n][m] != 0)
                    return false;
                else if (matrix[n][m] != matrix[m][n])
                    return false;
        return true;
    }
    return false;
}

template <class T>
bool Matrix<T>::is_diagonal()
{
    if (is_square())
    {
        for (int n = 0; n < f; n++)
            for (int m = 0; m < c; m++)
                if (n != m and matrix[n][m] != 0)
                    return false;
        return true;
    }
    return false;
}

template <class T>
bool Matrix<T>::is_null()
{
    for (int n = 0; n < f; n++)
        for (int m = 0; m < c; m++)
            if (matrix[n][m] != 0)
                return false;
    return true;
}

template <class T>
bool Matrix<T>::is_invertible()
{
    if (is_square())
    {
        Matrix<T> aux(*this);
        return aux.determinant() != 0;
    }
    return false;
}

template <class T>
bool Matrix<T>::is_empty()
{
    return f == 0 and c == 0;
}

template <class T>
bool Matrix<T>::is_vector()
{
    return f == 1 or c == 1;
}

template <class T>
bool Matrix<T>::is_singular()
{
    return !is_invertible();
}

template <class T>
bool Matrix<T>::is_positive_definite()
{
    if (is_square())
    {
        Matrix<T> aux(*this);
        return aux.is_symmetric() and aux.is_invertible() and aux.determinant() > 0;
    }
    return false;
}

template <class T>
bool Matrix<T>::is_positive_semidefinite()
{
    if (is_square())
    {
        Matrix<T> aux(*this);
        return aux.is_symmetric() and aux.is_invertible() and aux.determinant() >= 0;
    }
    return false;
}

template <class T>
bool Matrix<T>::is_negative_definite()
{
    if (is_square())
    {
        Matrix<T> aux(*this);
        return aux.is_symmetric() and aux.is_invertible() and aux.determinant() < 0;
    }
    return false;
}

template <class T>
bool Matrix<T>::is_negative_semidefinite()
{
    if (is_square())
    {
        Matrix<T> aux(*this);
        return aux.is_symmetric() and aux.is_invertible() and aux.determinant() <= 0;
    }
    return false;
}

template <class T>
bool Matrix<T>::is_positive()
{
    return determinant() > 0;
}

template <class T>
bool Matrix<T>::is_negative()
{
    return determinant() < 0;
}

template <class T>
bool Matrix<T>::is_zero()
{
    return determinant() == 0;
}

template <class T>
bool Matrix<T>::is_upper_triangular()
{
    if (is_square())
    {
        for (int n = 0; n < f; n++)
            for (int m = 0; m < c; m++)
                if (n > m and matrix[n][m] != 0)
                    return false;
        return true;
    }
    return false;
}

template <class T>
bool Matrix<T>::is_lower_triangular()
{
    if (is_square())
    {
        for (int n = 0; n < f; n++)
            for (int m = 0; m < c; m++)
                if (n < m and matrix[n][m] != 0)
                    return false;
        return true;
    }
    return false;
}

template <class T>
bool Matrix<T>::is_triangular()
{
    return is_upper_triangular() or is_lower_triangular();
}

template <class T>
bool Matrix<T>::is_orthogonal()
{
    if (is_square())
    {
        Matrix<T> aux(*this);
        aux = aux * aux.transposed();
        return aux.is_identity();
    }
    return false;
}

template <class T>
bool Matrix<T>::is_perpendicular()
{
    if (is_square())
    {
        Matrix<T> aux(*this);
        return aux * aux.transposed() == aux.transposed() * aux == aux.is_null();
    }
    return false;
}

template <class T>
bool Matrix<T>::is_banded()
{
    if (is_square())
    {
        for (int n = 0; n < f; n++)
            for (int m = 0; m < c; m++)
                if (abs(n - m) > 1 and matrix[n][m] != 0)
                    return false;
        return true;
    }
    return false;
}

// OPERADORES DE ASIGNACION

template <class T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &mat)
{
    if (this != &mat)
    {
        this->~Matrix();
        f = mat.f;
        c = mat.c;
        matrix = new T *[f];
        for (int i = 0; i < f; i++)
        {
            matrix[i] = new T[c];
        }
        for (int i = 0; i < f; i++)
        {
            for (int j = 0; j < c; j++)
            {
                matrix[i][j] = mat.matrix[i][j];
            }
        }
    }
    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::operator=(const initializer_list<initializer_list<T>> &lst)
{
    int af = lst.size();
    int ac = lst.begin()->size();

    this->~Matrix();

    matrix = new T *[af];
    for (int i = 0; i < af; i++)
    {
        matrix[i] = new T[ac];
    }
    c = ac;
    f = af;

    int n = 0;
    int m = 0;
    for (auto &i : lst)
    {
        for (auto &j : i)
        {
            matrix[n][m] = j;
            m++;
        }
        n++;
        m = 0;
    }
    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::operator=(const T &val)
{
    for (int n = 0; n < f; n++)
        for (int m = 0; m < c; m++)
            matrix[n][m] = val;
    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &mat)
{
    if (f == mat.f and c == mat.c)
    {
        for (int n = 0; n < f; n++)
            for (int m = 0; m < c; m++)
                matrix[n][m] += mat.matrix[n][m];
    }
    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &mat)
{
    if (f == mat.f and c == mat.c)
    {
        for (int n = 0; n < f; n++)
            for (int m = 0; m < c; m++)
                matrix[n][m] -= mat.matrix[n][m];
    }
    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &mat)
{
    if (c == mat.f)
    {
        Matrix<T> aux(f, mat.c);
        for (int i = 0; i < f; i++)
            for (int j = 0; j < mat.c; j++)
                for (int k = 0; k < c; k++)
                    aux.matrix[i][j] += matrix[i][k] * mat.matrix[k][j];
        *this = aux;
    }
    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::operator*=(const T &val)
{
    for (int n = 0; n < f; n++)
        for (int m = 0; m < c; m++)
            matrix[n][m] *= val;
    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::operator/=(const T &val)
{
    for (int n = 0; n < f; n++)
        for (int m = 0; m < c; m++)
            matrix[n][m] /= val;
    return *this;
}

// OPERADORES ARITMETICOS

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &mat) const
{
    Matrix<T> aux(*this);
    aux += mat;
    return aux;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &mat) const
{
    Matrix<T> aux(*this);
    aux -= mat;
    return aux;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &mat) const
{
    Matrix<T> aux(*this);
    aux *= mat;
    return aux;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const T &val) const
{
    Matrix<T> aux(*this);
    aux *= val;
    return aux;
}

template <class T>
Matrix<T> Matrix<T>::operator/(const T &val) const
{
    Matrix<T> aux(*this);
    aux /= val;
    return aux;
}

// OPERADORES DE COMPARACION

template <class T>
bool Matrix<T>::operator==(const Matrix<T> &mat) const
{
    if (f == mat.f and c == mat.c)
    {
        for (int n = 0; n < f; n++)
            for (int m = 0; m < c; m++)
                if (matrix[n][m] != mat.matrix[n][m])
                    return false;
        return true;
    }
    return false;
}

template <class T>
bool Matrix<T>::operator!=(const Matrix<T> &mat) const
{
    return !(*this == mat);
}

template <class T>
template <class U>
bool Matrix<T>::operator==(const U &val) const
{
    for (int n = 0; n < f; n++)
        for (int m = 0; m < c; m++)
            if (matrix[n][m] != val)
                return false;
    return true;
}

template <class T>
template <class U>
bool Matrix<T>::operator!=(const U &val) const
{
    return !(*this == val);
}

template <class T>
template <class U>
bool Matrix<T>::operator<(const U &val) const
{
    for (int n = 0; n < f; n++)
        for (int m = 0; m < c; m++)
            if (matrix[n][m] >= val)
                return false;
    return true;
}

template <class T>
template <class U>
bool Matrix<T>::operator>(const U &val) const
{
    for (int n = 0; n < f; n++)
        for (int m = 0; m < c; m++)
            if (matrix[n][m] <= val)
                return false;
    return true;
}

template <class T>
template <class U>
bool Matrix<T>::operator<=(const U &val) const
{
    for (int n = 0; n < f; n++)
        for (int m = 0; m < c; m++)
            if (matrix[n][m] > val)
                return false;
    return true;
}

template <class T>
template <class U>
bool Matrix<T>::operator>=(const U &val) const
{
    for (int n = 0; n < f; n++)
        for (int m = 0; m < c; m++)
            if (matrix[n][m] < val)
                return false;
    return true;
}

template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;
template class Matrix<Rational>;

template ostream &operator<<(ostream &, const Matrix<int> &);
template ostream &operator<<(ostream &, const Matrix<double> &);
template ostream &operator<<(ostream &, const Matrix<Rational> &);

template istream &operator>>(istream &, Matrix<int> &);
template istream &operator>>(istream &, Matrix<double> &);
template istream &operator>>(istream &, Matrix<Rational> &);