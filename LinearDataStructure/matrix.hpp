#pragma once
#ifndef _MAXTIXH_
#define _MAXTIXH_
#include <iostream>
#include "myExpectation.h"
#include "arrayList.hpp"
#include <sstream>
#include <algorithm>
using namespace std;
template <class T>
class matrix
{
public:
    matrix(int theRows = 0, int theColumns = 0);
    matrix(const matrix<T> &);
    ~matrix()
    {
        if (this->element != nullptr)
        {
            // cout << "析构函数 this->element:" << this->element << endl;
            // cout<<*this->element<<endl;
            delete[] this->element;
            this->element = nullptr;
        }
    }
    int rows() const
    {
        return this->theRows;
    }
    int columns() const
    {
        return this->theColumns;
    }
    T &operator()(int i, int j) const;
    matrix<T> &operator=(const matrix<T> &);
    matrix<T> operator+(const matrix<T> &) const;
    matrix<T> operator-(const matrix<T> &) const;
    matrix<T> operator*(const matrix<T> &) const;
    matrix<T> &operator+=(const matrix<T> &);
    void output(ostream &cout) const;
    void tranpose();

private:
    int theRows;
    int theColumns;
    T *element;
};
template <class T>
matrix<T>::matrix(int theRows, int theColumns)
{
    if (theRows < 0 || theColumns < 0)
    {
        throw illegalParameterValue("Rows and columns must be >=0");
    }
    if ((theRows == 0 || theColumns == 0) && (theRows != 0 || theColumns != 0))
    {
        throw illegalParameterValue("Either both or neither rows and columns should be zero.");
    }
    this->theColumns = theColumns;
    this->theRows = theRows;
    this->element = new T[theColumns * theRows];
}
template <class T>
matrix<T>::matrix(const matrix<T> &m)
{
    this->theColumns = m.theColumns;
    this->theRows = m.theRows;
    if (m.element == nullptr)
    {
        this->element = nullptr;
    }
    this->element = new T[theColumns * theRows];
    copy(m.element, m.element + theColumns * theRows, this->element);
}
template <class T>
matrix<T> &matrix<T>::operator=(const matrix<T> &m)
{
    if (this != &m)
    {
        this->theRows = m.theRows;
        this->theColumns = m.theColumns;
        if (this->element != nullptr)
        {
            delete[] this->element;
        }
        this->element = new T[this->theColumns * this->theRows];
        copy(m.element, m.element + theColumns * theRows, this->element);
    }
}
template <class T>
T &matrix<T>::operator()(int i, int j) const
{
    if (i < 1 || i > this->theRows || j < 1 || j > this->theColumns)
    {
        throw illegalParameterValue("Index out of bonuds.");
    }
    return this->element[(i - 1) * this->theColumns + j - 1];
}
template <class T>
matrix<T> matrix<T>::operator+(const matrix<T> &m) const
{
    if (this->theRows != m.theRows || this->theColumns != m.theColumns)
    {
        throw illegalParameterValue("Matirx szie is not matched!");
    }
    matrix<T> resMatrix(this->theRows, this->theColumns);
    for (int i = 0; i < this->theColumns * this->theRows; i++)
    {
        resMatrix.element[i] = this->element[i] + m.element[i];
    }
    return resMatrix;
}
template <class T>
matrix<T> matrix<T>::operator-(const matrix<T> &m) const
{
    if (this->theRows != m.theRows || this->theColumns != m.theColumns)
    {
        throw illegalParameterValue("Matirx szie is not matched!");
    }
    matrix<T> resMatrix(this->theRows, this->theColumns);
    for (int i = 0; i < this->theColumns * this->theRows; i++)
    {
        resMatrix.element[i] = this->element[i] - m.element[i];
    }
    return resMatrix;
}
template <class T>
matrix<T> matrix<T>::operator*(const matrix<T> &m) const
{
    if (this->theColumns != m.theRows)
    {
        throw illegalParameterValue("Matrix size Mismatch!");
    }
    matrix<T> resMatirx(this->theRows, m.theColumns);
    int ct = 0, cm = 0, cr = 0;
    for (int i = 1; i <= this->theRows; i++)
    {
        for (int j = 1; j <= m.theColumns; j++)
        {
            resMatirx(i, j) = 0;
            for (int k = 1; k <= this->theColumns; k++)
            {
                resMatirx(i, j) += this->element[(i - 1) * this->theColumns + k - 1] * m.element[(k - 1) * m.theColumns + j - 1];
            }
        }
    }
    return resMatirx;
}
template <class T>
void matrix<T>::output(ostream &cout) const
{
    for (int i = 1; i <= this->theRows; i++)
    {
        for (int j = 1; j <= this->theColumns; j++)
        {
            cout << this->element[(i - 1) * this->theColumns + j - 1] << " ";
        }
        cout << endl;
    }
}
template <class T>
void matrix<T>::tranpose()
{
    T *newElement = new T[this->theRows * this->theColumns];
    // cout << "newElement:" << newElement << endl;
    // cout << "this->element:" << this->element << endl;
    for (int i = 1; i <= this->theColumns; i++)
    {
        for (int j = 1; j <= this->theRows; j++)
        {
            newElement[(i - 1) * this->theRows + j - 1] = this->element[(j - 1) * this->theColumns + i - 1];
        }
    }
    int temp = this->theRows;
    this->theRows = this->theColumns;
    this->theColumns = temp;
    delete[] this->element;
    this->element = newElement;
    // cout << "newElement:" << newElement << endl;
    // cout << "this->element:" << this->element << endl;
}
template <class T>
ostream &operator<<(ostream &cout, const matrix<T> &RightMatirx)
{
    RightMatirx.output(cout);
    return cout;
}
template <class T>
class diagnoalMatrix
{
public:
    diagnoalMatrix(int theN = 0);
    ~diagnoalMatrix()
    {
        if (this->element != nullptr)
        {
            delete[] this->element;
            this->element = nullptr;
        }
    }
    int degree()
    {
        return this->m_n;
    }
    T get(int, int) const;
    void set(int, int, const T &);
    void output(ostream &cout) const;

private:
    int m_n;
    T *element;
};
template <class T>
diagnoalMatrix<T>::diagnoalMatrix(int theN)
{
    if (theN < 1)
        throw illegalParameterValue("Matrix size must be > 0!");
    this->m_n = theN;
    element = new T[theN];
}
template <class T>
T diagnoalMatrix<T>::get(int i, int j) const
{
    if (i < 1 || i > this->m_n || j < 1 || j > this->m_n)
    {
        throw illegalParameterValue("Index out of bonuds.");
    }
    if (i == j)
        return this->element[i - 1];
    else
        return 0;
}
template <class T>
void diagnoalMatrix<T>::set(int i, int j, const T &newValue)
{
    if (i < 1 || i > this->m_n || j < 1 || j > this->m_n)
    {
        throw illegalParameterValue("Index out of bonuds.");
    }
    if (i == j)
    {
        this->element[i - 1] = newValue;
    }
    else
    {
        throw illegalParameterValue("Nondiagonal elements must be zero!");
    }
}
template <class T>
void diagnoalMatrix<T>::output(ostream &cout) const
{
    for (int i = 0; i < this->m_n; i++)
    {
        for (int j = 0; j < this->m_n; j++)
        {
            if (i == j)
                cout << this->element[i] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}
template <class T>
ostream &operator<<(ostream &cout, const diagnoalMatrix<T> &M)
{
    M.output(cout);
    return cout;
}
template <class T>
class matrixTerm
{
public:
    int row, column;
    T value;
};
template <class T>
ostream &operator<<(ostream &cout, const matrixTerm<T> &M)
{
    cout << "column = " << M.column << " row = " << M.row << " value = " << M.value;
    return cout;
}
template <class T>
class spareMatrix
{
public:
    void transpose(spareMatrix<T> &b);
    void add(spareMatrix<T> &b, spareMatrix<T> &c);
    void output(ostream &cout) const;
    void input(int rows, int colums, const arrayList<matrixTerm<T>> &);

private:
    int rows, columns;
    arrayList<matrixTerm<T>> terms;
};
template <class T>
void spareMatrix<T>::output(ostream &cout) const
{
    cout << "rows = " << this->rows << " columns = " << this->columns << endl;
    cout << "Nonzero term = " << this->terms.size() << endl;
    for (typename arrayList<matrixTerm<T>>::iterator it = this->terms.begin(); it != this->terms.end(); it++)
    {
        cout << "Array(" << ((*it).row) << "," << ((*it).column) << ") = " << ((*it).value) << endl;
    }
}
template <class T>
ostream &operator<<(ostream &cout, const spareMatrix<T> &M)
{
    M.output(cout);
    return cout;
}
template <class T>
void spareMatrix<T>::input(int rows, int columns, const arrayList<matrixTerm<T>> &List)
{
    this->terms = List;
    this->rows = rows;
    this->columns = columns;
}
template <class T>
void spareMatrix<T>::transpose(spareMatrix<T> &b)
{
    b.columns = this->rows;
    b.rows = this->columns;
    int *colSize = new int[this->columns + 1];
    int *rowNext = new int[this->rows + 1];
    b.terms.reset(this->terms.size());
    for (int i = 1; i <= this->columns; i++)
    {
        colSize[i] = 0;
    }
    for (typename arrayList<matrixTerm<T>>::iterator it = this->terms.begin(); it != this->terms.end(); it++)
    {
        colSize[(*it).column]++;
    }
    rowNext[1] = 0;
    for (int i = 2; i <= this->columns; i++)
    {
        rowNext[i] = rowNext[i - 1] + colSize[i - 1];
    }
    matrixTerm<T> mTerm;
    for (typename arrayList<matrixTerm<T>>::iterator it = this->terms.begin(); it != this->terms.end(); it++)
    {
        int j = rowNext[(*it).column]++;
        mTerm.row = (*it).column;
        mTerm.column = (*it).row;
        mTerm.value = (*it).value;
        b.terms.set(j - 1, mTerm);
    }
}
#endif
